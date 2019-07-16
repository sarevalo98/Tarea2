#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
double R(double x0,double y0)
    {
    double r1=sqrt(pow(x0,2)+pow(y0,2));
    return r1;
    }
double posicionx(double x0,double vx0)
    {
    return vx0;
    }
double aceleracionx(double x0,double vx0,double r0)
    {
    double Gx= (-1.98256*pow(10,-29));
    double Mx= 1.989*pow(10,30);
    double ax= Gx*Mx*x0/pow(r0,3);
    return ax;
    }
double posiciony(double y0,double vy0)
    {
    return vy0;
    }
double aceleraciony(double y0,double vy0,double r0)
    {
    double Gy= (-1.98256*pow(10,-29));
    double My= 1.989*pow(10,30);
    double ay= Gy*My*y0/pow(r0,3);
    return ay;
    }
double Euler(double h0,int num)
    {
    //Arrays
    double arrt[num];
    double arrx[num];
    double arry[num];
    double Vx[num];
    double Vy[num];
    double Rs[num];
    //Condiciones iniciales.
    arrt[0]=0.0;
    arrx[0]=0.1164;
    arry[0]=0.99772;
    Vx[0]= (-6.35);
    Vy[0]= 0.606;
    Rs[0]= sqrt(pow(arrx[0],2) + pow(arry[0],2));
    //Procedimiento
    for(int i=1;i<num;i++)
        {
        arrt[i]=arrt[i-1]+h0;
        arrx[i]=arrx[i-1]+h0*posicionx(arrx[i-1], Vx[i-1]);
        arry[i]=arry[i-1]+h0*posiciony(arry[i-1], Vy[i-1]);
        Vx[i]=Vx[i-1]+h0*aceleracionx(arrx[i-1],Vx[i-1],Rs[i-1]);
        Vy[i]=Vy[i-1]+h0*aceleraciony(arry[i-1],Vy[i-1],Rs[i-1]);
        Rs[i]=sqrt(pow(arrx[i],2) + pow(arry[i],2));
        }
    ofstream outfile;
    outfile.open("Euler.dat");
    for(int i=0;i<num;i++)
        {
        outfile<<arrt[i]<<" "<<arrx[i]<<" "<<Vx[i]<<" "<<arry[i]<<" "<<Vy[i]<<endl;
        }
    outfile.close();
    }
//Leap-Frog
double Leap(double h0,int num)
    {
    //Arrays
    double arrt1[num];
    double arrx1[num];
    double arry1[num];
    double Vx1[num];
    double Vy1[num];
    double Rs1[num];
    //Condiciones iniciales.
    arrt1[0]=0.0;
    arrx1[0]=0.1164;
    arry1[0]=0.99772;
    Vx1[0]= (-6.35);
    Vy1[0]= 0.606;
    Rs1[0]= sqrt(pow(arrx1[0],2) + pow(arry1[0],2));
    //condiciones primer paso.
    arrt1[1]=arrt1[0]+h0;
    arrx1[1]=arrx1[0]+h0*posicionx(arrx1[0], Vx1[0]);
    arry1[1]=arry1[0]+h0*posiciony(arry1[0], Vy1[0]);
    Vx1[1]=Vx1[0]+h0*aceleracionx(arrx1[0],Vx1[0],Rs1[0]);
    Vy1[1]=Vy1[0]+h0*aceleraciony(arry1[0],Vy1[0],Rs1[0]);
    Rs1[1]=sqrt(pow(arrx1[1],2) + pow(arry1[1],2));
    //Procedimiento
    for(int i=2;i<num;i++)
        {
        arrt1[i]=arrt1[i-1]+h0;
        arrx1[i]=arrx1[i-2]+2*h0*posicionx(arrx1[i-1], Vx1[i-1]);
        arry1[i]=arry1[i-2]+2*h0*posiciony(arry1[i-1], Vy1[i-1]);
        Vx1[i]=Vx1[i-2]+2*h0*aceleracionx(arrx1[i-1],Vx1[0],Rs1[i-1]);
        Vy1[i]=Vy1[i-2]+2*h0*aceleraciony(arry1[i-1],Vy1[i-1],Rs1[i-1]);
        Rs1[i]=sqrt(pow(arrx1[i],2) + pow(arry1[i],2));
        }
    ofstream outfile2;
    outfile2.open("LeapFrog.dat");
    for(int i=0;i<num;i++)
        {
        outfile2<<arrt1[i]<<" "<<arrx1[i]<<" "<<Vx1[i]<<" "<<arry1[i]<<" "<<Vy1[i]<<endl;
        }
    outfile2.close();
    }
int main()
    {
    int N=1000;
    double a=0.0;
    double b=1.0;
    double h=(b-a)/N;
    Euler(h,N);
    Leap(h,N);
    return 0;
    }