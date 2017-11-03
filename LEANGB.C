#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm;
 int x1,x2,y1,y2,xmin,xmax,ymin,ymax;
 int flag2=0,flag1=0;
 float q[4],p[4],dx,dy,i,xx1,xx2,yy1,yy2;
 float t1,t2,t[4];
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
// int x1,x2,y1,y2,xmin,xmax,ymin,ymax;
// float t1,t2,t[4];
 printf("Enter the cordinates of line");
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 line(x1,y1,x2,y2);
 printf("Enter the lower coordinate of window");
 scanf("%d%d",&xmin,&ymin);
 printf("Enter the upper coordinate of window");
 scanf("%d%d",&xmax,&ymax);
 rectangle(xmin,ymin,xmax,ymax);
 dx=x2-x1;
 dy=y2-y1;
 p[0]=-dx;
 p[1]=dx;
 p[2]=-dy;
 p[3]=dy;
 q[0]=x1-xmin;
 q[1]=xmax-x1;
 q[2]=y1-ymin;
 q[3]=ymax-y1;
 for(i=0;i<4;i++)
 {
  if(p[i]!=0)
  {
   t[i]=(float)q[i]/p[i];
  }
  else
  { flag1=1;// printf("Line is parallel to one of the clipping boundary");
   if(q[i]<0)
   {// flag2=1;
  //	printf("Line is completely outside the window");
   }
   if(q[i]>=0)
   {  if(i<2)
	  {
	   if(y1<ymin)
		y1=ymin;
	   if(y2>ymax)
	   y2=ymax;
	   setcolor(RED);
	   line(x1,y1,x2,y2);
	  }
	  if(i>1)
	  {
	   if(x1<xmin)
		x1=xmin;
	   if(x2>xmax)
		x2=xmax;
		setcolor(RED);
		line(x1,y1,x2,y2);
	  }
   }
  }
 }
 t1=0;t2=1;
 for(i=0;i<4;i++)
 {
	if(p[i]<0)
	{
	 if(t1<t[i])
	 t1=t[i];
	}
	else
	{
	 if(t2>t[i])
	 t2=t[i];
	}
 }
 if(t1<t2)
 {
  xx1=x1+t1*dx;
  xx2=x1+t2*dx;
  yy1=y1+t1*dy;
  yy2=y1+t2*dy;
  setcolor(RED);
  line(xx1,yy1,xx2,yy2);
 }
 if(flag1==1)
 printf("Line is parallel to one of the boundary");
 if(flag2==1);
 printf("Line is completely outside the window");
 getch();
 closegraph();

}