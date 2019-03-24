#include<bits/stdc++.h>
using namespace std;

int sum(int arr[], int from, int to)
{
    int total = 0;
    for(int i=from; i<=to; i++)
        total+=arr[i];
    return total;
}

int partition(int arr[], int n, int k)
{
    // base case if only one painter
    if(k==1)
        return sum(arr, 0, n-1);
    // base case if only one board
    if(n==1)
        return arr[0];

    int best = INT_MAX;
    for(int i=1; i<=n; i++)
        best = min(best, max(partition(arr, i, k-1), sum(arr, i, n-1)));

    return best;
}

int findMax(int arr[] ,int n, int k)
{
    // dp table
    int table[n+1][k+1] = {0};
    
    // sum cache to quickly compute the sum in a range
    int sumCache[n+1] = {0};
    for(int i=1; i<=n; i++)
        sumCache[i] = sumCache[i-1] + arr[i-1];

    //base case 1 : only 1 board
    for(int i=1; i<=k; i++)
        table[1][i] = arr[0];
    //base case 2 : only 1 painter
    for(int i=1; i<=n; i++)
        table[i][1] = sumCache[i];

    for(int i=2; i<=n; i++) // from 2 to n blocks
    {
        for(int j=2; j<=k; j++) // from 2 to k painters
        {
            int best = INT_MAX;
            for(int x=1; x<=i; x++) // starting position of the block
            {
                best = min(best, max(table[x][j-1], sumCache[i]-sumCache[x]));
            }
            table[i][j] = best;
        }
    }

    return table[n][k];
}

int getMax(int arr[], int from, int to)
{
    int maximum = arr[from];
    for(int i=from+1; i<=to; i++)
        maximum = max(maximum, arr[i]);
    return maximum;
}

int getPainterCount(int arr[], int n, int maxLen)
{
    int count = 1;
    int total = 0;

    for(int i=0; i<=n; i++)
    {
        total += arr[i];

        if(total>maxLen)
        {
            count++;
            total = arr[i];
        }
    }
    
    return count;
}

int partitionBS(int arr[], int n, int k)
{
    int low = getMax(arr, 0, n-1);
    int high = sum(arr, 0, n-1);
    
    while(low<high)
    {
        int mid = (low+high)/2;
        int required = getPainterCount(arr, n-1, mid);  // get the optimum number of painter for this maxlen

        if(required<=k)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    int *arr;
    int n; int k;
    cout<<"Enter number of boards : ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter sizes of boards : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Enter number of painters : ";
    cin>>k;
    cout<<partition(arr, n, k)<<endl;
    cout<<findMax(arr, n, k)<<endl;
    cout<<partitionBS(arr, n, k)<<endl;
    return 0;
}