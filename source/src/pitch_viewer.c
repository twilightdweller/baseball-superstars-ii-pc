#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "pitch_path.h"
#include "pitch_scene.h"
#include "camera.h"
#include "taken_pitch.h"
#include "batting.h"
#include "pitch_rules.h"
#include "batted_flight.h"
#include "ground_out.h"
#include "ball_motion.h"
#include <string.h>
#include <stdlib.h>
#include "pitch_records.h"
static BS2Point3 path[4099],controls[50];
static BS2Projection camera;
static int selected=0,preset=1,frames=0,ready=0;
static DWORD started;
static BS2AtBat at_bat;
static BS2StrikeZone zone;
enum PitchPhase { AIM, DELIVERY, JUDGMENT, COMPLETE, BATTED, CONTACT, FOUL, FIELDING, FIELD_COMPLETE };
static enum PitchPhase phase;
static int taking, aim, pitch_number, last_call;
static DWORD judge_started, swing_started, contact_started;
static unsigned variant_order[24];
static BS2Flight flight;
static BS2MovingBall moving_ball;
static unsigned motion_ticks;
static const unsigned char *flight_data;
static size_t flight_size, fly_size;
static const uint8_t *fly_data;
static BS2FlyOut field;
static BS2GroundPlay ground;
static BS2GroundDefense ground_defense;
static const uint8_t *ground_data;
static size_t ground_size;
static int is_ground;
static int have_field, advanced_lineup, first_preset;
static DWORD field_started;
static const char *const fielders[] = {"Pitcher", "Catcher", "First baseman", "Second baseman",
 "Third baseman", "Shortstop", "Outfielder", "Outfielder", "Outfielder"};
static int swing_frame = -1, swing_checked, contact_pattern;
static uint32_t swing_seed;
static int fixed_practice_seed;
static uint32_t practice_seed = 1u;
static BS2Point2 bat_offset;
static const char *call_name[] = {"Ready", "Called strike", "Ball", "Walk", "", "Called strikeout"};

static void reset_appearance(void) {
 at_bat = (BS2AtBat){0};
 have_field=0; advanced_lineup=0; first_preset=preset;
 at_bat.play[0x12d] = 9;
 swing_frame = -1; swing_checked = 0; swing_seed = fixed_practice_seed ? practice_seed : GetTickCount();
 aim = 0; pitch_number = 0; last_call = 0; phase = AIM;
}

/* Statistics recording is outside this single-appearance viewer. */
static void flow_effect(void *context, int effect) { (void)context; (void)effect; }
static HDC canvas;
static HBITMAP bitmap,previous_bitmap;
static HDC art_dc;
static HBITMAP fields[2],swings[2],ball_image;
enum { FIELD_RIGHT = 101, FIELD_LEFT, PITCH_BALL, SWING_RIGHT, SWING_LEFT };
static HFONT font,previous_font;
static int px(BS2Point2 p){return p.x/262144;}
static int py(BS2Point2 p){return p.y/262144;}
static void replay(void){
 const PitchRecord *r=&records[selected];BS2PitchSpec spec={0};
 spec.count=r->count;spec.frames=r->frames;spec.style=r->style;spec.coordinate_format=1;spec.kind=r->kind;
 spec.target=r->points[r->count-1];
 if(taking)spec.target.x+=aim*262144;
 ready=bs2_camera_from_figure(figure,sizeof(figure),preset,&camera)==0 &&
       bs2_pitch_release(figure,sizeof(figure),r->style,preset==0,&spec.release)==0 &&
       bs2_pitch_path(&spec,r->points,controls,path)==0;
 if(taking && ready)
  ready=bs2_strike_zone(figure,sizeof(figure),&camera,&zone)==0 &&
        bs2_batting_offset(figure,sizeof(figure),&camera,&spec.target,&bat_offset)==0;
 frames=r->frames+3;started=GetTickCount();
}
static void take_or_restart(void) {
 if(phase==FIELD_COMPLETE || (phase==COMPLETE && last_call==5)){
  if(at_bat.play[6]<3 && bs2_begin_next_batter(&at_bat)==0){
   advanced_lineup=1;
   preset=at_bat.batting_slot%2 ? 3-first_preset : first_preset;
   swing_frame=-1; swing_checked=0; have_field=0;
   aim=0; pitch_number=0; last_call=0; phase=AIM;
  }else{preset=first_preset;reset_appearance();}
  replay();return;
 }
 if(phase==COMPLETE || phase==CONTACT){reset_appearance();replay();return;}
 if((phase==AIM || phase==FOUL) && ready){
  at_bat.play[0x11]=at_bat.play[0x1c]=0;
  swing_frame=-1; swing_checked=0; started=GetTickCount(); ++pitch_number; phase=DELIVERY;
 }
}

