#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lisDP(int arr[], int n)
{
    int table[n];
    // initialization
    table[0] = 1;

    for(int i=1; i<n; i++)
    {
        table[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(arr[j] < arr[i] && table[j] + 1 > table[i])
                table[i] = 1 + table[j];
        }
    }
    for(int i=0; i<n; i++)
        cout<<table[i]<<" ";
    cout<<endl;
    cout<<"max increasing subsequence length is : "<<*max_element(table, table+n)<<endl;
}

int main()
{
    int n, *arr;
    cin>>n;
    arr= new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    lisDP(arr, n);
    return 0;
}