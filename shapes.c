#include<graphics.h>

main()
{
   int gd = DETECT,gm,left=300,top=200,right=350,bottom=250,x= 300,y=150,radius=50;
   int i,j=0;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   while(1)
   {
       for(i=0;i<150;i+=10,++j)
       {
         rectangle(left, top+i, right, bottom+i);
         rectangle(left, top-i, right, bottom-i);
         rectangle(left+i, top, right+i, bottom);
         rectangle(left-i, top, right-i, bottom);
         rectangle(left+i, top+i, right+i, bottom+i);
         rectangle(left-i, top-i, right-i, bottom-i);
         rectangle(left+i, top-i, right+i, bottom-i);
         rectangle(left-i, top+i, right-i, bottom+i);
         delay(100);
         setcolor(j%14+1);
         cleardevice();
       }
       for(i=150;i>=0;i-=10,++j)
       {
         rectangle(left, top+i, right, bottom+i);
         rectangle(left, top-i, right, bottom-i);
         rectangle(left+i, top, right+i, bottom);
         rectangle(left-i, top, right-i, bottom);
         rectangle(left+i, top+i, right+i, bottom+i);
         rectangle(left-i, top-i, right-i, bottom-i);
         rectangle(left+i, top-i, right+i, bottom-i);
         rectangle(left-i, top+i, right-i, bottom+i);
         delay(100);
         setcolor(j%15);
         cleardevice();
       }
     }
   //circle(x, y, radius);
   /*bar(left + 300, top, right + 300, bottom);
   line(left - 10, top + 150, left + 410, top + 150);
   ellipse(x, y + 200outtextxy(left + 100, top + 325, "My First C Graphics Program");outtextxy(left + 100, top + 325, "My First C Graphics Program");outtextxy(left + 100, top + 325, "My First C Graphics Program");, 0, 360, 100, 50);*/

   getch();
   closegraph();
   return 0;
}
