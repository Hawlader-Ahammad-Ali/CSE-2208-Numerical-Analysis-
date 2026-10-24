#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double INF = 1e5;
void PrintMat(vector<vector<double>>&mat, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void LUdecomposition(vector<vector<double>>&mat,vector<double>&x, int n )
{
    vector<vector<double>>L(n,vector<double>(n,0));
    vector<vector<double>>U(n,vector<double>(n,0));
    for(int j = 0 ; j < n ; j++)
    {
        U[j][j] = 1;
        for(int i = j ; i < n ; i++)
        {
            L[i][j] = mat[i][j];
            for(int k = 0 ; k < j ; k++)
                L[i][j] -= L[i][k] * U[k][j];
        }

        for(int i = j+1 ; i < n ; i++)
        {
            U[j][i] = mat[j][i];
            for(int k = 0 ; k < j ; k++)
            {
                U[j][i] -= L[j][k] * U[k][i];
            }
            U[j][i] /= L[j][j];
        }

    }
    cout << "L matrix  : " << endl;
    PrintMat(L,n);
    cout << "U matrix  : " << endl;
    PrintMat(U,n);
    // forword
    vector<double>Z(n);
    for(int i = 0 ; i < n ; i++)
    {
        Z[i] = x[i];
        for(int j = 0 ; j < i  ; j++)
        {
            Z[i] -= L[i][j] * Z[j];

        }
        Z[i] /= L[i][i];
    }
    cout << "Z matrix : " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << Z[i] << endl;
    }
    // backword
    vector<double>ans(n);
    for(int i = n-1 ; i >= 0 ; i--)
    {
        ans[i] = Z[i];
        for(int j = i+1 ; j < n  ; j++)
            ans[i] -= U[i][j] * ans[j];
    }
    cout << "Answer is : " << endl;
    cout << fixed << setprecision(4) << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << "x" << i << " : " << ans[i] << endl;
    }
}
int main()
{
    int n ;
    cin >> n;
    vector<vector<double>>mat(n,vector<double>(n,0));
    vector<double>x(n);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            cin >> mat[i][j];
    }
    for(int i = 0 ; i < n ; i++)
        cin >> x[i];
    LUdecomposition(mat,x,n);
}
/*
5 10
1 2 4
1 4 5
2 5 6
2 3 1
3 1 2
3 4 3
4 3 1
4 5 2
5 4 4
5 1 1
*/
