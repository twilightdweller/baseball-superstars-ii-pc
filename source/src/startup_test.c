#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <string.h>
#include "active_title.h"
int bs2_title_tick(uint8_t*,uint64_t);
int bs2_state_check(uint8_t*);
static uint8_t object[512];
static ULONGLONG start;
static int done;
static void reset(HWND h){memset(object,0,sizeof(object));uint32_t state=6;memcpy(object+12,&state,4);memcpy(object+16,&state,4);object[0x15c]=1;done=0;start=GetTickCount64();SetWindowTextA(h,"BS2 startup diagnostic | Title state 6 | Not playable");}
static LRESULT CALLBACK proc(HWND h,UINT m,WPARAM w,LPARAM l){
 if(m==WM_TIMER && !done){bs2_title_tick(object,GetTickCount64()-start);if(bs2_state_check(object+8)){uint32_t state;memcpy(&state,object+12,4);if(state==7){done=1;SetWindowTextA(h,"BS2 startup diagnostic | PASS: menu state 7 reached | Menu rendering pending | R: replay");}}return 0;}
 if(m==WM_KEYDOWN){if(w=='R')reset(h);if(w==VK_ESCAPE)DestroyWindow(h);return 0;}
 if(m==WM_SIZE){InvalidateRect(h,NULL,TRUE);return 0;}
 if(m==WM_PAINT){PAINTSTRUCT ps;HDC dc=BeginPaint(h,&ps);RECT r;GetClientRect(h,&r);FillRect(dc,&r,(HBRUSH)GetStockObject(BLACK_BRUSH));double sx=(double)r.right/480,sy=(double)r.bottom/320,scale=sx<sy?sx:sy;int ww=(int)(480*scale),hh=(int)(320*scale);BITMAPINFO b;ZeroMemory(&b,sizeof(b));b.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);b.bmiHeader.biWidth=480;b.bmiHeader.biHeight=-320;b.bmiHeader.biPlanes=1;b.bmiHeader.biBitCount=32;b.bmiHeader.biCompression=BI_RGB;SetStretchBltMode(dc,COLORONCOLOR);StretchDIBits(dc,(r.right-ww)/2,(r.bottom-hh)/2,ww,hh,0,0,480,320,active_title,&b,DIB_RGB_COLORS,SRCCOPY);EndPaint(h,&ps);return 0;}
 if(m==WM_DESTROY){KillTimer(h,1);PostQuitMessage(0);return 0;}
 return DefWindowProcA(h,m,w,l);
}
int WINAPI WinMain(HINSTANCE inst,HINSTANCE prev,LPSTR cmd,int show){
 (void)prev;(void)cmd;WNDCLASSA wc={0};wc.lpfnWndProc=proc;wc.hInstance=inst;wc.lpszClassName="BS2StartupTest";wc.hCursor=LoadCursor(NULL,IDC_ARROW);RegisterClassA(&wc);
 HWND h=CreateWindowA(wc.lpszClassName,"BS2 startup diagnostic",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,980,700,NULL,NULL,inst,NULL);if(!h)return 1;reset(h);SetTimer(h,1,16,NULL);ShowWindow(h,show);MSG msg;while(GetMessage(&msg,NULL,0,0)>0){TranslateMessage(&msg);DispatchMessage(&msg);}return 0;
}
