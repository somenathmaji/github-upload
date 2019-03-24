#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 8, 8, 8, 12};
    
    cout<<a<<endl;
    cout<<a+1<<endl;
    cout<<a+2<<endl;
    cout<<a+3<<endl;
    cout<<a+4<<endl<<endl;

    cout<<upper_bound(a, a+5, 8)-a<<endl;
    cout<<lower_bound(a, a+5, 8)-a<<endl;
    return 0;
}