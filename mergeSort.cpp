#include <iostream>

using namespace std;

int merge(int arr[], int low, int mid, int high)
{
    int n1 = (mid - low) + 1;
    int n2 = (high - mid);
    int tempArr[n1 + n2];
    
    int index = 0;
    int index1 = low;
    int index2 = mid+1;
    
    while(index1 <= mid && index2 <= high)
    {
        if(arr[index1] < arr[index2])
            tempArr[index++] = arr[index1++];
        else
            tempArr[index++] = arr[index2++];
    }
    while(index1 <= mid)
    {
        tempArr[index++] = arr[index1++];
    }

    while(index2 <= high)
    {
        tempArr[index++] = arr[index2++];
    }

    int j = 0;
    for(int i=low; i<=high; i++)
    {
        arr[i] = tempArr[j++];
    }

}

int mergeSort(int arr[], int l, int h)
{
    if(l>=h)
        return true;
    int mid = l + (h-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, h);
    merge(arr, l, mid, h);
}

int main()
{
    int a[] = {8, 4, 5, 3, 10, 33, 0};
    mergeSort(a, 0, 6);
    
    for(int i=0; i<7; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}