static void swing(void) {
 if(phase!=DELIVERY || swing_frame>=0)return;
 DWORD now=GetTickCount();
 unsigned tick=(now-started)/20u;
 if(tick>(unsigned)records[selected].frames)return;
 swing_frame=(int)tick; swing_started=now;
}

static const char *first_base_runner(void) {
 if(!at_bat.first_base_slot || at_bat.play[6]==3)return NULL;
 int runner_preset=(at_bat.first_base_slot-1)%2 ? 3-first_preset : first_preset;
 return runner_preset==1?"Ara":"Medica";
}

static const char *pitch_result(void) {
 if(phase==BATTED)return "Ball in play";
 if(phase==FIELD_COMPLETE || (phase==FIELDING && (at_bat.play[0xb]==13 ||
    (is_ground && ground_defense.received_tick && at_bat.first_base_slot))))
  return !is_ground?"Fly out":at_bat.first_base_slot?"Safe at first":"Ground out";
 if(phase==FIELDING)return "Fielding";
 if(phase==CONTACT)return "Contact";
 if(phase==FOUL)return "Foul ball";
 if(phase==DELIVERY)return swing_frame>=0?"Swing":"In flight";
 if(swing_frame>=0 && last_call==1)return "Swinging strike";
 if(swing_frame>=0 && last_call==5)return "Swinging strikeout";
 return call_name[last_call];
}

