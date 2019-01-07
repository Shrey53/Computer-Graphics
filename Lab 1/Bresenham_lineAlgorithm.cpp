#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>

using namespace std;



void Bresenham(float x0, float y0, float xn, float yn)
{
    float slope, dx, dy, ix=1, iy=1, p0;


    dx=fabs(xn-x0);
    dy=fabs(yn-y0);
    slope=(yn-y0)/(xn-x0);


    cout<<"x0"<<"\t"<<"y0"<<"\t"<<"(x0,y0)"<<endl;
    if(fabs(slope)<1)   //floating absolute
    {


        if (x0>xn)          // if xn<x0, decrement in x
            ix=-1;

        p0= 2*dy-dx;

        for(int i=0; i<dx; i++)
        {
            putpixel(x0,y0,RED);
            cout<<x0<<"\t"<<y0<<"\t"<<"("<<x0<<","<<y0<<")"<<endl;
            if(p0<0)
            {
                x0+=ix;
                p0 = p0 + 2*dy;
            }
            else
            {
                (yn<y0)?iy=-1:iy=1; //if slope=-ve and yn<y0, increment in y should be positive
                x0+=ix;
                y0+=iy;

                p0 = p0 + 2*dy - 2*dx;
            }
        }
    }

    else
    {

        p0= 2*dx-dy;

        if(yn<y0)
            iy=-1;

         for(int i=0; i<dy; i++)
        {
            putpixel(x0,y0,RED);
            cout<<x0<<"\t"<<y0<<"\t"<<"("<<x0<<","<<y0<<")"<<endl;
            if(p0<0)
            {
                y0+=iy;
                p0 = p0 + 2*dx;
            }
            else
            {
                (xn<x0)?ix=-1:ix=1;
                x0+=ix;
                y0+=iy;

                p0 = p0 + 2*dx - 2*dy;
            }
        }
    }

}
int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

//m==1
//    Bresenham(200,300,300,400);
//    Bresenham(300,300,50,50);
//    Bresenham(300,50,200,150);
//    Bresenham(100,200,250,50);

//for m<1
//    Bresenham(20,20,400,300);
//    Bresenham(200,50,100,120);
   Bresenham(50,260,200,220);
   // Bresenham(30,20,20,15);

    getch();

}
