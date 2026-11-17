#include "src/menu.h"
#include <assert.h>
#include <stdio.h>
int main(void){
 for(int c=0;c<6;c++){
  Menu m={c,0,0,-1};menu_move(&m,1,0);assert(m.category==(c+1)%6);menu_move(&m,-1,0);assert(m.category==c);
  assert(menu_confirm(&m)==-1&&m.focus==1);
  for(int i=0;i<menu_count(c);i++){
   Menu a={c,i,1,-1},b=a;Rect r=menu_rect(6+i);
   int k=menu_confirm(&a);menu_press(&b,r.x+1,r.y+1);int mouse=menu_release(&b,r.x+1,r.y+1);
   assert(k==mouse&&k==c*16+i);
   menu_press(&b,r.x+1,r.y+1);assert(menu_release(&b,-1,-1)==-1);
   menu_move(&a,1,0);assert(a.item==(i+1)%menu_count(c));menu_move(&a,-1,0);assert(a.item==i);
  }
 }
 Menu m={2,0,0,-1};assert(menu_hit(&m,-5,180)==-1);assert(menu_hit(&m,480,180)==-1);
 for(int c=0;c<6;c++){Menu a={c,0,0,-1};menu_move(&a,0,1);assert(a.focus==1);menu_move(&a,0,-1);assert(a.focus==0);for(int j=0;j<100;j++){menu_move(&a,0,1);assert(a.item>=0&&a.item<menu_count(c));}}
 const int sizes[][2]={{480,320},{960,640},{980,700},{1920,1080},{700,980},{1,1},{0,0}};
 for(unsigned n=0;n<sizeof(sizes)/sizeof(sizes[0]);n++){
  int w=sizes[n][0],h=sizes[n][1],x,y;Rect v=menu_viewport(w,h);
  assert(!menu_screen_point(w,h,-1,0,&x,&y));
  if(v.w<480||v.h<320)continue;
  for(int id=0;id<13;id++){Rect r=menu_rect(id);int sx=v.x+(r.x+r.w/2)*v.w/480,sy=v.y+(r.y+r.h/2)*v.h/320;assert(menu_screen_point(w,h,sx,sy,&x,&y));assert(menu_hit(&m,x,y)==id);}
  if(v.y)assert(!menu_screen_point(w,h,w/2,0,&x,&y));
  if(v.x)assert(!menu_screen_point(w,h,0,h/2,&x,&y));
 }
 puts("PASS: category wrapping, all destination confirmations, keyboard/click equivalence, drag-off cancellation, and out-of-bounds input.");return 0;
}
