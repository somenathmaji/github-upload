#include <iostream>

using namespace std;

// this is a dynamic programming aproach to solve this problem
// will fill the table in bottom up fashion
void minMatrixMultiplication(int d[], int n)
{
    int table[n][n];
    for(int i = 0; i < n; i++)
    {
        table[i][i] = 0;
    }
    
    for(int len = 2; len < n; len++)
    {
        for(int i = 1; i < n-len+1; i++)
        {
            int mul;
            int j = i+len-1;
            table[i][j] = INT32_MAX;
            for(int k = i; k < j; k++)
            {
                mul = table[i][k] + table[k+1][j] + d[i-1]*d[k]*d[j];
                if(mul < table[i][j])
                    table[i][j] = mul;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"minimum multiplication : "<<table[1][n-1]<<endl;;
}

int main()
{
    int n;
    int *a;
    cin>>n;
    a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    minMatrixMultiplication(a, n);
    return 0;
}