#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
void midcircle(int,int,int);
void boundaryf(int,int,int,int);
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
 boundaryf(x,y,15,2);
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
   putpixel(x0+x,y0+y,15);
   putpixel(x0+y,y0+x,15);
   putpixel(x0+y,y0-x,15);
   putpixel(x0+x,y0-y,15);
   putpixel(x0-x,y0-y,15);
   putpixel(x0-y,y0-x,15);
   putpixel(x0-y,y0+x,15);
   putpixel(x0-x,y0+y,15);
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

void boundaryf(int x,int y,int b_col,int f_col)
{
 if(getpixel(x,y)!=b_col && getpixel(x,y)!=f_col)
 {
  putpixel(x,y,f_col);
  boundaryf(x+1,y,b_col,f_col);
  boundaryf(x,y+1,b_col,f_col);
  boundaryf(x-1,y,b_col,f_col);
  boundaryf(x,y-1,b_col,f_col);
 }
}