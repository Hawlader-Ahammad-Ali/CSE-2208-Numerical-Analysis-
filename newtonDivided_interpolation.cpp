#include <bits/stdc++.h>
using namespace std;
void difference_table(vector<vector<double>>&mat, vector<double>&x ,int n )
{
    for(int j = 1 ;  j < n ; j++)
    {
        for(int i = 0 ;  i < n-j ; i++)
        {
            mat[i][j] = (mat[i+1][j-1] - mat[i][j-1])/(x[i+j] - x[i]);
        }
    }
}
double newtonDivided(vector<vector<double>>&y , vector<double>&x , int n , double value )
{
    difference_table(y,x,n);
    double result = y[0][0];
    double term = 1 ;
    for(int i =  1 ; i < n ; i++)
    {
        term *= (value -x[i-1]);
        result += term*y[0][i];
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
   cout << "Answer : " << newtonDivided(y,x,n,target) << endl;
}
/*
4
3 180
5 150
7 120
9 90
4
*/
