#include <iostream>
using namespace std;

int main()
{
    long int b, k;
    int arr[100000];
    cin>>b>>k;
    for(int i=0; i<k; i++)
    {
        cin>>arr[i];
    }
    if(b%2 == 0)    // even base
    {
        if(arr[k-1]%2==0)
        {
            cout<<"even"<<endl;
        }
        else
        {
            cout<<"odd"<<endl;
        }
        
    }
    else
    {
        int count = 0;
        for(int i=0; i<k; i++)
        {
            if(arr[i]%2 == 1)
                count++;
        }
        if(count%2 == 0)
        {
            cout<<"even"<<endl;
        }
        else
        {
            cout<<"odd"<<endl;
        }
        
    }
    
    return 0;
}