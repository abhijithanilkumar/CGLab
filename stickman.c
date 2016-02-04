#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159
void mline(int x1,int y1,int x2,int y2);
void bline(int x1, int y1, int xn, int yn);
void circle(int xc,int yc,int r);
void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void drawCircle(int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, RED);
putpixel(xc-x, yc+y, RED);
putpixel(xc+x, yc-y, RED);
putpixel(xc-x, yc-y, RED);
putpixel(xc+y, yc+x, RED);
putpixel(xc-y, yc+x, RED);
putpixel(xc+y, yc-x, RED);
putpixel(xc-y, yc-x, RED);
}
void main()
{
    int x1,x2,y1,y2,i,xstart,ystart,xend,yend,xcenter,ycenter,n_lines,margin,line_length;
    float angle_step,theta;
    xcenter = 280;
    ycenter = 200;
    int gd=DETECT,gm;//DETECT is macro defined in graphics.h
    initgraph(&gd,&gm,NULL);//initialize graphic mode
    //left
    circle(100,50,50);
    mline(100,100,100,250); //body
    bline(50,100,100,150); //hand-left
    bline(100,150,150,100); //hand-right
    mline(100,250,50,300); //leg-left
    bline(100,250,150,300); //leg-right
    //center
    circle(100+150,50,50);
    mline(100+150,100,100+150,250); //body
    mline(50+150,200,100+150,150); //hand-left
    bline(100+150,150,150+150,200); //hand-right
    mline(100+150,250,50+150,300); //leg-left
    bline(100+150,250,150+150,300); //leg-right
    //right
    circle(100+300,50,50);
    mline(100+300,100,100+300,250); //body
    bline(50+300,100,100+300,150); //hand-left
    bline(100+300,150,150+300,100); //hand-right
    mline(50+300,200,100+300,250); //leg-left
    bline(100+300,250,150+300,250); //leg-right
    getch();
}

void mline(int x1,int y1,int x2,int y2)
{
	int dx,dy,d,incry,incre,incrne,slopegt1=0;
	dx=abs(x1-x2);dy=abs(y1-y2);
	if(dy>dx)
	{
		swap(&x1,&y1);
		swap(&x2,&y2);
		swap(&dx,&dy);
		slopegt1=1;
	}
	if(x1>x2)
	{
		swap(&x1,&x2);
		swap(&y1,&y2);
	}
	if(y1>y2)
		incry=-1;
	else
		incry=1;
	d=2*dy-dx;
	incre=2*dy;
	incrne=2*(dy-dx);
	while(x1<x2)
	{
		if(d<=0)
			d+=incre;
		else
		{
			d+=incrne;
			y1+=incry;
		}
		x1++;
		if(slopegt1)
			putpixel(y1,x1,WHITE);
		else
			putpixel(x1,y1,WHITE);
	}
}

void bline(int x1, int y1, int xn, int yn)
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

void circle(int xc,int yc,int r)
{
  int x = 0, y = r;
  int p = 1 - r;
  while (x < y)
  {
    drawCircle(xc, yc, x, y);
    x++;
    if (p < 0)
      p = p + 2 * x + 1;
    else
    {
      y--;
      p = p + 2 * (x - y) + 1;
    }
      drawCircle(xc, yc, x, y);
  }
}
