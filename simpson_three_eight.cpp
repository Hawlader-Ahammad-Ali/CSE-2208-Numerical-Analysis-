#include <bits/stdc++.h>
using namespace std;
double fun(double x)
{
    return (sqrt(x));
}
double simpson_three_eight(double a  , double b , double n)
{
    double h = (b-a) / n;
    double y0 = fun(a);
    double yn = fun(b);
    double three = 0 , non_three = 0;
    for(int i = 1 ;  i < n ; i++)
    {
        a+=h;
        if(i%3 == 0)
            three+= fun(a);
        else non_three+= fun(a);
    }
    double ans = (3*h*((y0+yn) + 2*three + 3*non_three))/8;
    return ans;
}
int main()
{
   double a , b , n;
   cin >> a >> b >> n;
   cout << simpson_three_eight(a,b,n) << endl;
}
