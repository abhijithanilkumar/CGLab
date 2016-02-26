#include<graphics.h>
#include<stdio.h>
#define pi 3.14

int originx, originy;

void drawfront()
{
  int face1[]={100,100,150,150,150,250,100,200,100,100};
  int face2[]={100,100,200,100,250,150,150,150,100,100};
  int face3[]={150,150,250,150,250,250,150,250,150,150};

  setcolor(RED);
  fillpoly(5, face1);
  setcolor(GREEN);
  fillpoly(5, face2);
  setcolor(YELLOW);
  fillpoly(5, face3);

  setcolor(BLACK);
  setlinestyle(1,0,1);
  line(100,200,200,200);
  line(200,100,200,200);
  line(200,200,250,250);
}
void drawback()
{
    int face1[]={100,100,200,100,200,200,100,200,100,100};
    int face2[]={100,200,200,200,250,250,150,250,100,200};
    int face3[]={200,100,250,150,250,250,200,200,200,100};

    setcolor(BLUE);
    fillpoly(5, face1);
    setcolor(BROWN);
    fillpoly(5, face2);
    setcolor(WHITE);
    fillpoly(5, face3);

    setcolor(BLACK);
    line(100,100,150,150);
    line(150,150,250,150);
    line(150,150,150,250);
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

void rotate(int angle)
{
  float r = angle*((2*pi)/360);
  int f1x1,f1x2,f1x3,f1y1,f1y2,f1y3,f1x4,f1y4,poly1[10];
  originx = 175;
  originy = 125;
  f1x1 = rotatex(100,100,r);
  f1y1 = rotatey(100,100,r);
  f1x2 = rotatex(200,100,r);
  f1y2 = rotatey(200,100,r);
  f1x3 = rotatex(250,150,r);
  f1y3 = rotatey(250,150,r);
  f1x4 = rotatex(150,150,r);
  f1y4 = rotatey(150,150,r);
  poly1[0] = f1x1;
  poly1[1] = f1y1;
  poly1[2] = f1x2;
  poly1[3] = f1y2;
  poly1[4] = f1x3;
  poly1[5] = f1y3;
  poly1[6] = f1x4;
  poly1[7] = f1x4;
  poly1[8] = f1x1;
  poly1[9] = f1y1;
  int f2x1,f2x2,f2x3,f2y1,f2y2,f2y3,f2x4,f2y4,poly2[10];
  originx = 175;
  originy = 225;
  f2x1 = rotatex(100,200,r);
  f2y1 = rotatey(100,200,r);
  f2x2 = rotatex(200,200,r);
  f2y2 = rotatey(200,200,r);
  f2x3 = rotatex(250,250,r);
  f2y3 = rotatey(250,250,r);
  f2x4 = rotatex(150,250,r);
  f2y4 = rotatey(150,250,r);
  //printf("%d%d",f2x4,f2y4);
  poly2[0] = f2x1;
  poly2[1] = f2y1;
  poly2[2] = f2x2;
  poly2[3] = f2y2;
  poly2[4] = f2x3;
  poly2[5] = f2y3;
  poly2[6] = f2x4;
  poly2[7] = f2y4;
  poly2[8] = f2x1;
  poly2[9] = f2y1;
  setcolor(WHITE);
  setlinestyle(0,0,0);
  drawpoly(5,poly1);
  drawpoly(5,poly2);
  line(f2x1,f2y1,f1x1,f1y1);
  line(f2x2,f2y2,f1x2,f1y2);
  line(f2x3,f2y3,f1x3,f1y3);
  line(f2x4,f2y4,f1x4,f1y4);
}

int main()
{
   int gd = DETECT, gm, c;
   int poly1[]={100,100,150,150,150,250,100,200,100,100};
   int poly2[]={200,100,250,150,250,250,200,200,200,100};
   initgraph(&gd, &gm, NULL);


   rectangle(100,100,200,200);
   rectangle(150,150,250,250);
   drawpoly(5, poly1);
   drawpoly(5, poly2);

   drawfront();

   printf("MENU \n 1.Front\n 2.Back\n 3.Rotate\nEnter your Choice : ");
   scanf("%d",&c);

   switch(c)
   {
     case 1:
        drawfront();
        break;
     case 2:
        drawback();
        break;
     case 3:
        cleardevice();
        rotate(30);
        break;
   }

   getch();
   closegraph();
   return 0;
}
