#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
void Bezier(int[],int[],int);
int fact(int);
void main()
{
 int x[20],y[20],n;
 int gd=DETECT,gm,i;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 printf("Enter the number of control points:\n");
 scanf("%d",&n);
 printf("Enter the x and y-coordinate of the control pt.\n");
 for(i=0;i<n;i++)
 {
  scanf("%d%d",&x[i],&y[i]);
 }
  Bezier(x,y,n);

  getch();
  closegraph();
}

void Bezier(int x[20],int y[20],int ctr_pt)
{
  double coeff[20];
  int i,n=ctr_pt-1,k;
  double j,xt,yt;
  for(i=0;i<ctr_pt;i++)                //computing coefficient
  {
   coeff[i]=(fact(n)/(fact(i)*fact(n-i)));
//   printf("%f",coeff[i]);

  }
  delay(100);
  //compting blend function
  for(j=0;j<=1;j+=0.0005)
  {

	double blend,t1,t2;
	 xt=0.0,yt=0.0;
	n=ctr_pt-1;

	for(k=0;k<ctr_pt;k++)
	 {
	   if(k==0)
	   t1=1;
	   else
	   t1=pow(j,k);
	   t2=pow(1-j,n-k);

	   blend=coeff[k]*t1*t2;

	   xt+=blend*x[k];
	   yt+=blend*y[k];

	 }
	 putpixel(xt,yt,WHITE);

  }
   for(i=0;i<ctr_pt;i++)
	putpixel(x[i],y[i],RED);

}

int fact(int n)
{
 if(n==0)
 return 1;
 else
 return n*fact(n-1);

}
