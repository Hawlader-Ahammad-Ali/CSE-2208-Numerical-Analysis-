#include <bits/stdc++.h>
using namespace std;

double fun(double x , double y)
{
    return (2*x + y);
}

double RK4(double x , double h , double y)
{
    double k1 = h*fun(x,y);
    double k2 = h*fun(x + h/2 ,y + k1/2);
    double k3 = h*fun(x + h/2 ,y + k2/2);
    double k4 = h*fun(x + h ,y + k3);

    double yn = y + (k1+2*k2+2*k3+k4)/6;
    return yn;
}

void ODE(double x0 , double y0 , double h , double last)
{
    double y = y0 , x = x0;
    while(x < last-1e-9){
        double step = min(h,last - x );
        y = RK4(x,step , y);
        x+= step;
    }

    cout << x << " " << y << endl;
}

int main()
{
    double x0, last , h , y0;
    cin >> x0 >> last >> h >> y0;
    ODE(x0,last,h,y0);
}
