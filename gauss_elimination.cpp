// 2307070
//sajib_70
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void GaussElimination(vector<vector<double>>&mat, int n)
{
    vector<double>answer(n) ;
    for(int col = 0 ; col < n -1 ; col++)
    {
        for(int i = col + 1 ; i < n ; i++)
        {
            double factor = (mat[i][col] / mat[col][col]);
            for(int j2 = col ; j2 <= n ; j2++)
            {
                mat[i][j2] = mat[i][j2] - (mat[col][j2] * factor);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = mat[i][n];

        for (int j = i + 1; j < n; j++)
        {
            answer[i] -= mat[i][j] * answer[j];
        }

        answer[i] /= mat[i][i];
    }
    for(int i = 0 ; i < n  ; i++)
    {
        cout << answer[i] << " " ;
    }
    cout << endl;
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
    GaussElimination(mat,n);
}
/*
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
*/
