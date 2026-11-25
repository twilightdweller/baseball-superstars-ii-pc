#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "pitch_path.h"
#include "pitch_scene.h"
#include "camera.h"
#include "taken_pitch.h"
#include <string.h>
#include "pitch_records.h"
static BS2Point3 path[4099],controls[50];
static BS2Projection camera;
static int selected=0,preset=1,frames=0,ready=0;
static DWORD started;
static BS2AtBat at_bat;
static BS2StrikeZone zone;
enum PitchPhase { AIM, DELIVERY, JUDGMENT, COMPLETE };
static enum PitchPhase phase;
static int taking, aim, pitch_number, last_call;
static DWORD judge_started;
static const char *call_name[] = {"Ready", "Called strike", "Ball", "Walk", "", "Called strikeout"};

static void reset_appearance(void) {
 at_bat = (BS2AtBat){0};
 at_bat.play[0x12d] = 9;
 aim = 0; pitch_number = 0; last_call = 0; phase = AIM;
}

/* Statistics recording is outside this single-appearance viewer. */
static void flow_effect(void *context, int effect) { (void)context; (void)effect; }
static HDC canvas;
static HBITMAP bitmap,previous_bitmap;
static HDC art_dc;
static HBITMAP fields[2],ball_image;
enum { FIELD_RIGHT = 101, FIELD_LEFT, PITCH_BALL };
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
 if(taking && ready)ready=bs2_strike_zone(figure,sizeof(figure),&camera,&zone)==0;
 frames=r->frames+3;started=GetTickCount();
}
static void take_or_restart(void) {
 if(phase==COMPLETE){reset_appearance();replay();return;}
 if(phase==AIM && ready){started=GetTickCount();++pitch_number;phase=DELIVERY;}
}

static void update_appearance(void) {
 DWORD now=GetTickCount();
 if(phase==DELIVERY && now-started>=(DWORD)(records[selected].frames-1)*20u){
  last_call=bs2_take_curve(&at_bat,path,(size_t)frames,&camera,&zone);
  if(last_call<1){last_call=0;ready=0;phase=AIM;return;}
  judge_started=now;phase=JUDGMENT;
 }
 if(phase==JUDGMENT){
  int state=bs2_taken_pitch_next_state(&at_bat,(now-judge_started)/20u,flow_effect,NULL);
  if(state<0){ready=0;phase=AIM;}
  else if(state>0)phase=at_bat.batter_reserved?COMPLETE:AIM;
 }
}

static void update_title(HWND window) {
 char title[160];
 if(!taking){SetWindowTextA(window,"BS2 Pitch Motion");return;}
 snprintf(title,sizeof(title),"BS2 At-Bat | Pitch %d | %s | Balls %u, Strikes %u, Outs %u%s",
          pitch_number,phase==DELIVERY?"In flight":call_name[last_call],
          (unsigned)at_bat.play[5],(unsigned)at_bat.play[4],(unsigned)at_bat.play[6],
          phase==COMPLETE?" | Complete":phase==AIM?" | Ready":"");
 SetWindowTextA(window,title);
}
static void label(int x,int y,const char *s,COLORREF color){
 SetTextColor(canvas,color);
 TextOutA(canvas,x,y,s,(int)lstrlenA(s));
}
static void render(void){
 HGDIOBJ old_art=SelectObject(art_dc,fields[preset-1]);
 BitBlt(canvas,0,0,480,320,art_dc,0,0,SRCCOPY);
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
  if(taking)p=bs2_pitch_screen_pixel(&path[frame],&camera);
  else{bs2_project_point(&p,&path[frame],&camera);p=(BS2Point2){px(p),py(p)};}
  old_art=SelectObject(art_dc,ball_image);
  TransparentBlt(canvas,p.x-8,p.y-8,17,17,art_dc,0,0,17,17,RGB(255,0,255));
  SelectObject(art_dc,old_art);
 }
 if(taking){
  char info[180];
  snprintf(info,sizeof(info),"Pitch %d    Balls %u    Strikes %u    Outs %u",pitch_number,
           (unsigned)at_bat.play[5],(unsigned)at_bat.play[4],(unsigned)at_bat.play[6]);
  label(12,8,info,RGB(235,241,246));
  snprintf(info,sizeof(info),"%s    Target offset %+d",phase==DELIVERY?"Pitch in flight":call_name[last_call],aim);
  label(12,28,info,RGB(255,205,105));
  if(phase==COMPLETE){
   snprintf(info,sizeof(info),"Lineup slot %u reserved. Space: new at-bat",(unsigned)at_bat.reserved_slot+1);
   label(12,48,info,RGB(212,223,233));
  }else label(12,48,"Left / Right: aim    Space / click: deliver pitch",RGB(212,223,233));
  label(12,66,"T: pitch viewer    Esc: exit",RGB(212,223,233));
  if(!ready)label(12,100,"Could not generate or judge this pitch.",RGB(255,130,130));
  return;
 }
 label(12,8,"BASEBALL SUPERSTARS II - PITCH MOTION",RGB(235,241,246));
 char info[180];snprintf(info,sizeof(info),"Curve %d/%u   Group %d / variant %d   Camera %d",selected+1,(unsigned)(sizeof(records)/sizeof(records[0])),records[selected].group,records[selected].variant,preset);
 label(12,29,info,RGB(160,187,204));
 label(12,48,"Left / Right: curve    Up / Down: camera",RGB(212,223,233));
 label(12,66,"Space / click: replay    T: take an at-bat    Esc: exit",RGB(212,223,233));
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
  art_dc=CreateCompatibleDC(canvas);
  fields[0]=load_art(instance,FIELD_RIGHT);
  fields[1]=load_art(instance,FIELD_LEFT);
  ball_image=load_art(instance,PITCH_BALL);
  if(!canvas||!bitmap||!art_dc||!fields[0]||!fields[1]||!ball_image)return -1;
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
   else if(phase==AIM && (w==VK_LEFT || w==VK_RIGHT)){
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
  if(ball_image)DeleteObject(ball_image);
  KillTimer(window,1);
  if(font){SelectObject(canvas,previous_font);DeleteObject(font);}
  if(bitmap){SelectObject(canvas,previous_bitmap);DeleteObject(bitmap);}
  if(canvas)DeleteDC(canvas);PostQuitMessage(0);return 0;
 }
 return DefWindowProcA(window,message,w,l);
}
int WINAPI WinMain(HINSTANCE instance,HINSTANCE previous,LPSTR args,int show){
 (void)previous;taking=strcmp(args,"--at-bat")==0;reset_appearance();SetProcessDPIAware();
 WNDCLASSA wc={0};wc.lpfnWndProc=proc;wc.hInstance=instance;wc.lpszClassName="BS2PitchMotion";wc.hCursor=LoadCursor(NULL,IDC_ARROW);
 if(!RegisterClassA(&wc))return 1;
 HWND window=CreateWindowExA(0,wc.lpszClassName,"BS2 Pitch Motion",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,980,700,NULL,NULL,instance,NULL);
 if(!window)return 1;ShowWindow(window,show);UpdateWindow(window);
 MSG message;int result;while((result=GetMessageA(&message,NULL,0,0))>0){TranslateMessage(&message);DispatchMessageA(&message);}
 return result<0?1:(int)message.wParam;
}
