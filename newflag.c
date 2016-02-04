#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159
void draw(int x1,int y1,int x2,int y2,int c);
void circle(int xc,int yc,int r);
void main()
{
    int x1,x2,y1,y2,i,xstart,ystart,xend,yend,xcenter,ycenter,n_lines,margin,line_length;
    float angle_step,theta;
    xcenter = 280;
    ycenter = 200;
    int gd=DETECT,gm;//DETECT is macro defined in graphics.h
    initgraph(&gd,&gm,NULL);//initialize graphic mode
    for(i=0;i<=100;++i)
    {
      draw(50,50+i,500,50+i,12);
      draw(50,150+i,500,150+i,15);
      draw(50,250+i,500,250+i,2);
      circle(xcenter,ycenter,35);
    }
    margin = 600/40;
    line_length = 600/12 - margin;
    n_lines = 24;
    angle_step = (2 * pi) / n_lines;
    xstart = xcenter;
    ystart = ycenter;
    for(i=0;i<24;++i)
    {
      theta = angle_step * i;
      xend = (int)(line_length * cos(theta)) + xcenter;
      yend = (int)(line_length * sin(theta)) + ycenter;
      setcolor(1);
      line(xstart, ystart, xend, yend);
    }
    getch();
}

void draw(int x1,int y1,int x2,int y2,int c)
{
    float x,y,dx,dy,pixel;
    int i;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
    pixel=dx;
    else
    pixel=dy;

    dx=dx/pixel;
    dy=dy/pixel;

    x=x1;
    y=y1;

    i=1;
    while(i<=pixel)
    {
          putpixel(x,y,c);
          x=x+dx;
          y=y+dy;
          i=i+1;
    }
}

void Draw8Points(int xc,int yc, int a, int b)
{
    putpixel(xc+a, yc+b, 1);
    putpixel(xc-a, yc+b, 1);
    putpixel(xc-a, yc-b, 1);
    putpixel(xc+a, yc-b, 1);
    putpixel(xc+b, yc+a, 1);
    putpixel(xc-b, yc+a, 1);
    putpixel(xc-b, yc-a, 1);
    putpixel(xc+b, yc-a, 1);
}

void circle(int xc,int yc, int R)
{
  int x=R,y=0;
  double theta=0,dtheta=1.0/R;
  Draw8Points(xc,yc,x,y );
  while(x>y)
  {
    theta+=dtheta;
    x=round(R*cos(theta));
    y=round(R*sin(theta));
    Draw8Points(xc,yc,x,y);
  }
}
