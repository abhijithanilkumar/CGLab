/*  demo.c*/
#include<graphics.h>
#include<stdio.h>
void lineBres(int x1, int y1, int xn, int yn)
{
int dx = xn - x1, dy = yn - y1;
int di = 2 * dy - dx;
int ds = 2 * dy, dt = 2 * (dy - dx);
putpixel(x1, y1, WHITE);
while (x1 < xn)
{
x1++;
if (di < 0)
di = di + ds;
else
{
y1++;
di = di + dt;
}
putpixel(x1, y1, WHITE);
}
}
int main()
{
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
   initgraph(&gd,&gm,NULL);
   lineBres(100,100,200,200);
   getch();

   closegraph();
   return 0;
}
