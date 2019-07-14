#include <fstream>
#include<iostream>
using namespace std;
double funcion(double x0,double t0,double vx0,double y0, double vy0)
    {
    return v0;
    }
double veloci(double x0,double t0,double vx0,double y0, double vy0)
    {
    double G=pow(6.674*10,-11);
    double M=pow(1.989*10,30);
    }
double runge(double a0, double b0, double h0, int num)
    {
    double arrt[num];
    arrt[0]=a0;
    double k1;
    double k2;
    double k3;
    double k4;
    double prom;
    double arrx[num];
    arrx[0]=0.1;
    double k1v;
    double k2v;
    double k3v;
    double k4v;
    double promv;
    double arrv[num];
    arrv[0]=0.0;
    for(int i=1; i<=num;i++)
        {
        k1=h0 * funcion(arrx[i-1],arrt[i-1],arrv[i-1]);
        k1v=h0 * veloci(arrx[i-1],arrt[i-1],arrv[i-1]);
        k2=h0 * funcion(arrx[i-1]+0.5*k1,arrt[i-1]+0.5*k1,arrv[i-1]+0.5*k1);
        k2v=h0 * veloci(arrx[i-1]+0.5*k1v,arrt[i-1]+0.5*k1v,arrv[i-1]+0.5*k1v);
        k3=h0 * funcion(arrx[i-1]+0.5*k2,arrv[i-1]+0.5*k2,arrv[i-1]+0.5*k2);
        k3v=h0 * veloci(arrx[i-1]+0.5*k2v,arrv[i-1]+0.5*k2v,arrv[i-1]+0.5*k2v);
        k4=h0 * funcion(arrx[i-1]+k3,arrt[i-1]+k3,arrv[i-1]+k3);
        k4v=h0 * veloci(arrx[i-1]+k3v,arrt[i-1]+k3v,arrv[i-1]+k3v);
        prom=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
        promv=(1.0/6.0)*(k1v+2.0*k2v+2.0*k3v+k4v);
        arrt[i]=arrt[i-1]+h0;
        arrx[i]=arrx[i-1]+prom;
        arrv[i]=arrv[i-1]+promv;
        }
    ofstream outfile;
    outfile.open("runge.dat");
    for(int i=0;i<=num;i++)
        {
        outfile <<arrt[i]<<";"<<arrx[i]<<";"<<arrv[i]<< endl;
        }
    outfile.close();
    for(int i=0;i<=num;i++)
        {
        cout <<arrt[i]<<";"<<arrv[i]<<";"<<arrx[i]<< endl;
        }
    }
int main()
    {
    double a=0.0;
    double b=5.0;
    double h=0.01;
    int puntos=(b-a)/h;
    runge(a,b,h,puntos);
    return 0;
    }