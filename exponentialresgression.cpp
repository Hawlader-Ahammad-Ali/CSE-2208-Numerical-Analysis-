#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void LinearRegression(double x[],double y[] , int n , int target)
{
    double sumx =0 , sumy = 0 , sumxy = 0 , sumx2 = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        sumx += x[i];
        sumx2 += (x[i]*x[i]);
        sumy += y[i];
        sumxy += (x[i]*y[i]);
    }
    double b = (n*sumxy - sumx*sumy) / (n*sumx2 - (sumx*sumx));
    double A = (sumy - b*sumx) / n;
     double a = exp(A);
    cout << "Exponetial Equation:\n";
    cout << "y = " << a << " * e^(" << b << "x)\n";

    double lnY = A + b*target ;

    cout << "Value of given x : " << exp(lnY) << endl;
    return ;
}
void exponentialRegression(double x[] , double y[] ,int n , int target)
{
    double Y[n];
    for(int i = 0 ; i < n ; i++) Y[i] = log(y[i]);
    LinearRegression(x,Y,n,target);

}
int main()
{
    int n ;
    cin >> n ;
    double x[n];
    double y[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i] >> y[i] ;
    }
    cout << "Find value for F(x) : " << endl;
    int value ;
    cin >> value ;
    exponentialRegression(x,y,n,value);

}
