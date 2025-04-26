#include<iostream>
using namespace std;

void sort_array(int a[],int x)
{
  for(int i=0;i<x;i++)
  {
    for(int j=i+1;j<x;j++)
    {
      if(a[j]<a[i])
        swap(a[j],a[i]);
    }
  }
}
int main()
{
  int arr[]={12,34,21,34,17,1,3,2,57,89,43,21,32,14,16,9,7,5};
  int n=sizeof(arr)/sizeof(int);
  cout<<"The given array is: "<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  sort_array(arr,n);

  cout<<"After sorting: "<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
