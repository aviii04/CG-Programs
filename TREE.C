#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void tree(int,int,int,int,float);
void main()
{
 int x1,x2,y1,y2,n;
// float theta;
float angle=90*M_PI/180;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 printf("Enter the coordinate of trunk:\n");
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 printf("Enter the no. of branches:\n");
 scanf("%d",&n);
// theta=3.1416;
// printf("Enter the angle of inclination\n");
// scanf("%d",&theta);
//  printf("%f",theta);
 line(x1,y1,x2,y2);
 tree(x1,y1,n,y2-y1,angle);

 getch();
 closegraph();

}

void tree(int x,int y,int n,int l,float angle)
{
// float angle=90*M_PI/180;
 int x1=x+l*cos(angle+(20*M_PI/180));
 int y1=y-l*sin(angle+(20*M_PI/180));

 int x2=x+l*cos(angle-(20*M_PI/180));
 int y2=y-l*sin(angle-(20*M_PI/180));

 if(n>0)
 {
  tree(x1,y1,n-1,l*0.8,angle+(20*M_PI/180));
  tree(x2,y2,n-1,l*0.8,angle-(20*M_PI/180));



  line(x,y,x1,y1);
  line(x,y,x2,y2);
 }
// printf("%f",val);
}