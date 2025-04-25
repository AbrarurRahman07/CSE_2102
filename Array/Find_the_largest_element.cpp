#include<iostream>
using namespace std;
int main()
{
    int data[]= {12,56,32,1,23,45,34,67,32,56,32,56};

    int n=sizeof(data)/sizeof(int);

    int max=data[0],loc=0;
    for(int i=1; i<n; i++)
    {
        if(data[i]>max)
        {
            max=data[i];
            loc=i;
        }
    }
    cout<<"The maximum value is "<<max<<" at index number "<<loc<<"."<<endl;
}

