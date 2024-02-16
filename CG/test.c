#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
  int gd = DETECT, gm;
  int x1, u1, x2, y2, stepsize, dx, dy, i;
  float x, y, xinc, yinc;
  initgraph(&gd, &gm, "c:\\tc\\bgi");
  printf("Digital Differential Line Drawing Algorithm");
  printf("put the values of x1 and y1\n");
  scanf("%d %d", &x1, &y1);
  printf("put the values of x2 and y2\n");
  scanf("%d %d", &x2, &y2);
  dx=x2-x1;
  dy=y2-y1;
  x=x1;
  y=y1;
  if(abs(dy)>abs(dx))
  {
    stepsize=abs(dy);
  }
  else {
    stepsize=abs(dx);
  }
  xinc=dx/(float)stepsize;
  yinc=dy/(float)stepsize;
  putpixel(x,y,RED);
  for(i=0;i<stepsize;i++)
  {
    x=x+xinc;
    y=y+yinc;
    putpixel((int)(x+0.5),(int)(y+0.5),RED);
  }
  getch();
  closegraph();
}

