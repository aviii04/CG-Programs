//Using Sutherland Hodgeman Algo.
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>

void clip(float,float,float);
int j=0;
int x1,x2,y1,y2;
int x3[8],y3[8];
void main()
{
 int x[8],y[8];
 int i,n;
 float m;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 printf("Enter the top left and bottom right corner of clipping window");
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 printf("Enter the no. of sides of polygon\n");
 scanf("%d",&n);
 printf("Enter the coordinates of polygon");
 for(i=0;i<n;i++)
 {
  scanf("%d%d",&x[i],&y[i]);

 }
 rectangle(x1,y1,x2,y2);
 for(i=0;i<n-1;i++)
  line(x[i],y[i],x[i+1],y[i+1]);
  line(x[i],y[i],x[0],y[0]);

  for(i=0;i<n-1;i++)
  {
	m=(y[i+1]-y[i])/(x[i+1]-x[i]);
	clip(x[i],y[i],m);
	clip(x[i+1],y[i+1],m);
  }
  m=(y[i]-y[0])/(x[i]-x[0]);
	clip(x[i],y[i],m);
	clip(x[0],y[0],m);
 setcolor(RED);
  for(i=0;i<j-1;i++)
  line(x3[i],y3[i],x3[i+1],y3[i+1]);


  getch();
  closegraph();
}

void clip(float x,float y,float m)
{
  while(x<x1 || x>x2 || y<y1 || y>y2)
  {
	if(x<x1)
	{
	  y+=m*(x1-x);
	x=x1;
	}
	else if(x>x2)
	{
	  y+=m*(x2-x);
	  x=x2;

	}
	else if(y<y1)
	{
	  x+=(y1-y)/m;
	  y=y1;

	}
	else if(y>y2)
	{
	  x+=(y2-y)/m;
	  y=y2;
	}
  }
		x3[j]=x;
	y3[j]=y;
	j++;

}