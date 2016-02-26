#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159
void drawpentagon(int,int);
int rotatex(int,int,float);
int rotatey(int,int,float);
void rotation(int,int,int);
void scaling(int,int,float);
int scale(int,float);
int originx,originy;

void main()
{
  //drawstickman(0,0);
  //drawstickman(200,100);
  int c,x,y,r;
  float s;
  int gd=DETECT,gm;//DETECT is macro defined in graphics.h
  initgraph(&gd,&gm,NULL);//initialize graphic mode
  drawpentagon(0,0);
  printf("MENU\n 1.Translate\n 2.Rotate\n 3.Scale \n 4.Exit \nEnter your Choice : ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
      printf("Enter the translation factor along X and Y axes : ");
      scanf("%d%d",&x,&y);
      cleardevice();
      drawpentagon(x,y);
      break;
    case 2:
      printf("Enter the angle of rotation : ");
      scanf("%d",&r);
      originx = 200;
      originy = 100;
      cleardevice();
      rotation(50,0,r);
      break;
    case 3:
      printf("Enter the scaling factor : ");
      scanf("%f",&s);
      originx = 200;
      originx = 200;
      cleardevice();
      scaling(50,0,s);
      break;
    case 4:
      printf("Exiting!");
      getch();
      closegraph();
      exit(0);
    default:
      printf("Invalid Choice ! Try Again!");
  }
  delay(20);
  getch();
  closegraph();
}

void drawpentagon(int i,int j)
{
  line(200+i,100+j,105+i,169+j);
  line(105+i,169+j,141+i,281+j);
  line(141+i,281+j,259+i,281+j);
  line(259+i,281+j,295+i,169+j);
  line(295+i,169+j,200+i,100+j);
}

void scaling(int i,int j,float s)
{
  line(scale(200+i,s),scale(100+j,s),scale(105+i,s),scale(169+j,s));
  line(scale(105+i,s),scale(169+j,s),scale(141+i,s),scale(281+j,s));
  line(scale(141+i,s),scale(281+j,s),scale(259+i,s),scale(281+j,s));
  line(scale(259+i,s),scale(281+j,s),scale(295+i,s),scale(169+j,s));
  line(scale(295+i,s),scale(169+j,s),scale(200+i,s),scale(100+j,s));
}

void rotation(int i,int j,int angle)
{
  float r = angle*((2*pi)/360);
  line(rotatex(200+i,100+j,r),rotatey(200+i,100+j,r),rotatex(105+i,169+j,r),rotatey(105+i,169+j,r));
  line(rotatex(105+i,169+j,r),rotatey(105+i,169+j,r),rotatex(141+i,281+j,r),rotatey(141+i,281+j,r));
  line(rotatex(141+i,281+j,r),rotatey(141+i,281+j,r),rotatex(259+i,281+j,r),rotatey(259+i,281+j,r));
  line(rotatex(259+i,281+j,r),rotatey(259+i,281+j,r),rotatex(295+i,169+j,r),rotatey(295+i,169+j,r));
  line(rotatex(295+i,169+j,r),rotatey(295+i,169+j,r),rotatex(200+i,100+j,r),rotatey(200+i,100+j,r));
}

int rotatex(int x,int y,float r)
{
  x -= originx;
  y -= originy;
  return (int)((x*cos(r)-y*sin(r))+originx);
}

int rotatey(int x,int y, float r)
{
  x -= originx;
  y -= originy;
  return (int)((x*sin(r)+y*cos(r))+originy);
}

int scale(int x,float s)
{
  x -= originx;
  x *= s;
  return (int)(x+originx);
}
