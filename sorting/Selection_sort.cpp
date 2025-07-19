#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int mini=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[mini])
            {
                mini=j;
            }
        }
        if(mini!=i)
        {
            swap(arr[i],arr[mini]);
        }
    }
}
int main()
{
    int arr[]= {17,12,18,5,7,8,10};
    int arr2[]= {9,13,15,11,2};
    int n=sizeof(arr)/sizeof(int);
    selection_sort(arr,n);
    for(auto a:arr)
        cout<<a<<" ";
    cout<<endl;
    int n2=sizeof(arr2)/sizeof(int);
    selection_sort(arr2,n2);
    for(auto a:arr2)
        cout<<a<<" ";
    cout<<endl;
}
