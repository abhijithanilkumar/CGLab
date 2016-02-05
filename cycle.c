#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159
void drawstickman(int,int);
int rotatex(int,int,float);
int rotatey(int,int,float);
void rotation(int,int,int);
void scaling(int,int,int);
int scale(int,int);
int originx,originy;

void main()
{
  //drawstickman(0,0);
  //drawstickman(200,100);
  int c,x,y,r,s;
  int gd=DETECT,gm;//DETECT is macro defined in graphics.h
  initgraph(&gd,&gm,NULL);//initialize graphic mode
  drawstickman(50,0);
  printf("MENU\n 1.Translate\n 2.Rotate\n 3.Scale \n 4.Exit \nEnter your Choice : ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
      printf("Enter the translation factor along X and Y axes : ");
      scanf("%d%d",&x,&y);
      cleardevice();
      drawstickman(x,y);
      break;
    case 2:
      printf("Enter the angle of rotation : ");
      scanf("%d",&r);
      originx = 200;
      originy = 200;
      cleardevice();
      rotation(50,0,r);
      break;
    case 3:
      printf("Enter the scaling factor : ");
      scanf("%d",&s);
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

void drawstickman(int i,int j)
{
  circle(100+i,150+j,25); //head
  line(100+i,175+j,100+i,250+j); //body
  line(75+i,250+j,125+i,250+j); //seat
  line(100+i,250+j,100+i,270+j); //seat-bar
  line(100+i,270+j,200+i,270+j); //middle-bar
  line(200+i,230+j,200+i,270+j); //handle-bar
  line(175+i,230+j,225+i,230+j); //handle
  line(100+i,200+j,190+i,230+j); //hand
  circle(100+i,300+j,25); //back-wheel
  circle(200+i,300+j,25); //front-wheel
}

void scaling(int i,int j,int s)
{
  circle(scale(100+i,s),scale(150+j,s),25*s); //head
  line(scale(100+i,s),scale(175+j,s),scale(100+i,s),scale(250+j,s)); //body
  line(scale(75+i,s),scale(250+j,s),scale(125+i,s),scale(250+j,s)); //seat
  line(scale(100+i,s),scale(250+j,s),scale(100+i,s),scale(270+j,s)); //seat-bar
  line(scale(100+i,s),scale(270+j,s),scale(200+i,s),scale(270+j,s)); //middle-bar
  line(scale(200+i,s),scale(230+j,s),scale(200+i,s),scale(270+j,s)); //handle-bar
  line(scale(175+i,s),scale(230+j,s),scale(225+i,s),scale(230+j,s)); //handle
  line(scale(100+i,s),scale(200+j,s),scale(190+i,s),scale(230+j,s)); //hand
  circle(scale(100+i,s),scale(300+j,s),25*s); //back-wheel
  circle(scale(200+i,s),scale(300+j,s),25*s); //front-wheel
}

void rotation(int i,int j,int angle)
{
  float r = angle*((2*pi)/360);
  circle(rotatex(100+i,150+j,r),rotatey(100+i,150+j,r),25); //head
  line(rotatex(100+i,175+j,r),rotatey(100+i,175+j,r),rotatex(100+i,250+j,r),rotatey(100+i,250+j,r)); //body
  line(rotatex(75+i,250+j,r),rotatey(75+i,250+j,r),rotatex(125+i,250+j,r),rotatey(125+i,250+j,r)); //seat
  line(rotatex(100+i,250+j,r),rotatey(100+i,250+j,r),rotatex(100+i,270+j,r),rotatey(100+i,270+j,r)); //seat-bar
  line(rotatex(100+i,270+j,r),rotatey(100+i,270+j,r),rotatex(200+i,270+j,r),rotatey(200+i,270+j,r)); //middle-bar
  line(rotatex(200+i,230+j,r),rotatey(200+i,230+j,r),rotatex(200+i,270+j,r),rotatey(200+i,270+j,r)); //handle-bar
  line(rotatex(175+i,230+j,r),rotatey(175+i,230+j,r),rotatex(225+i,230+j,r),rotatey(225+i,230+j,r)); //handle
  line(rotatex(100+i,200+j,r),rotatey(100+i,200+j,r),rotatex(190+i,230+j,r),rotatey(190+i,230+j,r)); //hand
  circle(rotatex(100+i,300+j,r),rotatey(100+i,300+j,r),25); //back-wheel
  circle(rotatex(200+i,300+j,r),rotatey(200+i,300+j,r),25); //front-wheel
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

int scale(int x,int s)
{
  x -= originx;
  x *= s;
  return x+originx;
}
