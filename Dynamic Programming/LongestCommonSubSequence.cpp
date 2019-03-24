#include<iostream>
#include<string>

using namespace std;

int lcsRecur(char X[], char Y[], int m, int n)
{
    if(m==0 || n==0)
        return 0;
    if(X[m-1] == Y[n-1])
        return 1 + lcsRecur(X, Y, m-1, n-1);
    else
        return max(lcsRecur(X, Y, m-1, n), lcsRecur(X, Y, m, n-1));
}

int lcsDP(char X[], char Y[], int m, int n)
{
    int table[m+1][n+1];
    // initialization
    for(int i=0; i<m+1; i++)
        table[i][0] = 0;
    
    for(int j=0; j<n+1; j++)
        table[0][j] = 0;

    for(int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(X[i-1] == Y[j-1])
                table[i][j] = 1 + table[i-1][j-1];
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    cout<<"DP table : "<<endl;
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"longest common subsequence length is : "<<table[m][n]<<endl;
}

int main()
{
    int m, n;
    char *X, *Y;
    cin>>m;
    X = new char[m];
    cin>>X;
    cin>>n;
    Y = new char[n];
    cin>>Y;
    cout<<lcsRecur(X, Y, m, n)<<endl;
    lcsDP(X, Y, m, n);
    return 0;
}