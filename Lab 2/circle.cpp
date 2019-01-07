#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

void shift_circle(float xc,float yc, float x, float y)
{
    putpixel(xc+x, yc-y,5);
    cout<<xc+x<<"\t"<<yc-y<<endl;

    putpixel(xc+x, yc+y,5);
    cout<<xc+x<<"\t"<<yc+y<<endl;

    putpixel(xc-x, yc+y,5);
    cout<<xc-x<<"\t"<<yc+y<<endl;

    putpixel(xc-x, yc-y,5);
    cout<<xc-x<<"\t"<<yc-y<<endl;

    putpixel(xc+y, yc+x,5);
    cout<<xc+y<<"\t"<<yc+x<<endl;

    putpixel(xc-y, yc+x,5);
    cout<<xc-y<<"\t"<<yc+x<<endl;

    putpixel(xc+y, yc-x,5);
    cout<<xc+y<<"\t"<<yc-x<<endl;

    putpixel(xc-y, yc-x,5);
    cout<<xc-y<<"\t"<<yc-x<<endl;
}

void midpoint_circle(float radius, float xc,float yc)
{
    float x0=0, y0=radius, p0;

    p0= 5/4-radius;


    while(x0<=y0)
    {
        shift_circle(xc,yc,x0,y0);
        //delay(15);
        //putpixel(x0,y0,WHITE);
        x0+=1;

        if(p0<0)
            p0+=2*x0+2+1;
        else
        {
            p0+=2*x0+2+1-2*y0+2;
            y0--;

        }

    }

}


int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    midpoint_circle(10,300,250);


    getch();
}
