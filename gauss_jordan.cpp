// 2307070
//sajib_70
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void PrintMat(vector<vector<double>>&mat , int n)
{
    cout << "Updated Matrix : " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void GaussJordan(vector<vector<double>>&mat, int n)
{
    vector<double>answer(n) ;
    for(int col = 0 ; col < n  ; col++)
    {
        double pivot = mat[col][col];
        // make col diagonal equal 1
        for(int i = 0 ; i <= n  ; i++)
        {
            mat[col][i] /= pivot ;
        }

        for(int row = 0 ;  row < n ; row++ )
        {
            if( row == col ) continue ;
            // ex Row 2 = Row 2 - Row 1 * mat[1][0]
            double factor = mat[row][col];
            for(int j = 0 ; j <= n ; j++)
            {
                mat[row][j] -= mat[col][j]*factor;
            }
        }
    }
    PrintMat(mat,n);
    cout << "Solution : " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << "x" << i+1 << " = " << mat[i][n] << endl;
    }
}
int main()
{
    int n ;
    cin >> n ;
    vector<vector<double>>mat(n,vector<double>(n+1));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= n ; j++)
        {
            cin >> mat[i][j];
        }
    }
    GaussJordan(mat,n);
}
/*
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
*/
