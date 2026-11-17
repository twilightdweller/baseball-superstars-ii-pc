#ifndef BS2_MENU_H
#define BS2_MENU_H
/* Portable input model for the reconstructed PC menu, not original game logic. */
typedef struct { int category,item,focus,pressed; } Menu;
typedef struct { int x,y,w,h; } Rect;
extern const char *menu_categories[6];
int menu_count(int category);
const char *menu_label(int category,int item);
Rect menu_rect(int id);
Rect menu_viewport(int width,int height);
int menu_screen_point(int width,int height,int sx,int sy,int *x,int *y);
int menu_hit(Menu *m,int x,int y);
void menu_move(Menu*m,int dx,int dy);
void menu_press(Menu*m,int x,int y);
int menu_release(Menu*m,int x,int y);
int menu_confirm(Menu*m);
#endif
