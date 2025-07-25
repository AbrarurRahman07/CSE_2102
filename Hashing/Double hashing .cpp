#include<iostream>
using namespace std;

const int tsize=10;
int hash_table[tsize]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int hash_function(int x)
{
    return x%tsize;
}

void insert(int n)
{
    int index=hash_function(n);
    int h1=index;
    if(hash_table[index]!=-1)
    {
        index=n%(tsize-2);
        int h2=index;
        int i=0;
        while(hash_table[index]!=-1 && i<tsize)
        {
            index=(h1+h2*i)%tsize;
            i++;
        }
        if(i==tsize)
            return;
    }
    hash_table[index]=n;
}
void search(int x)
{
    int index=hash_function(x);
    int h1=index;
    if(hash_table[index]!=x)
    {
        index=x%(tsize-2);
        int h2=index;
        int i=0;
        while(hash_table[index]!=x && i<tsize)
        {
            index=(h1+h2*i)%tsize;
            i++;
        }
        if(i==tsize)
        {
            cout<<"Not found"<<endl;
            return;
        }
    }
    cout<<"Found at index "<<index<<endl;
}
void display()
{
    cout << "\nHash Table:\n";
    for (int i=0; i<tsize; i++)
    {
        cout <<"Index "<<i<< ": ";
        if (hash_table[i] == -1)
            cout << "EMPTY";
        else
            cout << hash_table[i];
        cout << endl;
    }
}
int main()
{
    int key[]= {4,6,14,9,12,34,44,72,54};
    for(auto A:key)
        insert(A);
    display();
    search(9);
    search(14);
    search(54);
}