static void update_appearance(void) {
 DWORD now=GetTickCount();
 int tick=(int)((now-started)/20u), judge=records[selected].frames-1;
 if(phase==DELIVERY && swing_frame>=0 && !swing_checked && tick>swing_frame){
  swing_checked=1;
  contact_pattern=bs2_swing_pattern(preset==1,judge,swing_frame,bat_offset,&swing_seed);
  if(contact_pattern==BS2_INVALID_SWING){ready=0;phase=AIM;return;}
  at_bat.play[0x11]=(uint8_t)(contact_pattern!=BS2_SWING_MISS);
  if(at_bat.play[0x11]){
   unsigned order=variant_order[contact_pattern];
   if(bs2_open_flight(flight_data,flight_size,contact_pattern,&variant_order[contact_pattern],&flight)){
    ready=0; phase=AIM; return;
   }
   is_ground=contact_pattern>=3 && contact_pattern<=5;
   if(at_bat.first_base_slot)have_field=0;
   else if(is_ground){
    have_field=bs2_find_ground_play(ground_data,ground_size,contact_pattern,order,preset==1,at_bat.play[6],&ground);
    ground_defense=(BS2GroundDefense){0};
    if(have_field==1)field=ground.field;
   }else have_field=bs2_find_fly_out(fly_data,fly_size,contact_pattern,order,preset==1,at_bat.play[6],&field);
   if(have_field<0){ready=0;phase=AIM;return;}
   if(bs2_start_ball(&moving_ball,&flight)){ready=0;phase=AIM;return;}
   bs2_move_ball(&moving_ball);motion_ticks=1;
   contact_started=now; phase=BATTED; return;
  }
 }
 if(phase==DELIVERY && tick>=judge+2){
  last_call=bs2_judge_unhit_curve(&at_bat,swing_frame>=0,path,(size_t)frames,&camera,&zone);
  if(last_call<1){last_call=0;ready=0;phase=AIM;return;}
  judge_started=now;phase=JUDGMENT;
 }
 if(phase==BATTED){
  unsigned elapsed_ticks=(now-contact_started)/20u+1;
  while(motion_ticks<elapsed_ticks && !moving_ball.stopped){
   bs2_move_ball(&moving_ball);
   ++motion_ticks;
  }
 }
 if(phase==BATTED && (now-contact_started)/20u>=flight.count){
  if(have_field){
   at_bat.play[0xb]=at_bat.play[0x1e]=at_bat.play[0x1f]=0;
   field_started=contact_started+flight.count*20u;phase=FIELDING;
  }
  else if(!at_bat.first_base_slot && flight.untouched_foul){
   at_bat.play[0x1c]=1;
   bs2_increment_strike_to_two(at_bat.play); /* EndOfDefense, 0x16cb58. */
   phase=FOUL;
  }else phase=CONTACT;
 }
 if(phase==FIELDING){
  unsigned field_tick=(now-field_started)/20u+1;
  int next=is_ground?bs2_step_ground_play(&at_bat,&ground_defense,&ground,ground_data,ground_size,field_tick)
                    :bs2_step_fly_out(&at_bat,&field,field_tick);
  if(next<0){ready=0;phase=AIM;}
  else if(next)phase=FIELD_COMPLETE;
 }
 if(phase==JUDGMENT){
  int state=bs2_taken_pitch_next_state(&at_bat,(now-judge_started)/20u,flow_effect,NULL);
  if(state<0){ready=0;phase=AIM;}
  else if(state>0)phase=at_bat.batter_reserved?COMPLETE:AIM;
 }
}

static void describe_contact(char *text, size_t size) {
 static const char *const name[]={"Fly out","Ground out",NULL,"Foul ball",NULL,"Single","Double","Home run"};
 static const char *const side[]={"",", left",", right"};
 snprintf(text,size,"%s pattern%s",name[contact_pattern/3],side[contact_pattern%3]);
}

