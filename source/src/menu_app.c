#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "active_title.h"
#include "menu_icons.h"
int bs2_title_tick(uint8_t*,uint64_t);
int bs2_state_check(uint8_t*);
static Menu menu={2,0,0,-1};
static uint8_t object[512];
static int showing_menu,space_down;
static ULONGLONG start;
static HDC canvas;
static HBITMAP bitmap;
static HGDIOBJ oldbitmap;
static HFONT small,big;
static uint32_t *pixels;
static RECT viewport(HWND h){RECT client;GetClientRect(h,&client);Rect r=menu_viewport(client.right,client.bottom);return(RECT){r.x,r.y,r.x+r.w,r.y+r.h};}
static POINT point(HWND h,LPARAM l){RECT r;GetClientRect(h,&r);int x,y;menu_screen_point(r.right,r.bottom,(short)LOWORD(l),(short)HIWORD(l),&x,&y);return(POINT){x,y};}
static void enter(HWND h){showing_menu=1;SetWindowTextA(h,"Baseball Superstars II | Interactive menu preview | Gameplay unavailable");InvalidateRect(h,NULL,FALSE);}
static void result(HWND h,int action){if(action<0)return;char text[160];snprintf(text,sizeof(text),"%s is not available in this build.",menu_label(action/16,action%16));MessageBoxA(h,text,"Menu preview",MB_OK|MB_ICONINFORMATION);}
static void text(const char*s,Rect r,COLORREF color,HFONT font){SetTextColor(canvas,color);SelectObject(canvas,font);RECT q={r.x,r.y,r.x+r.w,r.y+r.h};DrawTextA(canvas,s,-1,&q,DT_CENTER|DT_VCENTER|DT_SINGLELINE);}
static void box(Rect r,COLORREF color){RECT q={r.x,r.y,r.x+r.w,r.y+r.h};HBRUSH b=CreateSolidBrush(color);FillRect(canvas,&q,b);DeleteObject(b);}
static void draw(void){
 if(!showing_menu){memcpy(pixels,active_title,sizeof(active_title));return;}
 for(int i=0;i<480*320;i++){uint32_t c=active_title[i];pixels[i]=((((c>>16)&255)/5)<<16)|((((c>>8)&255)/5)<<8)|(c&255)/5;}
 SetBkMode(canvas,TRANSPARENT);
 text("BASEBALL SUPERSTARS II",(Rect){12,8,456,26},RGB(255,255,255),big);
 text("MAIN MENU",(Rect){12,36,456,17},RGB(255,194,66),small);
 for(int i=0;i<6;i++){
  Rect r=menu_rect(i);int selected=i==menu.category;box(r,selected?RGB(36,87,116):RGB(14,29,43));
  if((!menu.focus&&selected)||menu.pressed==i){RECT q={r.x,r.y,r.x+r.w,r.y+r.h};HBRUSH b=CreateSolidBrush(RGB(255,194,66));FrameRect(canvas,&q,b);DeleteObject(b);}
  const Icon *ic=&icons[i];int iw=ic->w,ih=ic->h;if(iw>44){ih=ih*44/iw;iw=44;}if(ih>44){iw=iw*44/ih;ih=44;}int ox=r.x+(r.w-iw)/2,oy=r.y+2+(44-ih)/2;
  for(int y=0;y<ih;y++)for(int x=0;x<iw;x++){uint32_t v=ic->p[(y*ic->h/ih)*ic->w+x*ic->w/iw];if(v>>24)pixels[(oy+y)*480+ox+x]=v&0xffffff;}
  text(menu_categories[i],(Rect){r.x,r.y+48,r.w,15},selected?RGB(255,214,92):RGB(240,240,240),small);
 }
 for(int i=0;i<menu_count(menu.category);i++){Rect r=menu_rect(6+i);int sel=menu.focus&&i==menu.item;box(r,sel?RGB(38,94,126):RGB(18,38,53));if(sel||menu.pressed==i+6){RECT q={r.x,r.y,r.x+r.w,r.y+r.h};HBRUSH b=CreateSolidBrush(RGB(255,194,66));FrameRect(canvas,&q,b);DeleteObject(b);}text(menu_label(menu.category,i),r,sel?RGB(255,220,110):RGB(244,244,244),small);}
 text("Arrows: navigate   Space / click: confirm   Esc: back",(Rect){8,291,464,18},RGB(220,230,240),small);
}
static LRESULT CALLBACK proc(HWND h,UINT m,WPARAM w,LPARAM l){
 if(m==WM_TIMER&&!showing_menu){bs2_title_tick(object,GetTickCount64()-start);if(bs2_state_check(object+8))enter(h);return 0;}
 if(m==WM_KEYDOWN){
  if(w==VK_SPACE){if(!(l&(1L<<30))){space_down=1;if(showing_menu){Rect r=menu_rect(menu.focus?6+menu.item:menu.category);menu_press(&menu,r.x+r.w/2,r.y+r.h/2);}}}
  else if(showing_menu){if(w==VK_LEFT)menu_move(&menu,-1,0);if(w==VK_RIGHT)menu_move(&menu,1,0);if(w==VK_UP)menu_move(&menu,0,-1);if(w==VK_DOWN)menu_move(&menu,0,1);if(w==VK_ESCAPE){if(menu.focus)menu.focus=0;else DestroyWindow(h);}}
  else if(w==VK_ESCAPE)DestroyWindow(h);
  InvalidateRect(h,NULL,FALSE);return 0;
 }
 if(m==WM_KEYUP&&w==VK_SPACE){if(space_down){space_down=0;if(!showing_menu)enter(h);else{Rect r=menu_rect(menu.focus?6+menu.item:menu.category);result(h,menu_release(&menu,r.x+r.w/2,r.y+r.h/2));}InvalidateRect(h,NULL,FALSE);}return 0;}
 if(m==WM_LBUTTONDOWN){POINT p=point(h,l);SetFocus(h);if(p.x>=0){SetCapture(h);if(showing_menu)menu_press(&menu,p.x,p.y);}InvalidateRect(h,NULL,FALSE);return 0;}
 if(m==WM_LBUTTONUP){POINT p=point(h,l);int captured=GetCapture()==h;if(captured){if(showing_menu){int action=menu_release(&menu,p.x,p.y);ReleaseCapture();result(h,action);}else{ReleaseCapture();if(p.x>=0)enter(h);}}InvalidateRect(h,NULL,FALSE);return 0;}
 if(m==WM_KILLFOCUS||m==WM_CAPTURECHANGED){space_down=0;menu.pressed=-1;InvalidateRect(h,NULL,FALSE);return 0;}
 if(m==WM_SIZE){menu.pressed=-1;space_down=0;InvalidateRect(h,NULL,FALSE);return 0;}
 if(m==WM_PAINT){PAINTSTRUCT ps;HDC dc=BeginPaint(h,&ps);RECT q;GetClientRect(h,&q);FillRect(dc,&q,(HBRUSH)GetStockObject(BLACK_BRUSH));draw();RECT r=viewport(h);SetStretchBltMode(dc,COLORONCOLOR);StretchBlt(dc,r.left,r.top,r.right-r.left,r.bottom-r.top,canvas,0,0,480,320,SRCCOPY);EndPaint(h,&ps);return 0;}
 if(m==WM_DESTROY){KillTimer(h,1);PostQuitMessage(0);return 0;}return DefWindowProcA(h,m,w,l);
}
int WINAPI WinMain(HINSTANCE inst,HINSTANCE prev,LPSTR cmd,int show){
 (void)prev;(void)cmd;SetProcessDPIAware();WNDCLASSA wc={0};wc.lpfnWndProc=proc;wc.hInstance=inst;wc.lpszClassName="BS2MenuPreview";wc.hCursor=LoadCursor(NULL,IDC_ARROW);RegisterClassA(&wc);
 BITMAPINFO b={0};b.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);b.bmiHeader.biWidth=480;b.bmiHeader.biHeight=-320;b.bmiHeader.biPlanes=1;b.bmiHeader.biBitCount=32;canvas=CreateCompatibleDC(NULL);bitmap=CreateDIBSection(canvas,&b,DIB_RGB_COLORS,(void**)&pixels,NULL,0);if(!canvas||!bitmap)return 1;oldbitmap=SelectObject(canvas,bitmap);
 small=CreateFontA(-12,0,0,0,FW_BOLD,0,0,0,ANSI_CHARSET,0,0,NONANTIALIASED_QUALITY,0,"Arial");big=CreateFontA(-20,0,0,0,FW_BOLD,0,0,0,ANSI_CHARSET,0,0,NONANTIALIASED_QUALITY,0,"Arial");
 HWND h=CreateWindowA(wc.lpszClassName,"Baseball Superstars II | Title | Menu preview",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,980,700,NULL,NULL,inst,NULL);if(!h)return 2;uint32_t state=6;memcpy(object+12,&state,4);memcpy(object+16,&state,4);object[0x15c]=1;start=GetTickCount64();SetTimer(h,1,16,NULL);ShowWindow(h,show);MSG msg;while(GetMessage(&msg,NULL,0,0)>0){TranslateMessage(&msg);DispatchMessage(&msg);}SelectObject(canvas,oldbitmap);DeleteObject(bitmap);DeleteDC(canvas);DeleteObject(small);DeleteObject(big);return 0;
}
