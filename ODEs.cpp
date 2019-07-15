#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
//Función para calcular el momento angular.
double Angularx(double x0,double y0, double t0, double vx0, double vy0)
    {
    double m=3.002513826*pow(10,-6);//Masa de la tierra en Masas solares
    double R=pow(pow(x0,2)+pow(y0,2),1/2);
    double L=R*m*vx0;
    return L;
    }
double Angulary(double x0,double y0, double t0, double vx0, double vy0)
    {
    double m=3.002513826*pow(10,-6);//Masa de la tierra en Masas solares
    double R=pow(pow(x0,2)+pow(y0,2),1/2);
    double L=R*m*vy0;
    return L;
    }
//Funciones que reciben por parametro las velocidades de X y Y (respectivamente) y retornan lo necesario para el metodo de Runge Kutta de cuarto orden.
double velocix(double x0,double y0, double t0, double vx0, double vy0)
    {
     return vx0;
    }
double velociy(double x0,double y0, double t0, double vx0, double vy0)
    {
     return vy0;
    }
//Funciones para calcular la aceleracion de X y Y aplicando la formula de ley de atraccion universal.
double funcionx(double x0,double y0, double t0, double vx0, double vy0)
    {
    double G=4.420995153*pow(10,68);//Constante gravitacional universal en Masas solares, años y UA.
    double M=1.989*pow(10,30);
    double R=pow(pow(x0,2)+pow(y0,2),1/2);
    double a=(-G*M*x0)/R;
    return a;
    }
double funciony(double x0,double y0, double t0, double vx0, double vy0)
    {
    double G=4.420995153*pow(10,68);//Constante gravitacional universal en Masas solares, años y UA.
    double M=1.989*pow(10,30);
    double R=pow(pow(x0,2)+pow(y0,2),1/2);
    double a=(-G*M*y0)/R;
    return a;
    }
