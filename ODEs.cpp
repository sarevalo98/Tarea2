#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
double energia(double r0, double vx0, double vy0)
    {
    double G= (-1.98256*pow(10,-29))*1.989*pow(10,30);
    double m= (5.972*pow(10,24)/1.989*pow(10,30));
    double pot= (G*m)/r0;
    double cin= (1.0/2.0)*m*(pow(vx0,2)+pow(vy0,2));
    double ener= pot+cin;
    return ener;
    }
double momento(double r0)
    {
    double I=(2.0/5.0)*(5.972*pow(10,24)/1.989*pow(10,30))*r0;
    double W=(2.0*M_PI)/1.0;
    double E=I*W;
    return E;
    }
double posicionx(double x0,double vx0,double t0)
    {
    return vx0;
    }
double aceleracionx(double x0,double vx0,double r0,double t0)
    {
    double Gx= (-1.98256*pow(10,-29))*1.989*pow(10,30);
    double ax= Gx*x0/pow(r0,3.0);
    return ax;
    }
double posiciony(double y0,double vy0,double t0)
    {
    return vy0;
    }
double aceleraciony(double y0,double vy0,double r0,double t0)
    {
    double Gy= (-1.98256*pow(10,-29))*1.989*pow(10,30);
    double ay= Gy*y0/pow(r0,3.0);
    return ay;
    }
double Euler(double h0, string nombre)
    {
    int num=20.0/h0;
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
        arrx[i]=arrx[i-1]+h0*posicionx(arrx[i-1], Vx[i-1],arrt[i-1]);
        arry[i]=arry[i-1]+h0*posiciony(arry[i-1], Vy[i-1],arrt[i-1]);
        Vx[i]=Vx[i-1]+h0*aceleracionx(arrx[i-1],Vx[i-1],Rs[i-1],arrt[i-1]);
        Vy[i]=Vy[i-1]+h0*aceleraciony(arry[i-1],Vy[i-1],Rs[i-1],arrt[i-1]);
        Rs[i]=sqrt(pow(arrx[i],2) + pow(arry[i],2));
        }
    double momentum[num];
    for(int i=0;i<num;i++)
        {
        momentum[i]=momento(Rs[i]);
        }
    double energi[num];
    for(int i=0;i<num;i++)
        {
        energi[i]=energia(Rs[i], arrx[i],arry[i]);
        }
    ofstream outfile;
    outfile.open(nombre);
    for(int i=0;i<num;i++)
        {
        outfile<<arrt[i]<<" "<<arrx[i]<<" "<<Vx[i]<<" "<<arry[i]<<" "<<Vy[i]<<" "<<momentum[i]<<" "<<energi[i]<<endl;
        }
    outfile.close();
    }
//Leap-Frog
double Leap(double h0,string nombre)
    {
    int num=20.0/h0;
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
    arrx1[1]=arrx1[0]+h0*posicionx(arrx1[0], Vx1[0],arrt1[0]);
    arry1[1]=arry1[0]+h0*posiciony(arry1[0], Vy1[0],arrt1[0]);
    Vx1[1]=Vx1[0]+h0*aceleracionx(arrx1[0],Vx1[0],Rs1[0],arrt1[0]);
    Vy1[1]=Vy1[0]+h0*aceleraciony(arry1[0],Vy1[0],Rs1[0],arrt1[0]);
    Rs1[1]=sqrt(pow(arrx1[1],2) + pow(arry1[1],2));
    //Procedimiento
    for(int i=2;i<num;i++)
        {
        arrt1[i]=arrt1[i-1]+h0;
        arrx1[i]=arrx1[i-2]+2*h0*posicionx(arrx1[i-1], Vx1[i-1],arrt1[i-1]);
        arry1[i]=arry1[i-2]+2*h0*posiciony(arry1[i-1], Vy1[i-1],arrt1[i-1]);
        Vx1[i]=Vx1[i-2]+2*h0*aceleracionx(arrx1[i-1],Vx1[0],Rs1[i-1],arrt1[i-1]);
        Vy1[i]=Vy1[i-2]+2*h0*aceleraciony(arry1[i-1],Vy1[i-1],Rs1[i-1],arrt1[i-1]);
        Rs1[i]=sqrt(pow(arrx1[i],2) + pow(arry1[i],2));
        }
    double momentum1[num];
    for(int i=0;i<num;i++)
        {
        momentum1[i]=momento(Rs1[i]);
        }
    double energi1[num];
    for(int i=0;i<num;i++)
        {
        energi1[i]=energia(Rs1[i], arrx1[i],arry1[i]);
        }
    ofstream outfile2;
    outfile2.open(nombre);
    for(int i=0;i<num;i++)
        {
        outfile2<<arrt1[i]<<" "<<arrx1[i]<<" "<<Vx1[i]<<" "<<arry1[i]<<" "<<Vy1[i]<<" "<<momentum1[i]<<" "<<energi1[i]<<endl;
        }
    outfile2.close();
    }
