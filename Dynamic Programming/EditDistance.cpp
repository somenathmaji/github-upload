#include<bits/stdc++.h>

using namespace std;

int editDistanceRecur(string s1, string s2, int m, int n)
{
    // base case
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(s1[m-1] == s2[n-1])
        return editDistanceRecur(s1, s2, m-1, n-1); // match
    else
        return 1 + min(
                        min(
                            editDistanceRecur(s1, s2, m, n-1),  // insertion
                            editDistanceRecur(s1, s2, m-1, n)   // deletion
                            ), 
                        editDistanceRecur(s1, s2, m-1, n-1)     // replacement
                        );
}

int editDistanceDP(string s1, string s2, int m, int n)
{
    int table[m+1][n+1];
    
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if(j==0)
                table[i][j] = i;
            else if(i==0)
                table[i][j] = j;
            else if(s1[i-1] == s2[j-1])
                table[i][j] = table[i-1][j-1];  // match
            else
                table[i][j] = 1 + min(
                                    min(
                                        table[i][j-1],  // insertion
                                        table[i-1][j]   // deletion
                                        ), 
                                    table[i-1][j-1]     // replacement
                                    );
        }
    }
    return table[m][n];
}

int main()
{
    string s1 = "saturday";
    string s2 = "sunday";
    cout<<editDistanceRecur(s1, s2, s1.length(), s2.length())<<endl;
    cout<<editDistanceDP(s1, s2, s1.length(), s2.length())<<endl;
    return 0;
}