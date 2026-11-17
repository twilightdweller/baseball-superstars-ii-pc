#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "pitch_path.h"
#include "pitch_scene.h"
#include "camera.h"
#include "pitch_records.h"
static BS2Point3 path[4099],controls[50];
static BS2Projection camera;
static int selected=0,preset=1,frames=0,ready=0;
static DWORD started;
static HDC canvas;
static HBITMAP bitmap,previous_bitmap;
static HFONT font,previous_font;
static int px(BS2Point2 p){return p.x/262144;}
static int py(BS2Point2 p){return p.y/262144;}
static void replay(void){
 const PitchRecord *r=&records[selected];BS2PitchSpec spec={0};
 spec.count=r->count;spec.frames=r->frames;spec.style=r->style;spec.coordinate_format=1;spec.kind=r->kind;
 spec.target=(BS2Point3){0,-10*262144,0};
 ready=bs2_camera_from_figure(figure,sizeof(figure),preset,&camera)==0 &&
       bs2_pitch_release(figure,sizeof(figure),r->style,preset==0,&spec.release)==0 &&
       bs2_pitch_path(&spec,r->points,controls,path)==0;
 frames=r->frames+3;started=GetTickCount();
}
static void label(int x,int y,const char *s,COLORREF color){SetTextColor(canvas,color);TextOutA(canvas,x,y,s,(int)lstrlenA(s));}
static void render(void){
 RECT bounds={0,0,480,320};HBRUSH bg=CreateSolidBrush(RGB(18,25,33));FillRect(canvas,&bounds,bg);DeleteObject(bg);
 SetBkMode(canvas,TRANSPARENT);
 if(ready){
  HPEN line=CreatePen(PS_SOLID,1,RGB(78,108,129));HGDIOBJ old=SelectObject(canvas,line);
  for(int i=0;i<frames;i++){
   BS2Point2 p;bs2_project_point(&p,&path[i],&camera);
   if(i==0)MoveToEx(canvas,px(p),py(p),NULL);else LineTo(canvas,px(p),py(p));
  }
  SelectObject(canvas,old);DeleteObject(line);
  DWORD elapsed=(GetTickCount()-started)%(DWORD)(frames*20+1200);
  int frame=elapsed<300?0:(int)((elapsed-300)/20);if(frame>=frames)frame=frames-1;
  BS2Point2 p;bs2_project_point(&p,&path[frame],&camera);
  HBRUSH ball=CreateSolidBrush(RGB(255,205,105));HGDIOBJ ob=SelectObject(canvas,ball);old=SelectObject(canvas,GetStockObject(NULL_PEN));
  Ellipse(canvas,px(p)-4,py(p)-4,px(p)+5,py(p)+5);SelectObject(canvas,ob);SelectObject(canvas,old);DeleteObject(ball);
 }
 RECT top={0,0,480,55},bottom={0,263,480,320};bg=CreateSolidBrush(RGB(18,25,33));FillRect(canvas,&top,bg);FillRect(canvas,&bottom,bg);DeleteObject(bg);
 label(12,8,"BASEBALL SUPERSTARS II - PITCH MOTION",RGB(235,241,246));
 char info[180];snprintf(info,sizeof(info),"Curve %d/%u   Group %d / variant %d   Camera %d",selected+1,(unsigned)(sizeof(records)/sizeof(records[0])),records[selected].group,records[selected].variant,preset);
 label(12,29,info,RGB(160,187,204));
 label(12,270,"Left / Right: curve    Up / Down: camera",RGB(212,223,233));
 label(12,288,"Space / click: replay    Esc: exit",RGB(212,223,233));
 if(!ready)label(12,100,"This curve could not be generated.",RGB(255,130,130));
}
static LRESULT CALLBACK proc(HWND window,UINT message,WPARAM w,LPARAM l){
 switch(message){
 case WM_CREATE:{
  HDC dc=GetDC(window);canvas=CreateCompatibleDC(dc);bitmap=CreateCompatibleBitmap(dc,480,320);ReleaseDC(window,dc);
  if(!canvas||!bitmap)return -1;
  previous_bitmap=(HBITMAP)SelectObject(canvas,bitmap);
  font=CreateFontA(-13,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Segoe UI");
  if(font)previous_font=(HFONT)SelectObject(canvas,font);
  replay();SetTimer(window,1,20,NULL);return 0;
 }
 case WM_TIMER:InvalidateRect(window,NULL,FALSE);return 0;
 case WM_ERASEBKGND:return 1;
 case WM_KEYDOWN:
  if(l&((LPARAM)1<<30))return 0;
  if(w==VK_ESCAPE){DestroyWindow(window);return 0;}
  if(w==VK_LEFT)selected=(selected+368)%369;
  else if(w==VK_RIGHT)selected=(selected+1)%369;
  else if(w==VK_UP||w==VK_DOWN)preset=3-preset;
  else if(w!=VK_SPACE)return DefWindowProcA(window,message,w,l);
  replay();InvalidateRect(window,NULL,FALSE);return 0;
 case WM_LBUTTONUP:replay();InvalidateRect(window,NULL,FALSE);return 0;
 case WM_PAINT:{
  PAINTSTRUCT paint;HDC dc=BeginPaint(window,&paint);RECT r;GetClientRect(window,&r);
  FillRect(dc,&r,(HBRUSH)GetStockObject(BLACK_BRUSH));render();
  int width=r.right,height=width*2/3;if(height>r.bottom){height=r.bottom;width=height*3/2;}
  if(width>0&&height>0){SetStretchBltMode(dc,COLORONCOLOR);StretchBlt(dc,(r.right-width)/2,(r.bottom-height)/2,width,height,canvas,0,0,480,320,SRCCOPY);}
  EndPaint(window,&paint);return 0;
 }
 case WM_DESTROY:
  KillTimer(window,1);
  if(font){SelectObject(canvas,previous_font);DeleteObject(font);}
  if(bitmap){SelectObject(canvas,previous_bitmap);DeleteObject(bitmap);}
  if(canvas)DeleteDC(canvas);PostQuitMessage(0);return 0;
 }
 return DefWindowProcA(window,message,w,l);
}
int WINAPI WinMain(HINSTANCE instance,HINSTANCE previous,LPSTR args,int show){
 (void)previous;(void)args;SetProcessDPIAware();
 WNDCLASSA wc={0};wc.lpfnWndProc=proc;wc.hInstance=instance;wc.lpszClassName="BS2PitchMotion";wc.hCursor=LoadCursor(NULL,IDC_ARROW);
 if(!RegisterClassA(&wc))return 1;
 HWND window=CreateWindowExA(0,wc.lpszClassName,"BS2 Pitch Motion - diagnostic, no batting or match gameplay",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,980,700,NULL,NULL,instance,NULL);
 if(!window)return 1;ShowWindow(window,show);UpdateWindow(window);
 MSG message;int result;while((result=GetMessageA(&message,NULL,0,0))>0){TranslateMessage(&message);DispatchMessageA(&message);}
 return result<0?1:(int)message.wParam;
}
