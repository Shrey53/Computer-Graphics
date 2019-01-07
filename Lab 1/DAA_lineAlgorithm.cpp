#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<iostream>

using namespace std;


void DAA(float x0, float y0, float xn, float yn)
{
    float slope, dx, dy, ix, iy, steps;
    int a,b;

    dx=xn-x0;
    dy=yn-y0;
    slope=dy/dx;

    if(fabs(dx)>fabs(dy))
        steps=fabs(dx);
    else
        steps= fabs(dy);

    ix= dx/steps;
    iy= dy/steps;   //dy/steps=dy/dx=m if m<1

    cout<<"x"<<"\t"<<"y"<<"\t"<<"(x,y)"<<endl;
    for(int i=0; i<=steps; i++)
    {
        (x0-int(x0)<0.5)?a=floor(x0):a=ceil(x0);
        (y0-int(y0)<0.5)?b=floor(y0):b=ceil(y0);
        cout<<a<<"\t"<<b<<"\t"<<"("<<a<<","<<b<<")"<<endl;
        putpixel(a,b, WHITE);

        x0+=ix;
        y0+=iy;
    }


}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

//for m==1
//    DAA(200,300,300,400);
//    DAA(300,300,50,50);
//    DAA(300,50,200,150);
//    DAA(100,200,250,50);
//
////for m<1
//    DAA(20,20,400,300);
//    DAA(200,50,100,120);
//    DAA(50,260,200,220);
//    DAA(300,200,100,150);

    DAA(30,20,20,15);

    getch();

}

