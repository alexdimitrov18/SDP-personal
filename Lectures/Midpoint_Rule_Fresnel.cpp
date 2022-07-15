#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double f(double x)
{
    return sin(x*x);
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

   cout << setprecision(8) << scientific;

   cout << "Fresnel sine (0,1) = " << I4 << endl;
   cout << "Effective order of convergence = " << log(abs((I1-I2)/(I2-I4)))/log(2.0) << endl;
   cout << "A posteriori error estimation on the finest grid = " << (I4-I2)/3.0 << endl;

}
