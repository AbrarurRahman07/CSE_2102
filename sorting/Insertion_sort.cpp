#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
      int temp=arr[i];
      for(int j=i-1;j>=0 && arr[j]>temp;j--)
      {
        swap(arr[j+1],arr[j]);
      }
    }
}
int main()
{
    int arr[]= {17,12,18,5,7,8,10};
    int arr2[]= {9,13,15,11,2};

    int n=sizeof(arr)/sizeof(int);
    insertion_sort(arr,n);

    cout<<"Sorting first Array"<<endl;

    for(auto a:arr)
        cout<<a<<" ";
    cout<<endl;

    int n2=sizeof(arr2)/sizeof(int);
    insertion_sort(arr2,n2);

    cout<<"Sorting secound Array"<<endl;

    for(auto a:arr2)
        cout<<a<<" ";
    cout<<endl;
}

