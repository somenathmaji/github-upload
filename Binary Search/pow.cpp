#include<bits/stdc++.h>
using namespace std;

int power(int x, int n, int d) {
    // power function with the help of binary search
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    
    int base;
    if(x<0)
        base = (-1)*x;
    else
        base = x;
    base = base%d;
    
    int exp = n;

    int result = 1;
    while(n>0)
    {
        // n is odd
        if(n&1)
           result = (result*base)%d;
        // n can be even now
        n >>=1; // n/2
        base = (base*base)%d;
    }
    cout<<x<<" "<<n<<endl;
    if(x<0 && exp%2==1)   // negetive base and odd power. result should be negetive
    {
        cout<<"return 1"<<endl;
        return (d-result);
    }    
    else
    {
        cout<<"return 2"<<endl;
        return result;
    }
}

int main()
{
    int x, n, d;
    while(1)
    {
        cin>>x>>n>>d;
        cout<<power(x, n, d)<<endl;
    }
    return 0;
}