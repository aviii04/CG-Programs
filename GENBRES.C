#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int sign(int);
void main()
{
 int x1,y1,x2,y2,x,y,dx,dy,signx,signy,exchange=0,temp;
 int gd=DETECT,gm,e,i;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 printf("Enter the coordinates of a line");
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 x=x1;y=y1;
 signx=sign(x2-x1);
 signy=sign(y2-y1);
 if(dy>dx)
 {
  temp=dy;
  dy=dx;
  dx=temp;
  exchange=1;

 }
 e=2*dy-dx;  //Initializing decision parameter
 putpixel(x,y,15);

 i=1;
 for(i=1;i<dx;i++)
 {
   while(e>0)
   {
	if(exchange==1)
	 x+=signx;
	else
	 y+=signy;
	e-=2*dx;
   }
  if(exchange==1)
   y+=signy;
  else
   x+=signx;
  e+=2*dy;
  putpixel(x,y,15);


 }



 getch();
 closegraph();
}

int sign(int x)
{
   if(x==0)
   return 0;
   return (x>0?1:-1);

}