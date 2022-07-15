#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double myPi=3.141592653589793;

double f(double x)
{
    return 4.0/(1.0+x*x);
}

double midpoint(double a, double b, int n)
{
    double I=0.0;
    double h=(b-a)/n;
    double x=h/2;
    for(int i=0; i<n; i++)
    {
        I+=f(x);
        x+=h;
    }
    return I*h;
}

int main()

{
   int n=1024;
   double a=0.0;
   double b=1.0;
   double I1=midpoint(a,b,n);
   double I2=midpoint(a,b,2*n);
   double I4=midpoint(a,b,4*n);

   double error2 = myPi-I2;
   double error4 = myPi-I4;

   cout << setprecision(8) << scientific;

   cout << "Effective order of convergence  = " << log(abs((I1-I2)/(I2-I4)))/log(2.0) << endl;
   cout << "A posteriori error estimation on the second grid = " << (I2-I1)/3.0 << endl;
   cout << "A posteriori error estimation on the finest grid = " << (I4-I2)/3.0 << endl;
   cout << "Real error on the second grid = " << error2 << endl;
   cout << "Real error on the finest grid = " << error4 << endl;
}
