#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
void Bezier(int[],int[]);
void main()
{
 int i;
 int x[4],y[4];
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C://turboc3//bgi");
 printf("Enter the no. of 4 Control points");
 for(i=0;i<4;i++)
 scanf("%d%d",&x[i],&y[i]);
 Bezier(x,y);

 getch();
 closegraph();


}

void Bezier(int x[4],int y[4])
{
double i=0.0;
double xx,yy;

for(i=0.0;i<=1;i+=0.0005)
{
  xx=pow(1-i,3)*x[0]+3*i*pow(1-i,2)*x[1]+3*pow(i,2)*(1-i)*x[2]+pow(i,3)*x[3];
  yy=pow(1-i,3)*y[0]+3*i*pow(1-i,2)*y[1]+3*pow(i,2)*(1-i)*y[2]+pow(i,3)*y[3];;
  putpixel(xx,yy,WHITE);


}


}