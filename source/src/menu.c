#include "menu.h"
const char *menu_categories[6]={"OPTIONS","SPECIAL","PLAY","CHEATS","HELP","RANKING"};
static const char* labels[6][7]={
 {"Common settings","Detail settings","Reset game","Data management"},
 {"Hall of Fame","Super Player","Edit name","Records"},
 {"My League","Season","Tournament","Match Mode","Exhibition","Homerun Race","Mission Mode"},
 {"Enable currency cheat","Add G Points"},
 {"How to play","More menu","About"},
 {"Rankings"}};
static const int counts[6]={4,4,7,2,3,1};
int menu_count(int c){return counts[c];}
const char*menu_label(int c,int i){return labels[c][i];}
Rect menu_rect(int id){
 if(id<6)return (Rect){12+id*77,63,70,66};
 int i=id-6;return (Rect){24+(i%2)*222,151+(i/2)*31,210,25};
}
int menu_hit(Menu*m,int x,int y){
 for(int id=0;id<6+menu_count(m->category);id++){Rect r=menu_rect(id);if(x>=r.x&&y>=r.y&&x<r.x+r.w&&y<r.y+r.h)return id;}
 return -1;
}
void menu_move(Menu*m,int dx,int dy){
 m->pressed=-1;
 if(dy){if(!m->focus){m->focus=1;return;}if(dy<0&&m->item<2){m->focus=0;return;}int n=menu_count(m->category);m->item=(m->item+2*dy+n)%n;return;}
 if(!m->focus){m->category=(m->category+dx+6)%6;m->item=0;}
 else {int n=menu_count(m->category);m->item=(m->item+dx+n)%n;}
}
void menu_press(Menu*m,int x,int y){m->pressed=menu_hit(m,x,y);}
int menu_release(Menu*m,int x,int y){
 int id=menu_hit(m,x,y),old=m->pressed;m->pressed=-1;
 if(id<0||id!=old)return -1;
 if(id<6){m->category=id;m->item=0;m->focus=1;return -1;}
 m->item=id-6;m->focus=1;return m->category*16+m->item;
}
int menu_confirm(Menu*m){int id=m->focus?6+m->item:m->category;Rect r=menu_rect(id);menu_press(m,r.x+r.w/2,r.y+r.h/2);return menu_release(m,r.x+r.w/2,r.y+r.h/2);}

Rect menu_viewport(int width,int height){
 if(width<=0||height<=0)return (Rect){0,0,0,0};
 int w=width,h=height;
 if((long long)width*320<(long long)height*480)h=(int)((long long)width*320/480);
 else w=(int)((long long)height*480/320);
 return (Rect){(width-w)/2,(height-h)/2,w,h};
}
int menu_screen_point(int width,int height,int sx,int sy,int*x,int*y){
 Rect r=menu_viewport(width,height);*x=-1;*y=-1;
 if(r.w<=0||r.h<=0||sx<r.x||sx>=r.x+r.w||sy<r.y||sy>=r.y+r.h)return 0;
 *x=(int)((long long)(sx-r.x)*480/r.w);*y=(int)((long long)(sy-r.y)*320/r.h);return 1;
}
