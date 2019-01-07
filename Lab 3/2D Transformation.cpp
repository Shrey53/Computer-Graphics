#include<iostream>
#include<graphics.h>
#include<cmath>
#include<conio.h>

#define pi 3.1415

using namespace std;

const int M=3;
const int N=1;

float glo[3][3]={{1,0,0}, {0,1,0}, {0,0,1}},  result[3][1], x[3][1]={1,1,1};


void multiply3x3(float  mat[M][M]) //3x3 mat
{
    float temp[3][3];

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i][j]=0;
            for(int k=0; k<3; k++)
            {
                temp[i][j]+=mat[i][k]*glo[k][j];
            }
        }
    }
    //copy to global matrix
    for(int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            glo[i][j]=temp[i][j];
}
void multiply3x1(float mat[M][N]) //3x1 mat
{
    //multiply the global matrix(3x3) with vertex(3x1) and store to global result matrix(3x1)
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<1; j++)
        {
            result[i][j]=0;
            for(int k=0; k<3; k++)
            {
                result[i][j]+=glo[i][k]*mat[k][j];
            }
        }
    }
}
void setIdentityMatrix(float mat[M][M])
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(i==j)
                mat[i][j]=1;
            else
                mat[i][j]=0;
}

//.........NOTE...............//
//multiply transformation matrix(any of below) with global matrix
//which will remain the same until other transformation operations are not carried,
//since, global matrix remains the same identity matrix
//if other transformation carried out, composite matrix will keep on forming

void translate(float tx, float ty)
{
    float mat[3][3]; //any 3x3 matrix of garbage value
    //set above matrix to identity
    setIdentityMatrix(mat);
    //change above matrix as translation matrix
    mat[0][2]=tx;
    mat[1][2]=ty;

    //multiply translational matrix with global matrix
    //which will remain same as translational matrix if other operations not carried,
    //since, global matrix remains the same identity matrix

    multiply3x3(mat);
}
void scale(float sx, float sy)
{
    float mat[3][3]; //any 3x3 matrix of garbage value
    //set above matrix to identity
    setIdentityMatrix(mat);
    //change above matrix as scaling matrix
    mat[0][0]=sx;
    mat[1][1]=sy;

    multiply3x3(mat);
}

void rotate(float angleDegree)
{
    float mat[3][3]; //any 3x3 matrix of garbage value
    //set above matrix to identity

    float angle;    //in radian

    setIdentityMatrix(mat);

    //set radian value
    angle=( angleDegree * pi ) / 180;
    //set rotational matrix
    mat[0][0]=cos(angle);
    mat[0][1]=-sin(angle);
    mat[1][0]=sin(angle);
    mat[1][1]=cos(angle);


    multiply3x3(mat);
}
void reflect()
{
    float m[3][3]; //any 3x3 matrix of garbage value
    //set above matrix to identity
    setIdentityMatrix(m);
    char ch;
    float slope, c;

    cout<<"enter 'x', 'y', 'o', or 'a' for reflection about x-axis, y-axis, origin or about line y=mx+c"<<endl;
    cin>>ch;
    if(ch=='a' | ch=='A')
    {
        cout<<"enter slope and intercpet for line y=mx+c"<<endl;
        cin>>slope>>c;
        m[0][0]= 1-slope*slope;
        m[0][1]= 2*slope;
        m[0][2]=-2*c*slope;
        m[1][0]= 2*slope;
        m[1][1]=slope*slope-1;
        m[1][2]=2*c;
        m[2][2]=1+slope*slope;

        multiply3x3(m);
        for(int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                glo[i][j] /= (1+slope*slope);
    }
    else
    {
        if(ch=='x' | ch=='X')
          m[1][1]=-1;
        else if (ch=='y' | ch=='Y')
          m[0][0]=-1;
        else if (ch=='o' | ch=='O')
          {
              m[0][0]=-1;
              m[1][1]=-1;
          }
        multiply3x3(m);
    }
}

void shearX(float shx)
{
    float m[3][3]; //any 3x3 matrix of garbage value

    setIdentityMatrix(m);

    m[0][1]= shx;
    multiply3x3(m);

}
void shearY(float shy)
{
    float m[3][3]; //any 3x3 matrix of garbage value

    setIdentityMatrix(m);

    m[1][0]= shy;
    multiply3x3(m);

}

//this function converts result matrix to x matrix
void finalTransformation(float vector3x1[M][N])
{
    //to transform vertices after forming composite matrix
    multiply3x1(vector3x1);
}

void transformRtoX(float a[][2],int t)
{
    x[0][0]=a[t][0];
    x[1][0]=a[t][1];
}

 //this function converts x matrix to x result
void transformXtoR(float a[][2],int t)
{
     a[t][0]=result[0][0];
     a[t][1]=result[1][0];
}

//this function draws the quadrant axes as well as shapes
void draw(int n,int Co,float r[][2])
{
    //for quadrant axes
    float maxx,maxy;
    maxx=getmaxx(); //getmaxx returns the maximum (screen-relative) x value for the
    maxy=getmaxy(); //getmaxx returns the maximum (screen-relative) Y value for the
    maxx/=2;
    maxy/=2;
    setcolor(15);
    line(0,maxy,maxx*2,maxy);
    line(maxx,0,maxx,maxy*2);

    //for shapes
    setcolor(Co);
    for(int i=0; i<n; i++)
    {
        if(i!=(n-1))
            line(maxx+r[i][0],maxy-r[i][1],maxx+r[i+1][0],maxy-r[i+1][1]);
        else
            line(maxx+r[i][0],maxy-r[i][1],maxx+r[0][0],maxy-r[0][1]);
    }
}

void complete(int n,float r[][2])
{
    for(int i=0; i<n; i++)
    {
        transformRtoX(r,i);
        finalTransformation(x);
        transformXtoR(r,i);
    }
}

int main()
{
    int gd=DETECT,gm;
    //initgraph(&gd,&gm,"C://TC//BGI");
    initwindow(1200,1000, "2D", NULL, NULL);

    float tx,ty,scx,scy,ra,shx,shy,slope,x_value,c;
    int n,i,j,cho,ch2;
    cout<<"Enter number of sides:";
    cin>>n;
    float r[n][2];

    for(i=0; i<n; i++)
    {
        cout<<"Enter x"<<i+1<<" and y"<<i+1<<":"<<endl;
        for (j=0; j<2; j++)
        {
            cin>>r[i][j];
        }
    }
    draw(n,2,r);
    //scale(2,2);
    //rotate(45);
    //scale(2,2);
    //translate(5,100);
    //shearX(4);
    //shearY(4);
    reflect();
    complete(n,r);
    draw(n,4,r);

      getch();

}

