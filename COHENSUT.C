#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

typedef struct coordinate
{
 int x,y;
 char code[4];
}PT;
PT resetendpt(PT,PT);
void drawwindow();
void drawline();
PT setcode(PT);
int visibility(PT,PT);
void main()
{
 PT p1,p2,p3,p4,temp;
 int v,i;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");

 printf("Enter the coordinates of line:\n");
 scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
 drawwindow();
 delay(500);
 drawline(p1,p2);
 delay(500);
 cleardevice();
delay(500);

p1=setcode(p1);
p2=setcode(p2);

for(i=0;i<4;i++)
printf("%c",p1.code[i]);
printf("\n");
for(i=0;i<4;i++)
printf("%c",p2.code[i]);

//for(i=0;i<4;i++)
//printf("%c",p2.code[i]);
v=visibility(p1,p2);
//printf("%d",v);
delay(500);
switch(v)
{
 case 0:drawwindow();	  //completely inside
		setcolor(RED);
		drawline(p1,p2);
		setcolor(WHITE);
		break;
 case 1:drawwindow();     //completely outside
		break;
 case 2:drawwindow();     //partially inside
		p3=resetendpt(p1,p2);
	   //	printf("\n%d %d\n",p3.x,p3.y);
		p4=resetendpt(p2,p1);
	   //	printf("%d %d",p4.x,p4.y);
	   setcolor(RED);
		drawline(p3,p4);
		break;
}

 getch();
 closegraph();
}

void drawwindow()
{
 rectangle(100,100,200,200);
}

void drawline(PT p1,PT p2)
{
  line(p1.x,p1.y,p2.x,p2.y);
}

PT setcode(PT p)   //setting the 4-bit code
{
  PT ptemp;

  if(p.y<100)
   ptemp.code[0]='1';   //top
   else
   ptemp.code[0]='0';
  if(p.y>200)
   ptemp.code[1]='1';   //bottom
   else
   ptemp.code[1]='0';
  if(p.x>200)
   ptemp.code[2]='1';   //right
   else
   ptemp.code[2]='0';
  if(p.x<100)
   ptemp.code[3]='1';   //left
   else
   ptemp.code[3]='0';

   ptemp.x=p.x;
   ptemp.y=p.y;

   return(ptemp);
}

int visibility(PT p1,PT p2)
{
 int i,flag=0;
 for(i=0;i<4;i++)
  if(p1.code[i]!=0 || p2.code[i]!=0)
  flag=1;

  if(flag==0)
   return 0;

   for(i=0;i<4;i++)
   if((p1.code[i]==p2.code[i]) && p1.code[i]==1)
	flag=0;

   if(flag==0)
   return 1;

  else
   return 2;
}

PT resetendpt(PT p1,PT p2)
{
	PT temp;
	int x,y,i;
	float m,k;
  // printf("Inside");
	if(p1.code[3]=='1')
	 x=100;
	if(p1.code[2]=='1')
	 x=200;

	if((p1.code[3]=='1') || (p1.code[2]=='1'))
	{
	// printf("Inside 1");
	 m=(float)(p2.y-p1.y)/(p2.x-p1.x);
	 k=(p1.y+(m*(x-p1.x)));
	 temp.x=x;
	 temp.y=k;

   //	 if(p1.code[3]=='1')
   //	 p1.code[3]='0';

   //	if(p1.code[2]=='1')
   //	p1.code[2]='0';
 //  printf("Temp%d %d\n",temp.x,temp.y);

	 for(i=0;i<4;i++)
	  temp.code[i]=p1.code[i];

	 if(temp.y<=200 && temp.y>=100)
	  return temp;
	}

	if(p1.code[1]=='1')
	  y=200;
	if(p1.code[0]=='1')
	  y=100;

	if(p1.code[0]=='1' || p1.code[1]=='1')
	{
   //	printf("Inside 2");
	 m=(float)(p2.y-p1.y)/(p2.x-p1.x);
	 k=(float)p1.x+(float)(y-p1.y)/m;
	 temp.x=k;
	 temp.y=y;

   //	 if(p1.code[0]=='1')
   //	 p1.code[0]='0';

   //	if(p1.code[1]=='1')
   //	  p1.code[1]='0';
  // printf("Temp2%d %d\n",temp.x,temp.y);

	 for(i=0;i<4;i++)
	  temp.code[i]=p1.code[i];

	 return temp;
	}
  else
	return p1;
}