#include<iostream>
using namespace std;

void sort_array(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[]= {12,11,3,17,18,2,7};
    int n=sizeof(arr)/sizeof(int);
    cout<<"The given array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sort_array(arr,n);

    cout<<"After sorting: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
