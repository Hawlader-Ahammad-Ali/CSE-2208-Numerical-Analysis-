#include <bits/stdc++.h>
using namespace std;
double fun(double x)
{
    return (1/(x*x +1));
}
double simpson_one_third(double a  , double b , double n)
{
    double h = (b-a) / n;
    double y0 = fun(a);
    double yn = fun(b);
    double even = 0 , odd = 0;
    for(int i = 1 ;  i < n ; i++)
    {
        a+=h;
        if(i%2 == 0)
            even+= fun(a);
        else odd+= fun(a);
    }
    double ans = h*((y0+yn) + 2*even + 4*odd)/3;
    return ans;
}
int main()
{
   double a , b , n;
   cin >> a >> b >> n;
   cout << simpson_one_third(a,b,n) << endl;
}
