#include <iostream>
#include<bits/stdc++.h>
using namespace std;

double determinant(vector<vector<double>> adj, int n)
{

    if(n == 1)
        return adj[0][0];
    if(n==2)
        return adj[0][0] * adj[1][1] - adj[0][1] *adj[1][0];
    double det = 0;
    for(int col = 0 ; col < n ; col ++)
    {
        vector<vector<double>>minor(n-1, vector<double>(n-1));

        for(int i = 1 ; i < n ; i++)
        {

            int j2 = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if( j == col ) continue ;
                minor[i-1][j2++] = adj[i][j];
            }
        }
        double sign = (col % 2 == 0) ? 1 : -1 ;
        det += sign * adj[0][col] * determinant(minor, n - 1);
    }
    return det ;
}

vector<vector<double>> cofactorMatrix(vector<vector<double>> adj, int n)
{
    vector<vector<double>>cof(n,vector<double>(n));
    for(int row = 0 ; row < n ; row ++)
    {
        for(int col = 0 ; col < n ; col ++)
        {
            vector<vector<double>> minor(n-1,vector<double>(n-1));
            int r2 = 0;
            for(int i = 0 ; i < n ; i++)
            {
                if( i == row )
                    continue;
                int c2 = 0;
                for(int j = 0 ; j < n ; j++)
                {
                    if(j == col) continue;
                    minor[r2][c2++] = adj[i][j];
                }
                r2++;
            }
            double sign = ((row + col) % 2 == 0) ? 1 : -1 ;
            cof[row][col] = sign * determinant(minor, n -1);
        }

    }
    return cof;
}
void printMatrix (vector<vector<double>> mat, int n)
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
vector<vector<double>> adjoint(vector<vector<double>> mat, int n)
{
    vector<vector<double>>adj(n, vector<double>(n));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            adj[i][j] = mat[j][i];
    }
    return adj;
}
vector<vector<double>> inverseMat(vector<vector<double>> mat, int n , int det)
{
    vector<vector<double>> inverse (n,vector<double>(n));
    for(int i = 0 ; i < n ; i ++ )
    {
        for(int j = 0 ; j  < n ; j++)
        {
            inverse[i][j] = (mat[i][j])  / det ;
        }
    }
    return inverse;
}

vector<double>multiply(vector<vector<double>>mat  , vector<double>b , int n)
{
    vector<double>ans(n,0);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n  ; j++)
        {
            ans[i] += mat[i][j]*b[j];
        }
    }
    return ans;
}
int main()
{
    int n ;
    cout << "Enter number of eqn " << endl;
    cin >> n ;
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    cout << "Enter coefficient matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter constant matrix B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];
    double det = determinant(A, n);

    cout << "Determinant = " << det << endl;

    if(fabs(det) < 1e-9)
    {
        cout <<  "Inverse does not exist.\n";
        return 0;
    }
    vector<vector<double>> C =
                            cofactorMatrix(A, n);

    cout << "\nCofactor Matrix:\n";
    printMatrix(C, n);
    vector<vector<double>> adj =
                            adjoint(C, n);

    cout << "\nAdjoint Matrix:\n";
    printMatrix(adj, n);

     vector<vector<double>> inv =
        inverseMat(adj, n , det);

    cout << "\nInverse Matrix A^-1:\n";
    printMatrix(inv, n);


    vector<double> X =
        multiply(inv, B, n);

    cout << "\nSolution:\n";

    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(4)
             << X[i] << endl;

    return 0;

}
