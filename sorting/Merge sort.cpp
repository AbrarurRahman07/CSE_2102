#include <iostream>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    int temp[100];

    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }

    while (i<= m)
        temp[k++]=arr[i++];
    while (j<=r)
        temp[k++]=arr[j++];

    for (int p=0;p<k;p++)
        arr[l+p] =temp[p];
}
void mergeSort(int arr[],int l,int r)
{
    if (l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}
void printArray(int arr[],int size)
{
    for (int i=0; i<size ;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int arr[]={5,2,8,1,9};
    int n = sizeof(arr)/sizeof(int);
    cout << "Original array: ";
    printArray(arr,n);

    mergeSort(arr,0,n-1);

    cout << "Sorted array: ";
    printArray(arr,n);

    return 0;
}