static void update_title(HWND window) {
 char title[180], detail[64]="";
 if(!taking){SetWindowTextA(window,"BS2 Pitch Motion");return;}
 if(phase==CONTACT && at_bat.first_base_slot)snprintf(detail,sizeof(detail),"Occupied-base play unresolved");
 else if(phase==CONTACT)describe_contact(detail,sizeof(detail));
 if(phase==FIELD_COMPLETE)snprintf(detail,sizeof(detail),"%s | %s",is_ground?(at_bat.first_base_slot?"Reached first":"Out at first"):fielders[field.fielder],
  at_bat.play[6]==3?"Side retired":"Next batter ready");
 if(phase==COMPLETE && last_call==5 && at_bat.play[6]==3)
  snprintf(detail,sizeof(detail),"Side retired");
 if(phase==AIM && advanced_lineup && pitch_number==0)snprintf(detail,sizeof(detail),"Slot %u: %s",
  (unsigned)at_bat.batting_slot+1,preset==1?"Ara":"Medica");
 snprintf(title,sizeof(title),"BS2 At-Bat | Pitch %d | %s | Balls %u, Strikes %u, Outs %u%s%s%s",
          pitch_number,pitch_result(),
          (unsigned)at_bat.play[5],(unsigned)at_bat.play[4],(unsigned)at_bat.play[6],
          (phase==COMPLETE || phase==FIELD_COMPLETE)?" | Complete":(phase==AIM || phase==FOUL)?" | Ready":"",detail[0]?" | ":"",detail);
 const char *runner=first_base_runner();
 if(runner){
  size_t used=strlen(title);
  snprintf(title+used,sizeof(title)-used," | On first: %s",runner);
 }
 SetWindowTextA(window,title);
}
static void label(int x,int y,const char *s,COLORREF color){
 SetTextColor(canvas,color);
 TextOutA(canvas,x,y,s,(int)lstrlenA(s));
}
static void draw_defense_map(unsigned tick) {
 const uint8_t *commands;
 int count=bs2_fly_map_frame(is_ground?ground_data:fly_data,is_ground?ground_size:fly_size,&field,tick,&commands);
 RECT screen={0,0,480,320};
 FillRect(canvas,&screen,(HBRUSH)GetStockObject(BLACK_BRUSH));
 if(count<0)return;
 int saved=SaveDC(canvas);
 SetViewportOrgEx(canvas,120,106,NULL);
 SelectObject(canvas,GetStockObject(DC_PEN));
 for(int i=0;i<count;++i){
  BS2MapDraw op;
  memcpy(&op,commands+i*sizeof(op),sizeof(op));
  unsigned red=op.rgb565>>11,green=(op.rgb565>>5)&63,blue=op.rgb565&31;
  COLORREF color=RGB((red<<3)|(red>>2),(green<<2)|(green>>4),(blue<<3)|(blue>>2));
  SetDCPenColor(canvas,color);
  if(op.shape==0){
   MoveToEx(canvas,op.x,op.y,NULL);
   LineTo(canvas,op.width,op.height);
   SetPixelV(canvas,op.width,op.height,color);
  }else{
   SelectObject(canvas,GetStockObject(op.shape==1?DC_BRUSH:HOLLOW_BRUSH));
   SetDCBrushColor(canvas,color);
   if(op.shape==3)Rectangle(canvas,op.x,op.y,op.x+op.width,op.y+op.height);
   else Ellipse(canvas,op.x,op.y,op.x+op.width,op.y+op.height);
  }
 }
 RestoreDC(canvas,saved);
}

