#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void midcircle(int,int,int);
void floodf(int,int,int,int);
void main()
{
 int r,x,y;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 printf("Enter the radius of circle");
 scanf("%d",&r);
 printf("\nter the x and y coordinate of circle:");
 scanf("%d%d",&x,&y);
 midcircle(x,y,r);

 floodf(x,y,0,2);

 getch();
 closegraph();
}

void midcircle(int x0,int y0,int r)
{
 int x=0;
 int y=r;
 int pk=(5/4)-r;

 while(x<=y)
 {
   putpixel(x0+x,y0+y,7);
   putpixel(x0+y,y0+x,7);
   putpixel(x0+y,y0-x,7);
   putpixel(x0+x,y0-y,7);
   putpixel(x0-x,y0-y,7);
   putpixel(x0-y,y0-x,7);
   putpixel(x0-y,y0+x,7);
   putpixel(x0-x,y0+y,7);
   if(pk<0)
	pk=pk+2*x+3;
   else
	{
	 pk=pk+2*(x-y)+5;
	 y-=1;
	}
	x+=1;
 }
}

void floodf(int x,int y,int oldc,int newc)
{
 if(getpixel(x,y)==oldc)   //getpixel() gives colour of specified pixel
 {
  putpixel(x,y,newc);
  floodf(x+1,y,oldc,newc);
  floodf(x,y+1,oldc,newc);
  floodf(x-1,y,oldc,newc);
  floodf(x,y-1,oldc,newc);
 }

}