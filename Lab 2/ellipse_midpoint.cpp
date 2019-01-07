#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

void shift_ellipse(float xc,float yc, float x, float y)
{
    putpixel(xc+x, yc-y,9);
    cout<<xc+x<<"\t"<<yc-y<<endl;
    putpixel(xc-x, yc-y,5);
    cout<<xc-x<<"\t"<<yc-y<<endl;
    putpixel(xc+x, yc+y,5);
    cout<<xc+x<<"\t"<<yc+y<<endl;
    putpixel(xc-x, yc+y,5);
    cout<<xc-x<<"\t"<<yc+y<<endl;
//    putpixel(xc+y, yc+x,5);
//    putpixel(xc-y, yc+x,5);
//    putpixel(xc+y, yc-x,5);
//    putpixel(xc-y, yc-x,5);
}

void midpoint_ellipse(float rx,float ry, float xc,float yc)
{
    float x0=0, y0=ry, p0;

    p0= (ry*ry) - (rx*rx*ry) +((rx*rx)/4) ;  //for region 1


    while(2*x0*ry*ry<=2*y0*rx*rx)
    {
        shift_ellipse(xc,yc,x0,y0);
        delay(15);
        //putpixel(x0,y0,WHITE);
        x0+=1;

        if(p0<0)
            p0+=(2*ry*ry*x0) +(ry*ry);
        else
        {
            y0--;
            p0+=(2*ry*ry*x0+ry*ry)-(2*rx*rx*y0);

        }

    }
    p0= ry*ry*(x0+0.5)*(x0+0.5)+rx*rx*(y0-1)*(y0-1)-rx*rx*ry*ry;

    while(y0>=0)
    {
        shift_ellipse(xc,yc,x0,y0);
        delay(15);
        //putpixel(x0,y0,WHITE);
        y0--;

        if(p0<0)
        {
            x0++;
            p0+=(2*ry*ry*x0)-(2*rx*rx*y0)-(rx*rx);
        }

        else
        {
            p0-=(2*rx*rx*y0)+(rx*rx);

        }

    }

}


int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    midpoint_ellipse(10,15,100,200);


    getch();
}
