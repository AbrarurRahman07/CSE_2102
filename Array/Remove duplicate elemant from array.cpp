#include<iostream>
using namespace std;

void sort_array(int a[],int x)
{
    for(int i=0; i<x; i++)
    {
        for(int j=i+1; j<x; j++)
        {
            if(a[j]<a[i])
                swap(a[j],a[i]);
        }
    }
}
void marge_array(int a[],int a1[],int a2[],int x,int y)
{
    int k=0;
    for(int i=0; i<x; i++)
    {
        a[k]=a1[i];
        k++;
    }
    for(int i=0; i<y; i++)
    {
        a[k]=a2[i];
        k++;
    }
}
void remove_it(int a[],int pos,int x)
{
    for(int i=pos; i<x-1; i++)
    {
        a[i]=a[i+1];
    }
}
int main()
{
    int arr1[]= {12,34,21,34,17,1,3,2,57,89,43,21,32,14,16,9,7,5};
    int arr2[]= {8,5,7,2,12,34,32,34,56,32,45,23,56,76,23,1};
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);
    cout<<"The given arrays are: "<<endl;
    for(int i=0; i<n1; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<n2; i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    int n=n1+n2;
    int arr[n];

    marge_array(arr,arr1,arr2,n1,n2);
    sort_array(arr,n);

    cout<<"After merging : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    ///Process of removing duplicate element
    int m = n;
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] == arr[i])
            {
                remove_it(arr, i, m);
                m--;
                i--;
                break;
            }
        }
    }

    cout << "After removing duplicate element : " << endl;
    for(int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


