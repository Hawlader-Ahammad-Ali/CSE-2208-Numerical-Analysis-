#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void gaussJordan(vector<vector<double>>&mat , int n)
{
    for(int col = 0 ; col < n ; col++)
    {
        double pivot = mat[col][col];
        for(int i = 0 ; i <= n ; i++)
            mat[col][i] /= pivot ;
        for(int row = 0 ; row < n ; row++)
        {
            if(col == row) continue;

            double factor = mat[row][col];
            for(int j = 0 ; j <= n ; j++)
            {
                mat[row][j] -= factor*mat[col][j];
            }
        }
    }
}
void polynomialRegression(double x[] , double y[], int n , int degree , int target)
{

    int m = degree+1;
    vector<vector<double>>mat(m,vector<double>(m+1,0));
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            for(int k = 0; k < n; k++)
                mat[i][j] += pow(x[k], i + j);
        }
        for(int k = 0 ; k < n ; k++)
            mat[i][m] += y[k] * pow(x[k],i);
    }
    gaussJordan(mat,m);
    double coeff[20];

    cout << "Coefficients : " << endl;
    for(int i = 0 ;  i < m ; i++)
    {
        coeff[i] = mat[i][m];
        cout << "a" << i << " = " << coeff[i] << endl;
    }
    cout << "\nPolynomial Equation:\n";

    for(int i = 0; i < m; i++)
    {
        if(i > 0)
            cout << " + ";

        cout << coeff[i];

        if(i >= 1)
            cout << "x";

        if(i >= 2)
            cout << "^" << i;
    }
    double result = 0;
    for(int i = 0 ; i < m ; i++)
          result += (coeff[i] * pow(target,i)) ;
    cout << "Value of given x : " << result << endl;
}

int main()
{
    int n , degree;
    cin >> n >> degree ;
    double x[n];
    double y[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i] >> y[i] ;
    }
    cout << "Find value for F(x) : " << endl;
    int value ;
    cin >> value ;
    polynomialRegression(x,y,n,degree,value);

}
