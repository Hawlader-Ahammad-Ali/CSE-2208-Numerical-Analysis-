#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;
double fun(double x)
{
    return (3*x - cos(x) -1 );
}
void Bisection(double a, double b)
{
    double c ;
    double x1 = fun(a);
    double x2 = fun(b);
    if(x1*x2 > 0)
    {
        cout << "Invalid " << endl;
        return;
    }
    int i = 1;
    while(true )
    {
        c = (a+b)/2;
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
    int a , b ;
    cin>> a >> b;
    Bisection(a,b);
}
