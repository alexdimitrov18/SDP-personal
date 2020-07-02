#include <iostream>
using namespace std;

unsigned long long int C[40];

//! Effective iterative function
void Count_eff(int n)
{
    for (int k=1; k<=n; k++)
    {
          unsigned long long int s=0;
          for(int root=1; root<=k; root++)
          {
               s+=C[root-1]*C[k-root];
          }
          C[k]=s;

    }
}

//! Straightforward but not effective recursive function
unsigned long long int Count_trees(int n)
{
    if(n==0) return 1;
    unsigned long long int s=0;
    for(int root=1; root<=n; root++)
    {
        s+=Count_trees(root-1)*Count_trees(n-root);
    }
    return s;
}


int main()
{
    C[0]=1;
    Count_eff(36); //! up to 36 elements - the maximum we can compute with unsigned long long int.
    //! Computation is momentary
    for (int i=0; i<=36; i++)
    {

        cout << "Count_trees(" << i << ") = " << C[i] << endl;

    }
    //! up to 22 elements - we can compute this in a foreseeable time (~2 min) with the poor recursive program
    for (int i=0; i<=22; i++)
    {

        cout << "Count_trees(" << i << ") = " << Count_trees(i) << endl;

    }


    return 0;
}
