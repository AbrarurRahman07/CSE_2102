#include<iostream>
using namespace std;
int main()
{
    ///5->4
    int data[]= {12,56,32,1,23,45,34,67,32,56,32,56};
    cout<<"The given array is : ";
    for(auto p:data)
    {
        cout<<p<<" ";
    }
    cout<<endl;
    int n=sizeof(data)/sizeof(int);
    cout<<"There are total "<<n<<" element in this array."<<endl;
    int x,loc;
    cout<<"Enter the value to insert-"<<endl;
    cin>>x;
    cout<<"Enter the index number where you want to insert "<<x<<"-"<<endl;
    cin>>loc;
    for(int i=n; i>loc-1; i--)
    {
        data[i]=data[i-1];
    }
    data[loc-1]=x;
    cout<<"The modified array is : ";
    for(auto p:data)
    {
        cout<<p<<" ";
    }
    cout<<endl;
}


