#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;
double fun(double x)
{
    return (3*x - cos(x) -1 );
}
void FalsePosition(double a, double b)
{
    double c;
    if(fun(a)*fun(b) > 0)
    {
        cout << "Invalid " << endl;
        return;
    }
    int i = 1;
    while(true )
    {
         c = (a*fun(b) - b*fun(a))/(fun(b) - fun(a));
        cout << fixed << setprecision(3);
        cout << "Iteration " << i
             << ": a = " << a
             << ", b = " << b
             << ", c = " << c
             << ", f(c) = " << fun(c) << endl;
        if(abs(fun(c)) < tol) break;
        else if(fun(a)*fun(c) < 0)
            b = c;
        else
            a = c;
        i++;
    }

      cout << "Approximate root = " << c << endl;
}
int main()
{
   double a , b ;
    cin>> a >> b;
    Bisection(a,b);
}
