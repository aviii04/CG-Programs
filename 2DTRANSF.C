#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
void Translation();
void Scaling();
void Rotation();
void Shear();
void Reflection();
float x1=60,x2=100,x3=100,x4=60; //Rectangle Coordinates
float y1=60,y2=60,y3=100,y4=100;
float x11,x22,x33,x44;
float y11,y22,y33,y44;
void main()
{
int choice,n;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
printf("Enter your Choice\n");
rectangle(60,60,100,100);
printf("1.Translation\n2.Scaling\n3.Rotation\n4.Shear\n5.Reflectionn\n7.Exit");
scanf("%d",&choice);
switch(choice)
 {
   case 1:Translation();
   break;
   case 2:Scaling();
   break;
   case 3:Rotation();
   break;
   case 4:Shear();
   break;
   case 5:Reflection();
   break;
   case 7:printf("Exit");
   break;


 }
 getch();
 closegraph();

}

void Translation()
{
 int tx,ty,x,y;
  cleardevice();
  x=getmaxx()/2;
  y=getmaxy()/2;
  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
  line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 rectangle(x+60,y-60,x+100,y-100);
 printf("Enter the Translation Factor\n");
 scanf("%d%d",&tx,&ty);
 x11=x+(x1+tx);
 x33=x+(x3+tx);
 y11=y-(y1+ty);
 y33=y-(y3+ty);
 rectangle(x11,y11,x33,y33);
}

void Scaling()
{
 float sx,sy;
 int x,y;
  cleardevice();
  x=getmaxx()/2;
  y=getmaxy()/2;
  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
  line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 rectangle(x+60,y-60,x+100,y-100);
 printf("Enter the Scaling Factor\n");
 scanf("%f%f",&sx,&sy);
 x11=x+(x1*sx);
 x33=x+(x3*sx);
 y11=y-(y1*sy);
 y33=y-(y3*sy);
 rectangle(x11,y11,x33,y33);
}

void Rotation()
{
  int x,y,t;
  float r;
   cleardevice();
  x=getmaxx()/2;
  y=getmaxy()/2;
  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
  line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 rectangle(x+60,y-60,x+100,y-100);
 printf("Enter the Angle of Rotation\n");
 scanf("%d",&t);
 r=3.14*t/180;
 x11=x+(abs(x1*cos(r)-y1*sin(r)));
 x22=x+(abs(x2*cos(r)-y2*sin(r)));
 x33=x+(abs(x3*cos(r)-y3*sin(r)));
 x44=x+(abs(x4*cos(r)-y4*sin(r)));
 y11=y-(abs(x1*sin(r)+y1*cos(r)));
 y22=y-(abs(x2*sin(r)+y2*cos(r)));
 y33=y-(abs(x3*sin(r)+y3*cos(r)));
 y44=y-(abs(x4*sin(r)+y4*cos(r)));

 line(x11,y11,x22,y22);
 line(x22,y22,x33,y33);
 line(x33,y33,x44,y44);
 line(x44,y44,x11,y11);

// rectangle(x11,y11,x33,y33);
}

void Shear()
{
 float sx,sy,x,y;
 int choice;
  cleardevice();
  x=getmaxx()/2;
  y=getmaxy()/2;
  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
  line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 rectangle(x+60,y-60,x+100,y-100);
 printf("Choose the Shear direction\n");
 printf("1.X-Shear\n2.Y-Shear\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:printf("Enter the X-shear value:\n");
		 scanf("%f",&sx);
		 y11=y-(y1);
		 y22=y-(y2);
		 y33=y-(y3);
		 y44=y-(y4);
		 x11=x1+(sx*y1);
		 x22=x2+(sx*y2);
		 x33=x3+(sx*y3);
		 x44=x4+(sx*y4);
  break;
  case 2:printf("Enter the Y-shear value:\n");
		 scanf("%f",&sy);
		 x11=x+(x1);
		 x22=x+(x2);
		 x33=x+(x3);
		 x44=x+(x4);
		 y11=y-(y1+sy*x1);
		 y22=y-(y2+sy*x2);
		 y33=y-(y3+sy*x3);
		 y44=y-(y4+sy*x4);
  break;
 }
 line(x11,y11,x22,y22);
 line(x22,y22,x33,y33);
 line(x33,y33,x44,y44);
 line(x44,y44,x11,y11);
}

void Reflection()
{
 int choice,x,y;
  cleardevice();
  x=getmaxx()/2;
  y=getmaxy()/2;
  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
  line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 rectangle(x+60,y-60,x+100,y-100);
  printf("Enter your choice\n1.About X-axis\n2.About Y-axis\n3.About origin(X-Y plane)\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:x11=(x+x1);
		 x22=(x+x2);
		 x33=(x+x3);
		 x44=(x+x4);
		 y11=(y+y1);
		 y22=(y+y2);
		 y33=(y+y3);
		 y44=(y+y4);

   break;
   case 2:x11=(x-x1);
		 x22=(x-x2);
		 x33=(x-x3);
		 x44=(x-x4);
		 y11=(y-y1);
		 y22=(y-y2);
		 y33=(y-y3);
		 y44=(y-y4);
   break;
   case 3:
		 x11=(x-x1);
		 x22=(x-x2);
		 x33=(x-x3);
		 x44=(x-x4);
		 y11=(y+y1);
		 y22=(y+y2);
		 y33=(y+y3);
		 y44=(y+y4);
   break;

  }

 line(x11,y11,x22,y22);
 line(x22,y22,x33,y33);
 line(x33,y33,x44,y44);
 line(x44,y44,x11,y11);

}