#include<bits/stdc++.h>

using namespace std;

int minDistanceRecur(int a[3][3], int i, int j, int m, int n)
{
    if(i==m && j==n)
        return a[i-1][j-1]; // we reached the destination
    else if(i==m)
        return a[i-1][j-1] + minDistanceRecur(a, i, j+1, m, n); // there is only one move
    else if(j==n)
        return a[i-1][j-1] + minDistanceRecur(a, i+1, j, m, n); // there is only one move
    else
        return a[i-1][j-1] + min(
                                min(
                                    minDistanceRecur(a, i+1, j, m, n),  // move down
                                    minDistanceRecur(a, i, j+1, m, n)   // move right
                                    ), 
                                minDistanceRecur(a, i+1, j+1, m, n)     // move diagonally
                                );
}

int minDistanceDP(int a[3][3], int m, int n)
{
    int table[m][n];
    //initialization
    table[0][0] = a[0][0];
    for(int i=1; i<m; i++)
        table[i][0] = table[i-1][0] + a[i][0];
    for(int j=1; j<n; j++)
        table[0][j] = table[0][j-1] + a[0][j];
    
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            table[i][j] = a[i][j] + min(
                                        min(
                                            table[i-1][j],  // down move
                                            table[i][j-1]   // up move
                                            ), 
                                        table[i-1][j-1]     // diagonal move
                                        );
        }
    }
    
    return table[m-1][n-1];
}

int main()
{
int cost[3][3] = { 
                {1, 2, 3}, 
                {4, 8, 2}, 
                {1, 5, 3} 
                };
    //cout<<minDistanceRecur(cost, 1, 1, 3, 3)<<endl;
    cout<<minDistanceDP(cost, 3, 3)<<endl;
    return 0;
}