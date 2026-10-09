#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;


double fun(double x)
{
    return (3*x - cos(x) -1 );
}
void Secant(double x0 , double x1)
{
    int i = 0;
    double x2 ;
    while(true)
    {
        double funx0 = fun(x0);
        double funx1 = fun(x1);
        x2 = x1 - (funx1*(x1-x0)) / (funx1 - funx0);
        if(abs(fun(x2)) < tol) break;
        cout << fixed << setprecision(3);
        cout << "Iteration : " << i
        << ": x0 = " << x0
        << " , f(x0) = " << funx0
        << " , f(x1) = " << funx1
        << " , x2 = " << x2<< endl;
        x0 = x1;
        x1 = x2;
        i++;
    }
cout << "Approximate root = " << x2 << endl;
}
int main()
{
    double x0 , x1;
    cin >> x0 >> x1 ;
    Secant(x0 , x1);
}
