#include <bits/stdc++.h>
using namespace std;
void backward_table(vector<vector<double>>&mat, int n )
{
    for(int j = 1 ;  j < n ; j++)
    {
        for(int i = 0 ;  i< n-j ; i++)
        {
            mat[i][j] = mat[i+1][j-1] - mat[i][j-1];
        }
    }
}
double newtonBackward(vector<vector<double>>&y , vector<double>&x , int n , double value )
{
    backward_table(y,n);
    double h = x[1] - x[0];
    double u = (value - x[n-1])/h;
    double result = y[n-1][0];
    double term = 1 ;
    for(int i =   1 ; i < n ; i++)
    {
        term *= (u+(i-1)) / i;
        result += term*y[n-i-1][i];
    }
    return result ;
}
int main()
{
   int n ;
   cin >> n ;
   vector<double>x(n);
   vector<vector<double>>y(n,vector<double>(n,0));
   for(int i = 0 ; i < n ; i++)
   {
       cin >>  x[i] >> y[i][0] ;
   }
  // cout << "Enter targeted value : " << endl;
   double target ;
   cin >> target;
   cout << "Answer : " << newtonBackward(y,x,n,target) << endl;
}
/*
4
3 180
5 150
7 120
9 90
4
*/