//Metodo de Leap-Frog.
double Leap(double a0,double h0, int num)
    {
    //Arrays para las posiciones de X, Y, T y las veloscidades en X y Y.
    double arrt[num];
    double arrx[num];
    double arry[num];
    double velox[num];
    double veloy[num];
    //Condiciones iniciales de los array.
    arrt[0]=a0;
    arrx[0]=0.1163;
    arry[0]=0.9772;
    velox[0]=-6.35;
    veloy[0]=0.606;
    //Condiciones primera posición.
    arrt[1]=arrt[0]+h0;
    arrx[1]=arrx[0]+h0 * funcionx(arrx[0],arry[0],arrt[0],velox[0],veloy[0]);
    arry[1]=arry[0]+h0 * funciony(arrx[0],arry[0],arrt[0],velox[0],veloy[0]);
    velox[1]=velox[0]+h0*velocix(arrx[0],arry[0],arrt[0],velox[0],veloy[0]);
    veloy[1]=veloy[0]+h0*velociy(arrx[0],arry[0],arrt[0],velox[0],veloy[0]);
    //Procedimiento.
    for(int i=2; i<=num;i++)
        {
        arrt[i]=arrt[i-1]+h0;
        arrx[i]=arrx[i-2]+2.0*h0 * funcionx(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        arry[i]=arry[i-2]+2.0*h0 * funciony(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        velox[i]=velox[i-2]+2.0*h0*velocix(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        veloy[i]=veloy[i-2]+2.0*h0*velociy(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        }
    //Guardado de datos Leap-Frog.
    ofstream outfile3;
    outfile3.open("Leap.dat");
    for(int i=0;i<num;i++)
        {
        outfile3<<arrt[i]<<";"<<arrx[i]<<";"<<velox[i]<<";"<<arry[i]<<";"<<veloy[i]<<endl;
        }
    outfile3.close();
    ofstream outfile4;
    //Momento Angular
    outfile4.open("LeapAngular.dat");
    double angux[num];
    double anguy[num];
    for(int i=0;i<num;i++)
        {
        angux[i]=Angularx(arrx[i],arry[i],arrt[i],velox[i],veloy[i]);
        anguy[i]=Angulary(arrx[i],arry[i],arrt[i],velox[i],veloy[i]);
        outfile4<<angux[i]<<";"<<anguy[i]<<endl;
        }
    outfile4.close();
    }

//Metodo de Euler.
double euler(double a0,double h0, int num)
    {
    //Arrays para las posiciones de X, Y, T y las veloscidades en X y Y.
    double arrt[num];
    double arrx[num];
    double arry[num];
    double velox[num];
    double veloy[num];
    //Condiciones iniciales de los array.
    arrt[0]=a0;
    arrx[0]=0.1163;
    arry[0]=0.9772;
    velox[0]=-6.35;
    veloy[0]=0.606;
    //Procedimiento.
    for(int i=1; i<=num;i++)
        {
        arrt[i]=arrt[i-1]+h0;
        arrx[i]=arrx[i-1]+h0 * funcionx(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        arry[i]=arry[i-1]+h0 * funciony(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        velox[i]=velox[i-1]+h0*velocix(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        veloy[i]=veloy[i-1]+h0*velociy(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        }
    //Guardado de datos Euler.
    ofstream outfile2;
    outfile2.open("Euler.dat");
    for(int i=0;i<num;i++)
        {
        outfile2<<arrt[i]<<";"<<arrx[i]<<";"<<velox[i]<<";"<<arry[i]<<";"<<veloy[i]<<endl;
        }
    outfile2.close();
    //Momento Angular
    ofstream outfile5;
    outfile5.open("EulerAngular.dat");
    double angux[num];
    double anguy[num];
    for(int i=0;i<num;i++)
        {
        angux[i]=Angularx(arrx[i],arry[i],arrt[i],velox[i],veloy[i]);
        anguy[i]=Angulary(arrx[i],arry[i],arrt[i],velox[i],veloy[i]);
        outfile5<<angux[i]<<";"<<anguy[i]<<endl;
        }
    outfile5.close();
    }

//Metodo de runge Kutta.
double runge(double a0,double h0, int num)
    {
    //Array de tiempo
    double arrt[num];
    arrt[0]=a0;
    //COnstantes de K para X y Y.
    double kx1;
    double kx2;
    double kx3;
    double kx4;
    double ky1;
    double ky2;
    double ky3;
    double ky4;
    //COnstantes de K para V en X y Y.
    double kvx1;
    double kvx2;
    double kvx3;
    double kvx4;
    double kvy1;
    double kvy2;
    double kvy3;
    double kvy4;
    //Constantes para calcular el promedio de las K.
    double promx;
    double promy;
    double promvx;
    double promvy;
    //Arrays para las posiciones de X, Y y las veloscidades en X y Y.
    double arrx[num];
    double arry[num];
    double velox[num];
    double veloy[num];
    //Condiciones iniciales de los array.
    arrx[0]=0.1163;
    arry[0]=0.9772;
    velox[0]=-6.35;
    veloy[0]=0.606;
    for(int i=1; i<=num;i++)
        {
        //Primera K para cada variable.
        kx1=h0*funcionx(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        ky1=h0*funciony(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        kvx1=h0*velocix(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        kvy1=h0*velociy(arrx[i-1],arry[i-1],arrt[i-1],velox[i-1],veloy[i-1]);
        //Segunda K para cada variable.
        kx2=h0*funcionx(arrx[i-1]+0.5*kx1,arry[i-1]+0.5*kx1,arrt[i-1]+0.5*kx1,velox[i-1]+0.5*kx1,veloy[i-1]+0.5*kx1);
        ky2=h0*funciony(arrx[i-1]+0.5*ky1,arry[i-1]+0.5*ky1,arrt[i-1]+0.5*ky1,velox[i-1]+0.5*ky1,veloy[i-1]+0.5*ky1);
        kvx2=h0*velocix(arrx[i-1]+0.5*kvx1,arry[i-1]+0.5*kvx1,arrt[i-1]+0.5*kvx1,velox[i-1]+0.5*kvx1,veloy[i-1]+0.5*kvx1);
        kvy2=h0*velocix(arrx[i-1]+0.5*kvy1,arry[i-1]+0.5*kvy1,arrt[i-1]+0.5*kvy1,velox[i-1]+0.5*kvy1,veloy[i-1]+0.5*kvy1);
        //Tercera K para cada variable.
        kx3=h0*funcionx(arrx[i-1]+0.5*kx2,arry[i-1]+0.5*kx2,arrt[i-1]+0.5*kx2,velox[i-1]+0.5*kx2,veloy[i-1]+0.5*kx2);
        ky3=h0*funciony(arrx[i-1]+0.5*ky2,arry[i-1]+0.5*ky2,arrt[i-1]+0.5*ky2,velox[i-1]+0.5*ky2,veloy[i-1]+0.5*ky2);
        kvx3=h0*velocix(arrx[i-1]+0.5*kvx2,arry[i-1]+0.5*kvx2,arrt[i-1]+0.5*kvx2,velox[i-1]+0.5*kvx2,veloy[i-1]+0.5*kvx2);
        kvy3=h0*velocix(arrx[i-1]+0.5*kvy2,arry[i-1]+0.5*kvy2,arrt[i-1]+0.5*kvy2,velox[i-1]+0.5*kvy2,veloy[i-1]+0.5*kvy2);
        //Cuarta K para cada variable.
        kx4=h0*funcionx(arrx[i-1]+kx3,arry[i-1]+kx3,arrt[i-1]+kx3,velox[i-1]+kx3,veloy[i-1]+kx3);
        ky4=h0*funciony(arrx[i-1]+ky3,arry[i-1]+ky3,arrt[i-1]+ky3,velox[i-1]+ky3,veloy[i-1]+ky3);
        kvx4=h0*velocix(arrx[i-1]+kvx3,arry[i-1]+kvx3,arrt[i-1]+kvx3,velox[i-1]+kvx3,veloy[i-1]+kvx3);
        kvy4=h0*velociy(arrx[i-1]+kvy3,arry[i-1]+kvy3,arrt[i-1]+kvy3,velox[i-1]+kvy3,veloy[i-1]+kvy3);
        //Promedios de K.
        promx=(1.0/6.0)*(kx1+2.0*kx2+2.0*kx3+kx4);
        promy=(1.0/6.0)*(ky1+2.0*ky2+2.0*kx3+ky4);
        promvx=(1.0/6.0)*(kvx3+2.0*kvx2+2.0*kvx3+kvx4);
        promvy=(1.0/6.0)*(kvy3+2.0*kvy2+2.0*kvy3+kvy4);
        //Completar arrays.
        arrt[i]=arrt[i-1]+h0;
        arrx[i]=arrx[i-1]+promx;
        arry[i]=arry[i-1]+promy;
        velox[i]=velox[i-1]+promvx;
        veloy[i]=veloy[i-1]+promvy;
        }
    //Guardado de datos Runge Kutta.
    ofstream outfile;
    outfile.open("RungeKutta.dat");
    for(int i=0;i<num;i++)
        {
        outfile<<arrt[i]<<";"<<arrx[i]<<";"<<velox[i]<<";"<<arry[i]<<";"<<veloy[i]<<endl;
        }
    outfile.close();
    //Momento Angular
    ofstream outfile6;
    outfile6.open("RungeKuttaAngular.dat");
    double angux[num];
    double anguy[num];
    for(int i=0;i<num;i++)
        {
        angux[i]=Angularx(arrx[i],arry[i],arrt[i],velox[i],veloy[i]);
        anguy[i]=Angulary(arrx[i],arry[i],arrt[i],velox[i],veloy[i]);
        outfile6<<angux[i]<<";"<<anguy[i]<<endl;
        }
    outfile6.close();
    }
int main()
    {
    double a=0.0;
    double b=20.0;
    double h=0.001;
    int puntos=(b-a)/h;
    cout<< puntos<<endl;
    runge(a,h,puntos);
    euler(a,h, puntos);
    Leap(a,h, puntos);
    return 0;
    }