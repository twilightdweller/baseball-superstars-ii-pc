#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "assets.h"
int bs2_blit(uint16_t*,size_t,const uint8_t*,size_t,const uint16_t*,size_t,unsigned);
static int current;
static uint32_t *rgb;
static BITMAPINFO bi;
static void select_frame(HWND hwnd,int index){
 current=(index+30)%30;const Frame *f=&frames[current];
 size_t n=(size_t)f->w*f->h;
 uint16_t *raw=calloc(n,2);free(rgb);rgb=calloc(n,4);
 if(!raw||!rgb){MessageBoxA(hwnd,"Allocation failed","Error",MB_OK);ExitProcess(1);}
 if(bs2_blit(raw,n,f->data,f->size,f->pal,f->colors,0)){MessageBoxA(hwnd,"Frame decoding failed","Error",MB_OK);ExitProcess(2);}
 for(size_t i=0;i<n;i++){uint16_t v=raw[i];rgb[i]=((((v>>11)&31)*255/31)<<16)|((((v>>5)&63)*255/63)<<8)|((v&31)*255/31);}
 free(raw);ZeroMemory(&bi,sizeof(bi));bi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);bi.bmiHeader.biWidth=f->w;bi.bmiHeader.biHeight=-f->h;bi.bmiHeader.biPlanes=1;bi.bmiHeader.biBitCount=32;bi.bmiHeader.biCompression=BI_RGB;
 char title[240];snprintf(title,sizeof(title),"BS2 native asset viewer | %d/30 | %s | Arrow keys: browse | Not playable",current+1,f->name);SetWindowTextA(hwnd,title);InvalidateRect(hwnd,NULL,TRUE);
}
static LRESULT CALLBACK proc(HWND h,UINT m,WPARAM w,LPARAM l){
 if(m==WM_KEYDOWN){if(w==VK_RIGHT||w==VK_SPACE)select_frame(h,current+1);if(w==VK_LEFT)select_frame(h,current-1);if(w==VK_ESCAPE)DestroyWindow(h);return 0;}
 if(m==WM_SIZE){InvalidateRect(h,NULL,TRUE);return 0;}
 if(m==WM_PAINT){PAINTSTRUCT ps;HDC dc=BeginPaint(h,&ps);RECT r;GetClientRect(h,&r);FillRect(dc,&r,(HBRUSH)GetStockObject(DKGRAY_BRUSH));if(rgb){const Frame *f=&frames[current];double sx=(double)r.right/f->w,sy=(double)r.bottom/f->h;double scale=sx<sy?sx:sy;int ww=(int)(f->w*scale),hh=(int)(f->h*scale);SetStretchBltMode(dc,COLORONCOLOR);StretchDIBits(dc,(r.right-ww)/2,(r.bottom-hh)/2,ww,hh,0,0,f->w,f->h,rgb,&bi,DIB_RGB_COLORS,SRCCOPY);}EndPaint(h,&ps);return 0;}
 if(m==WM_DESTROY){free(rgb);PostQuitMessage(0);return 0;}
 return DefWindowProcA(h,m,w,l);
}
int WINAPI WinMain(HINSTANCE inst,HINSTANCE prev,LPSTR cmd,int show){
 (void)prev;(void)cmd;WNDCLASSA wc={0};wc.lpfnWndProc=proc;wc.hInstance=inst;wc.lpszClassName="BS2AssetViewer";wc.hCursor=LoadCursor(NULL,IDC_ARROW);RegisterClassA(&wc);
 HWND h=CreateWindowA(wc.lpszClassName,"BS2 native asset viewer",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,980,700,NULL,NULL,inst,NULL);if(!h)return 1;select_frame(h,17);ShowWindow(h,show);
 MSG msg;while(GetMessage(&msg,NULL,0,0)>0){TranslateMessage(&msg);DispatchMessage(&msg);}return 0;
}
