#include<bits/stdc++.h>

using namespace std;

int coinExchangeRecur(int coin[], int n, int sum)
{
    // base cases
    // sum 0, one solution, don't include any coin
    if(sum==0)
        return 1;
    // sum is negetive, no solution
    if(sum<0)
        return 0;
    // don't have any coin and there is a sum
    // so no solution
    if(n<=0 && sum>=1)
        return 0;
    // include the coin or leave it
    return coinExchangeRecur(coin, n-1, sum) + coinExchangeRecur(coin, n, sum-coin[n-1]);
}

int coinExchangeDP(int coin[], int n, int sum)
{
    int table[sum+1][n];
    // initialization
    for(int i=0; i<n; i++)
        table[0][i] = 1;
    int x, y;
    for(int i=1; i<sum+1; i++)
    {
        for(int j=0; j<n; j++)
        {
            x = (i-coin[j]>=0) ? table[i-coin[j]][j] : 0;
            y = (j>=1) ? table[i][j-1] : 0;
            table[i][j] = x+y;
        }
    }
    return table[sum][n-1];
}

int main()
{
    int n, *coin, sum;
    cin>>n;
    coin = new int[n];
    for(int i=0; i<n; i++)
        cin>>coin[i];
    cin>>sum;
    //cout<<coinExchangeRecur(coin, n, sum)<<endl;
    cout<<coinExchangeDP(coin, n, sum)<<endl;
    return 0;
}