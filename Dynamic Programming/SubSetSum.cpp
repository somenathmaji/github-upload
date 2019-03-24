#include <iostream>

using namespace std;
// subset sum using recursive algorithm
bool SubSetSumRecur(int arr[], int n, int sum)
{
    if(sum==0)
        return true;
    
    if(n==0 && sum!=0)
        return false;
    
    if(arr[n-1] > sum)
        return SubSetSumRecur(arr, n-1, sum);
    
    return SubSetSumRecur(arr, n-1, sum) || SubSetSumRecur(arr, n-1, sum-arr[n-1]);
}
// using bottom up DP to solve subset sum problem
bool SubSetSumDP(int arr[], int n, int sum)
{
    bool table[n+1][sum+1];

    for(int i=0; i<=n; i++)
        table[i][0] = true;

    for(int j=1; j<=sum; j++)
        table[0][j] = false;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(arr[i-1] > j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = table[i-1][j] + table[i-1][j-arr[i-1]];
        }
    }
    return table[n][sum];
}

int main()
{
    int n, sum, *arr;
    cin>>n;
    arr=new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cin>>sum;
    cout<<SubSetSumRecur(arr, n, sum)<<endl;
    cout<<SubSetSumDP(arr, n, sum)<<endl;
    return 0;
}