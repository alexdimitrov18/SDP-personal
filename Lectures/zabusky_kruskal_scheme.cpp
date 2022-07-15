#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

const double Pi=3.141592653589793;
const double t=1.0/(1024.0*1024.0*256.0); // time step
const int N=512; // number of space grid intervals
const double delta=0.022;
const double h=2.0/N; // length of space grid intervals
const double T=30.4/Pi;  //Recurrence time
const double c1=t/(3.0*h);
const double c2=(delta*delta*t)/(h*h*h);
const double c3=c1/2.0;
const double c4=c2/2.0;



int main()
{
   ofstream outfile;
   outfile.open("result.txt");
   outfile << scientific << setprecision(8);
   double u1[N];
   double u2[N];
   double time=0.0;
   //! Setting the initial conditions
   double x=0.0;
   for(int i=0; i<N; i++)
   {
       u2[i]=cos(Pi*x);
       x+=h;
   }
   //! The first step
   for (int i=0; i<=N-1;i++)
   {
       u1[i]=u2[i]-c3*(u2[(i-1+N)%N]+u2[i]+u2[(i+1)%N])*(u2[(i+1)%N]-u2[(i-1+N)%N])
       -c4*(u2[(i+2)%N] -2.0*(u2[(i+1)%N]-u2[(i-1+N)%N])-u2[(i-2+N)%N]);
   }
   time+=h;
   int steps=0;
   while (time < 1.21*T)
   {
      steps++;
      for (int i=0; i<=N-1;i++)
      {
          u2[i]=u2[i]-c1*(u1[(i-1+N)%N]+u1[i]+u1[(i+1)%N])*(u1[(i+1)%N]-u1[(i-1+N)%N])
          -c2*(u1[(i+2)%N] -2.0*(u1[(i+1)%N]-u1[(i-1+N)%N])-u1[(i-2+N)%N]);
      }
      time+=t;
      for (int i=0; i<=N-1;i++)
      {
          u1[i]=u1[i]-c1*(u2[(i-1+N)%N]+u2[i]+u2[(i+1)%N])*(u2[(i+1)%N]-u2[(i-1+N)%N])
          -c2*(u2[(i+2)%N] -2.0*(u2[(i+1)%N]-u2[(i-1+N)%N])-u2[(i-2+N)%N]);
      }
      time+=t;

      if (steps==1024*1024)
      {
          for (int i=0; i<=N-1; i++)
          {
               outfile << u1[i] << endl;
          }
          outfile << u1[0] << endl;
          steps=0;
      }


   }




}
