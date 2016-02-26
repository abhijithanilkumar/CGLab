#include<stdio.h>
#include<graphics.h>

float x[16]={100,50,150,250,200,300,50,150,200,300};//,75,75,125,125,75,125};
float y[16]={50,125,125,25,100,100,225,225,200,200};//,175,225,175,225,175,175};

void draw_house()
{
  setlinestyle(0,0,NORM_WIDTH);
  line(x[0],y[0],x[1],y[1]);
  line(x[1],y[1],x[2],y[2]);
  line(x[2],y[2],x[0],y[0]);
  line(x[0],y[0],x[3],y[3]);
  line(x[2],y[2],x[5],y[5]);
  line(x[3],y[3],x[5],y[5]);
  line(x[1],y[1],x[6],y[6]);
  line(x[2],y[2],x[7],y[7]);
  line(x[5],y[5],x[9],y[9]);
  line(x[6],y[6],x[7],y[7]);
  line(x[7],y[7],x[9],y[9]);
  setlinestyle(DASHED_LINE,0,NORM_WIDTH);
  line(x[1],y[1],x[4],y[4]);
  line(x[4],y[4],x[5],y[5]);
  line(x[3],y[3],x[4],y[4]);
  line(x[4],y[4],x[8],y[8]);
  line(x[6],y[6],x[8],y[8]);
  line(x[8],y[8],x[9],y[9]);
  //line(x[10],y[10],x[11],y[11]);
  //line(x[12],y[12],x[13],y[13]);
  //line(x[14],y[14],x[15],y[15]);
}

void main()
{
  int gd = DETECT, gm;
  float shx,shy;
  int c,i;
  initgraph(&gd, &gm, NULL);

  printf("\nMENU:\n 1.X-Reflect\n 2.Y-Reflect\n 3.Shear\nEnter your choice: ");
  draw_house();
  scanf("%d",&c);
  switch(c)
  {
    case 1:
      for(i=0;i<16;i++)
        y[i]=450-y[i];
      draw_house();
      break;
    case 2:
      for(i=0;i<16;i++)
        x[i]=600-x[i];
      draw_house();
      break;
    case 3:
      printf("Enter the shear factor : ");
      scanf("%f",&shx);
      for(i=0;i<6;i++)
         x[i]+=y[i]*shx;
      //x[10]+=y[10]*shx;
      //x[12]+=y[12]*shx;
      draw_house();
      break;
  }
  delay(10000);
  closegraph();
}