//Runge-kutta.
double Runge(double h0,string nombre)
    {
    int num=20.0/h0;
    //Arrays
    double arrt2[num];
    double arrx2[num];
    double arry2[num];
    double Vx2[num];
    double Vy2[num];
    double Rs2[num];
    //Condiciones iniciales.
    arrt2[0]=0.0;
    arrx2[0]=0.1164;
    arry2[0]=0.99772;
    Vx2[0]= (-6.35);
    Vy2[0]= 0.606;
    Rs2[0]= sqrt(pow(arrx2[0],2) + pow(arry2[0],2));
    //variables K para los valores de X,Y,Vx y Vy.
    double kx1;
    double kx2;
    double kx3;
    double kx4;
    double ky1;
    double ky2;
    double ky3;
    double ky4;
    double kvx1;
    double kvx2;
    double kvx3;
    double kvx4;
    double kvy1;
    double kvy2;
    double kvy3;
    double kvy4;
    //Guardar promedios
    double promx;
    double promy;
    double promvx;
    double promvy;
    //Procedimiento
    for(int i=1;i<num;i++)
        {
        //K1
        kx1=h0*posicionx(arrx2[i-1],Vx2[i-1],arrt2[i-1]);
        ky1=h0*posiciony(arry2[i-1],Vy2[i-1],arrt2[i-1]);
        kvx1=h0*aceleracionx(arrx2[i-1],Vx2[i-1],Rs2[i-1],arrt2[i-1]);
        kvy1=h0*aceleraciony(arry2[i-1],Vy2[i-1],Rs2[i-1],arrt2[i-1]);
        
        //K2
        kx2=h0*posicionx(arrx2[i-1]+0.5*kx1,Vx2[i-1]+0.5*kvx1,arrt2[i-1]+0.5*h0);
        ky2=h0*posiciony(arry2[i-1]+0.5*ky1,Vy2[i-1]+0.5*kvy1,arrt2[i-1]+0.5*h0);
        kvx2=h0*aceleracionx(arrx2[i-1]+0.5*kx1,Vx2[i-1]+0.5*kvx1,Rs2[i-1],arrt2[i-1]+0.5*h0);
        kvy2=h0*aceleraciony(arry2[i-1]+0.5*ky1,Vy2[i-1]+0.5*kvy1,Rs2[i-1],arrt2[i-1]+0.5*h0);
        
        //K3
        kx3=h0*posicionx(arrx2[i-1]+0.5*kx2,Vx2[i-1]+0.5*kvx2,arrt2[i-1]+0.5*h0);
        ky3=h0*posiciony(arry2[i-1]+0.5*ky2,Vy2[i-1]+0.5*kvy2,arrt2[i-1]+0.5*h0);
        kvx3=h0*aceleracionx(arrx2[i-1]+0.5*kx2,Vx2[i-1]+0.5*kvx2,Rs2[i-1],arrt2[i-1]+0.5*h0);
        kvy3=h0*aceleraciony(arry2[i-1]+0.5*ky2,Vy2[i-1]+0.5*kvy2,Rs2[i-1],arrt2[i-1]+0.5*h0);
        
        //K4
        kx4=h0*posicionx(arrx2[i-1],Vx2[i-1],arrt2[i-1]);
        ky4=h0*posiciony(arry2[i-1],Vy2[i-1],arrt2[i-1]);
        kvx4=h0*aceleracionx(arrx2[i-1],Vx2[i-1],Rs2[i-1],arrt2[i-1]);
        kvy4=h0*aceleraciony(arry2[i-1],Vy2[i-1],Rs2[i-1],arrt2[i-1]);
        //Promedios
        promx=(1.0/6.0)*(kx1+2.0*kx2+2.0*kx3+kx4);
        promy=(1.0/6.0)*(ky1+2.0*ky2+2.0*ky3+ky4);
        promvx=(1.0/6.0)*(kvx1+2.0*kvx2+2.0*kvx3+kvx4);
        promvy=(1.0/6.0)*(kvy1+2.0*kvy2+2.0*ky3+kvy4);
        //Valores
        arrt2[i]=arrt2[i-1]+h0;
        arrx2[i]=arrx2[i-1]+promx;
        arry2[i]=arry2[i-1]+promy;
        Vx2[i]=Vx2[i-1]+promvx;
        Vy2[i]=Vy2[i-1]+promvy;
        Rs2[i]= sqrt(pow(arrx2[i],2) + pow(arry2[i],2));
        }
    double momentum2[num];
    for(int i=0;i<num;i++)
        {
        momentum2[i]=momento(Rs2[i]);
        }
    double energi2[num];
    for(int i=0;i<num;i++)
        {
        energi2[i]=energia(Rs2[i], arrx2[i],arry2[i]);
        }
    ofstream outfile3;
    outfile3.open(nombre);
    for(int i=0;i<num;i++)
        {
        outfile3<<arrt2[i]<<" "<<arrx2[i]<<" "<<Vx2[i]<<" "<<arry2[i]<<" "<<Vy2[i]<<" "<<momentum2[i]<<" "<<energi2[i]<<endl;
        }
    outfile3.close();
    }
int main()
    {
    double a=0.0;
    double h=0.01;
    double h1=0.005;
    double h2=0.001;
    Euler(h,"Euler.dat");
    Leap(h,"LeapFrog.dat");
    Runge(h,"RungeKutta.dat");
    Euler(h1,"Euler1.dat");
    Leap(h1,"LeapFrog1.dat");
    Runge(h1,"RungeKutta1.dat");
     Euler(h2,"Euler2.dat");
    Leap(h2,"LeapFrog2.dat");
    Runge(h2,"RungeKutta2.dat");
    return 0;
    }