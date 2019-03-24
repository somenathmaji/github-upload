// C++ program to find median of a matrix 
// sorted row wise 
#include<bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 

// function to find median in the matrix 
int binaryMedian(int m[][MAX], int r ,int c) 
{ 
	int min = INT_MAX, max = INT_MIN; 
	for (int i=0; i<r; i++) 
	{ 
		// Finding the minimum element 
		if (m[i][0] < min) 
			min = m[i][0]; 

		// Finding the maximum element 
		if (m[i][c-1] > max) 
			max = m[i][c-1]; 
	} 

	int desired = (r * c + 1) / 2; 
    cout<<"desired : "<<desired<<endl;
	while (min < max) 
	{   cout<<"min : "<<min<<endl<<"max : "<<max<<endl;
		int mid = min + (max - min) / 2; 
		int place = 0; 
        cout<<"mid : "<<mid<<endl;
		// Find count of elements smaller than mid 
		for (int i = 0; i < r; ++i) 
        {
            cout<<"added : "<<upper_bound(m[i], m[i]+c, mid) - m[i]<<endl;
            place += upper_bound(m[i], m[i]+c, mid) - m[i]; 
        }
        cout<<"place : "<<place<<endl;
		if (place < desired) 
			min = mid + 1; 
		else
			max = mid; 
        cout<<endl<<endl;
	} 
	return min; 
} 

// driver program to check above functions 
int main() 
{ 
	int r = 3, c = 3; 
	int m[][MAX]= { {1,2,3}, {4,5,97}, {98,99,100} };
    int median = binaryMedian(m, r, c);

	cout << "Median is " << median << endl; 
	return 0; 
} 
