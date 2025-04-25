#include<iostream>
using namespace std;
int main()
{
    int data[]= {12,56,32,1,23,45,34,67,32,56,32,56};

    cout<<"The given array is : ";
    for(auto p:data)
    {
        cout<<p<<" ";
    }
    cout<<endl;
    int n=sizeof(data)/sizeof(int);
    cout<<"There are total "<<n<<" element in this array."<<endl;
    int loc;
    cout<<"Enter the location to delete -"<<endl;
    cin>>loc;
    for(int i=loc-1; i<n-1; i++)
    {
        data[i]=data[i+1];
    }
    cout<<"The modified array is : ";
    for (int i = 0; i < n-1; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}


