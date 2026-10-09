#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;

double derivative(double x)
{
    return (3+sin(x));
}
double fun(double x)
{
    return (3*x - cos(x) -1 );
}
void NewtonRaphson(double x0)
{
    double xn = x0 - (fun(x0) / derivative(x0));
    double x;
    int i = 0;
    while(true)
    {
        x = xn;
        if(abs(fun(x)) < tol) break;
        cout << fixed << setprecision(3);
        cout << "Iteration : " << i
        << ": xn = " << xn
        << " , f(x) = " << fun(xn)
        << " , f'(x) = " << derivative(xn)  << endl;
        xn = x - (fun(x) / derivative(x));
        i++;
    }
cout << "Approximate root = " << x << endl;
}
int main()
{
    double x;
    cin >> x ;
    NewtonRaphson(x);
}
