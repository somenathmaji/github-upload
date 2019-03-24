#include <iostream>

using namespace std;

int knapsack01Recur(int value[], int weight[], int n, int capacity)
{
    // base case
    if(n==0)    // no item, can't include any item
        return 0;
    if(capacity<=0) // capacity is zero, can't include any item
        return 0;
    if(weight[n-1] > capacity)
        return knapsack01Recur(value, weight, n-1, capacity);
    
    return max(knapsack01Recur(value, weight, n-1, capacity), value[n-1] + knapsack01Recur(value, weight, n-1, capacity-weight[n-1]));
}

void knapsack01DP(int value[], int weight[], int n, int capacity)
{
    int table[n+1][capacity+1];
    // initialization
    // no space left in knapsack
    for(int i=0; i<n+1; i++)
        table[i][0] = 0;
    // no item left
    for(int j=0; j<capacity+1; j++)
        table[0][j] = 0;
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<capacity+1; j++)
        {
            if(weight[i-1] > j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = max(table[i-1][j], value[i-1] + table[i-1][j-weight[i-1]]);
        }
    }
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<capacity+1; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"maximum value possible : "<<table[n][capacity]<<endl;
}

int main()
{
    int n;
    int *value, *weight, capacity;
    cin>>n;
    value = new int[n];
    weight = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>value[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    cin>>capacity;
    cout<<"maximum value possible : "<<knapsack01Recur(value, weight, n, capacity)<<endl;
    knapsack01DP(value, weight, n, capacity);
    return 0;
}