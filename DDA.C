#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
void main()
{
 int x1,y1,x2,y2,dx,dxx,dy,dyy,L,xnew,ynew;//dont take -ve value
 int gd=DETECT,gm,i;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
// clrscr();
 printf("Enter the Coordinates of line");
 fflush(stdin);
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

 dx=(x2-x1);
 dy=(y2-y1);

  dxx=abs(dx);
  dyy=abs(dy);


 if(dxx>dyy)
 L=dxx;
 else
 L=dyy;

 printf("%d",L);
  dx=dx/L;
  dy=dy/L;

  xnew=x1+0.5;
  ynew=y1+0.5;
  putpixel(xnew,ynew,15);

  i=1;
  while(i<L)
  {
   xnew+=dx;
   ynew+=dy;
   putpixel(xnew,ynew,15);

  i++;
  }

 getch();
 closegraph();
}