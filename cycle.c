#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159
void drawstickman(int,int);
int rotatex(int,int,float);
int rotatey(int,int,float);
void rotation(int,int,int);
int hx,hy,hr,bx1,bx2,by2,hnx1,hnx2,hny1,hny2;
int sx1,sx2,sy1,sy2,sbx1,sbx2,sby1,sby2;
int hdx1,hdx2,hdy1,hdy2,hdbx1,hdbx2,hdby1,hdby2;
int mbx1,mbx2,mby1,mby2;
int fwx,fwy,fwr,bwx,bwy,bwr;

void main()
{
  //drawstickman(0,0);
  //drawstickman(200,100);
  int c,x,y,r;
  int gd=DETECT,gm;//DETECT is macro defined in graphics.h
  initgraph(&gd,&gm,NULL);//initialize graphic mode
  drawstickman(100,100);
  printf("MENU\n 1.Translate\n 2.Rotate\n 3.Scale \n 4.Exit \nEnter your Choice : ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
      printf("Enter the translation factor along X and Y axes : ");
      scanf("%d%d",&x,&y);
      cleardevice();
      drawstickman(x+100,y+100);
      break;
    case 2:
      printf("Enter the angle of rotation : ");
      scanf("%d",&r);
      cleardevice();
      rotation(100,100,r);
      break;
    case 3:
      break;
    case 4:
      printf("Exiting!");
      getch();
      closegraph();
      exit(0);
    default:
      printf("Invalid Choice ! Try Again!");
  }
  getch();
  closegraph();
}
/*
void set()
{
  hx = 100;
  hy = 150;
  hr = 25;
  bx1 = 100;
  bx2 = 100;
  by1 = 175;
  by2 = 250;
  hnx1 = ;
  hnx2 = ;
  hny1 = ;
  hny2 = ;
  sx1 = 75;
  sx2 = 125;
  sy1 = 250;
  sy2 = 250;
  sbx1 = 100;
  sbx2 = 100;
  sby1 = 250;
  sby2 = 270;
  hdx1 = ;
  hdx2 = ;
  hdy1 = ;
  hdy2 = ;
  hdbx1 = ;
  hdbx2 = ;
  hdby1 = ;
  hdby2 = ;
  mbx1 = ;
  mbx2 = ;
  mby1 = ;
  mby2 = ;
  fwx = ;
  fwy = ;
  fwr = ;
  bwx = ;
  bwy = ;
  bwr = ;
}
*/
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
  return (int)(x*cos(r)-y*sin(r));
}

int rotatey(int x,int y, float r)
{
  return (int)(x*sin(r)+y*cos(r));
}
