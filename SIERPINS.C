#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
void Sierpins(int,int,int,int,int,int,int);
void main()
{
int n;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
printf("Enter the ordeer:\n");
scanf("%d",&n);
Sierpins(300,300,500,300,400,150,n);


getch();
closegraph();
}

void Sierpins(int x1,int y1,int x2,int y2,int x3,int y3,int n)
{
int xa,ya,xb,yb,xc,yc;

xa=(x1+x2)/2;
ya=(y1+y2)/2;
xb=(x1+x3)/2;
yb=(y1+y3)/2;
xc=(x3+x2)/2;
yc=(y3+y2)/2;
	if(n>0)
	{
			Sierpins(x1,y1,xa,ya,xb,yb,n-1);
			Sierpins(xa,ya,x2,y2,xc,yc,n-1);
			Sierpins(xb,yb,xc,yc,x3,y3,n-1);

			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x1,y1);

	}

}