static void render(void){
 int swinging=taking && swing_frame>=0 && phase!=AIM;
 int source_y=0;
 if(swinging){
  int ace=preset==1;
  source_y=320*(bs2_swing_art_frame(ace,(GetTickCount()-swing_started)/20u)-bs2_swing_art_frame(ace,0));
 }
 HGDIOBJ old_art=SelectObject(art_dc,swinging?swings[preset-1]:fields[preset-1]);
 BitBlt(canvas,0,0,480,320,art_dc,0,source_y,SRCCOPY);
 SelectObject(art_dc,old_art);
 SetBkMode(canvas,OPAQUE);
 SetBkColor(canvas,RGB(18,25,33));
 if(ready && !taking){
  HPEN line=CreatePen(PS_SOLID,1,RGB(78,108,129));HGDIOBJ old=SelectObject(canvas,line);
  for(int i=0;i<frames;i++){
   BS2Point2 p;bs2_project_point(&p,&path[i],&camera);
   if(i==0)MoveToEx(canvas,px(p),py(p),NULL);else LineTo(canvas,px(p),py(p));
  }
  SelectObject(canvas,old);DeleteObject(line);
 }
 if(ready){
  if(taking){
   int left=min(zone.first.x,zone.second.x),right=max(zone.first.x,zone.second.x);
   int top=min(zone.first.y,zone.second.y),bottom=max(zone.first.y,zone.second.y);
   HGDIOBJ brush=SelectObject(canvas,GetStockObject(HOLLOW_BRUSH));
   HGDIOBJ pen=SelectObject(canvas,GetStockObject(DC_PEN));SetDCPenColor(canvas,RGB(149,180,168));
   Rectangle(canvas,left,top,right+1,bottom+1);SelectObject(canvas,pen);SelectObject(canvas,brush);
  }
  DWORD elapsed=(GetTickCount()-started)%(DWORD)(frames*20+1200);
  int frame=elapsed<300?0:(int)((elapsed-300)/20);if(frame>=frames)frame=frames-1;
  if(taking){
   frame=phase==DELIVERY?(int)((GetTickCount()-started)/20u):records[selected].frames-1;
   if(frame>=frames)frame=frames-1;
  }
  BS2Point2 p;
  if(taking && (phase==BATTED || phase==CONTACT || phase==FOUL || phase==FIELDING || phase==FIELD_COMPLETE)){
   p=bs2_pitch_screen_pixel(&moving_ball.position,&camera);
  }else if(taking)p=bs2_pitch_screen_pixel(&path[frame],&camera);
  else{bs2_project_point(&p,&path[frame],&camera);p=(BS2Point2){px(p),py(p)};}
  if(phase!=FIELDING && phase!=FIELD_COMPLETE){
   old_art=SelectObject(art_dc,ball_image);
   TransparentBlt(canvas,p.x-8,p.y-8,17,17,art_dc,0,0,17,17,RGB(255,0,255));
   SelectObject(art_dc,old_art);
  }
 }
 if(taking){
  if(phase==FIELDING || phase==FIELD_COMPLETE)draw_defense_map((GetTickCount()-field_started)/20u+1);
  char info[180];
  const char *runner=first_base_runner();
  snprintf(info,sizeof(info),"Pitch %d    Balls %u    Strikes %u    Outs %u%s%s",pitch_number,
           (unsigned)at_bat.play[5],(unsigned)at_bat.play[4],(unsigned)at_bat.play[6],
           runner?"    On first: ":"",runner?runner:"");
  label(12,8,info,RGB(235,241,246));
  snprintf(info,sizeof(info),"%s    Target offset %+d",pitch_result(),aim);
  if(phase==CONTACT && at_bat.first_base_slot)snprintf(info,sizeof(info),"Occupied-base play unresolved");
  else if(phase==CONTACT)describe_contact(info,sizeof(info));
  label(12,28,info,RGB(255,205,105));
  if(phase==FIELDING || phase==FIELD_COMPLETE){
   unsigned tick=(GetTickCount()-field_started)/20u+1;
   if(is_ground){
    if(ground_defense.received_tick)snprintf(info,sizeof(info),"%s",
      at_bat.first_base_slot?"The runner beat the throw to first.":"First baseman received the throw. Out at first.");
    else if(tick>=ground.throw_tick)snprintf(info,sizeof(info),"%s throws to first.",fielders[field.fielder]);
    else snprintf(info,sizeof(info),"%s %s the ground ball.",fielders[field.fielder],
      ground_defense.pickup_tick?"fielded":"tracking");
   }else snprintf(info,sizeof(info),"%s%s",fielders[field.fielder],tick>=field.catch_tick?" caught the fly ball.":" tracking the ball.");
   label(12,48,info,RGB(212,223,233));
   if(phase==FIELD_COMPLETE)label(12,84,at_bat.play[6]==3?"Side retired. Space: restart practice":"Space: next batter",RGB(235,241,246));
  }else if(phase==AIM && advanced_lineup){
   snprintf(info,sizeof(info),"Batting %u: %s    Space: pitch",(unsigned)at_bat.batting_slot+1,preset==1?"Ara":"Medica");
   label(12,48,info,RGB(212,223,233));
  }else if(phase==COMPLETE){
   if(last_call==5 && at_bat.play[6]==3)
    snprintf(info,sizeof(info),"Side retired. Space: restart practice");
   else if(last_call==5)
    snprintf(info,sizeof(info),"Space: next batter (slot %u)",(unsigned)at_bat.reserved_slot+1);
   else snprintf(info,sizeof(info),"Lineup slot %u reserved. Space: new at-bat",(unsigned)at_bat.reserved_slot+1);
   label(12,48,info,RGB(212,223,233));
  }else if(phase==BATTED)label(12,48,"Ball in play",RGB(212,223,233));
  else if(phase==CONTACT)label(12,48,"Contact. Space: new at-bat",RGB(212,223,233));
  else if(phase==FOUL)label(12,48,"Foul ball. Space: next pitch",RGB(212,223,233));
  else label(12,48,"Space / click: pitch    X: swing    Left / Right: aim",RGB(212,223,233));
  label(12,66,"T: pitch viewer    Esc: exit",RGB(212,223,233));
  if(!ready)label(12,100,"Could not generate or judge this pitch.",RGB(255,130,130));
  return;
 }
 label(12,8,"BASEBALL SUPERSTARS II - PITCH MOTION",RGB(235,241,246));
 char info[180];snprintf(info,sizeof(info),"Curve %d/%u   Group %d / variant %d   Camera %d",selected+1,(unsigned)(sizeof(records)/sizeof(records[0])),records[selected].group,records[selected].variant,preset);
 label(12,29,info,RGB(160,187,204));
 label(12,48,"Left / Right: curve    Up / Down: camera",RGB(212,223,233));
 label(12,66,"Space / click: replay    T: play an at-bat    Esc: exit",RGB(212,223,233));
 if(!ready)label(12,100,"This curve could not be generated.",RGB(255,130,130));
}
static void paint_window(HWND window,HDC dc){
 RECT r;
 GetClientRect(window,&r);
 FillRect(dc,&r,(HBRUSH)GetStockObject(BLACK_BRUSH));
 render();
 int width=r.right,height=width*2/3;
 if(height>r.bottom){height=r.bottom;width=height*3/2;}
 if(width>0&&height>0){
  SetStretchBltMode(dc,COLORONCOLOR);
  StretchBlt(dc,(r.right-width)/2,(r.bottom-height)/2,width,height,canvas,0,0,480,320,SRCCOPY);
 }
}
static HBITMAP load_art(HINSTANCE instance,int id){
 return (HBITMAP)LoadImageA(instance,MAKEINTRESOURCEA(id),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
}
static LRESULT CALLBACK proc(HWND window,UINT message,WPARAM w,LPARAM l){
 switch(message){
 case WM_CREATE:{
  HDC dc=GetDC(window);canvas=CreateCompatibleDC(dc);bitmap=CreateCompatibleBitmap(dc,480,320);ReleaseDC(window,dc);
  HINSTANCE instance=((LPCREATESTRUCTA)l)->hInstance;
  HRSRC raw=FindResourceA(instance,MAKEINTRESOURCEA(106),MAKEINTRESOURCEA(10));
  if(!raw)return -1;
  flight_data=(const unsigned char *)LockResource(LoadResource(instance,raw));
  flight_size=SizeofResource(instance,raw);
  if(!flight_data || !flight_size)return -1;
  raw=FindResourceA(instance,MAKEINTRESOURCEA(107),MAKEINTRESOURCEA(10));
  if(!raw)return -1;
  fly_data=(const uint8_t *)LockResource(LoadResource(instance,raw));
  fly_size=SizeofResource(instance,raw);
  if(!fly_data || !fly_size)return -1;
  raw=FindResourceA(instance,MAKEINTRESOURCEA(108),MAKEINTRESOURCEA(10));
  if(!raw)return -1;
  ground_data=(const uint8_t *)LockResource(LoadResource(instance,raw));
  ground_size=SizeofResource(instance,raw);
  if(!ground_data || !ground_size)return -1;
  art_dc=CreateCompatibleDC(canvas);
  fields[0]=load_art(instance,FIELD_RIGHT);
  fields[1]=load_art(instance,FIELD_LEFT);
  swings[0]=load_art(instance,SWING_RIGHT);
  swings[1]=load_art(instance,SWING_LEFT);
  ball_image=load_art(instance,PITCH_BALL);
  if(!canvas||!bitmap||!art_dc||!fields[0]||!fields[1]||!swings[0]||!swings[1]||!ball_image)return -1;
  previous_bitmap=(HBITMAP)SelectObject(canvas,bitmap);
  font=CreateFontA(-13,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Segoe UI");
  if(font)previous_font=(HFONT)SelectObject(canvas,font);
  replay();update_title(window);SetTimer(window,1,20,NULL);return 0;
 }
 case WM_TIMER:
  if(taking){
   enum PitchPhase previous=phase;
   update_appearance();
   if(previous!=phase)update_title(window);
  }
  InvalidateRect(window,NULL,FALSE);return 0;
 case WM_ERASEBKGND:return 1;
 case WM_KEYDOWN:
  if(l&((LPARAM)1<<30))return 0;
  if(w==VK_ESCAPE){DestroyWindow(window);return 0;}
  if(w=='T'){
   taking=!taking;reset_appearance();replay();update_title(window);InvalidateRect(window,NULL,FALSE);return 0;
  }
  if(taking){
   if(w==VK_SPACE)take_or_restart();
   else if(w=='X')swing();
   else if((phase==AIM || phase==FOUL) && (w==VK_LEFT || w==VK_RIGHT)){
    aim=max(-40,min(40,aim+(w==VK_LEFT?4:-4)));replay();
   }
   update_title(window);InvalidateRect(window,NULL,FALSE);return 0;
  }
  if(w==VK_LEFT)selected=(selected+368)%369;
  else if(w==VK_RIGHT)selected=(selected+1)%369;
  else if(w==VK_UP||w==VK_DOWN)preset=3-preset;
  else if(w!=VK_SPACE)return DefWindowProcA(window,message,w,l);
  replay();InvalidateRect(window,NULL,FALSE);return 0;
 case WM_LBUTTONUP:if(taking){take_or_restart();update_title(window);}else replay();InvalidateRect(window,NULL,FALSE);return 0;
 case WM_PAINT:{
  PAINTSTRUCT paint;HDC dc=BeginPaint(window,&paint);
  paint_window(window,dc);EndPaint(window,&paint);return 0;
 }
 case WM_PRINTCLIENT:paint_window(window,(HDC)w);return 0;
 case WM_DESTROY:
  if(art_dc)DeleteDC(art_dc);
  if(fields[0])DeleteObject(fields[0]);
  if(fields[1])DeleteObject(fields[1]);
  if(swings[0])DeleteObject(swings[0]);
  if(swings[1])DeleteObject(swings[1]);
  if(ball_image)DeleteObject(ball_image);
  KillTimer(window,1);
  if(font){SelectObject(canvas,previous_font);DeleteObject(font);}
  if(bitmap){SelectObject(canvas,previous_bitmap);DeleteObject(bitmap);}
  if(canvas)DeleteDC(canvas);PostQuitMessage(0);return 0;
 }
 return DefWindowProcA(window,message,w,l);
}
int WINAPI WinMain(HINSTANCE instance,HINSTANCE previous,LPSTR args,int show){
 (void)previous;
 taking=strcmp(args,"--at-bat")==0;
 fixed_practice_seed=strcmp(args,"--fixed-seed")==0;
 if(strncmp(args,"--at-bat --seed ",16)==0){
  char *end;
  unsigned long value=strtoul(args+16,&end,10);
  if(end==args+16 || *end!='\0')return 2;
  taking=1;fixed_practice_seed=1;practice_seed=(uint32_t)value;
 }
 reset_appearance();SetProcessDPIAware();
 WNDCLASSA wc={0};wc.lpfnWndProc=proc;wc.hInstance=instance;wc.lpszClassName="BS2PitchMotion";wc.hCursor=LoadCursor(NULL,IDC_ARROW);
 if(!RegisterClassA(&wc))return 1;
 HWND window=CreateWindowExA(0,wc.lpszClassName,"BS2 Pitch Motion",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,980,700,NULL,NULL,instance,NULL);
 if(!window)return 1;ShowWindow(window,show);UpdateWindow(window);
 MSG message;int result;while((result=GetMessageA(&message,NULL,0,0))>0){TranslateMessage(&message);DispatchMessageA(&message);}
 return result<0?1:(int)message.wParam;
}
