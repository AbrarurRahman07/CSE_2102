#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
int hashTable[TABLE_SIZE];

void initialize()
{
    for (int i=0;i<TABLE_SIZE; i++)
        hashTable[i] =-1;
}

int hashFunction(int key)
{
    return key%TABLE_SIZE;
}

void insert(int key)
{
    int index=hashFunction(key);
    int i=0;

    while (i<TABLE_SIZE)
    {
        int probeIndex=(index+i*i)%TABLE_SIZE;

        if (hashTable[probeIndex]==-1)
        {
            hashTable[probeIndex]=key;
            return;
        }
        i++;
    }

    cout<<"Hash Table is full. Couldn't insert key: "<<key<<endl;
}

void search(int key)
{
    int index=hashFunction(key);
    int i=0;

    while (i<TABLE_SIZE)
    {
        int probeIndex=(index + i*i %TABLE_SIZE;

        if (hashTable[probeIndex]==key)
        {
            cout <<"Key "<<key<<" found at index "<<probeIndex<<endl;
            return;
        }
        if (hashTable[probeIndex]==-1)
         break; // key not found

        i++;
    }
    cout << "Key " << key << " not found!" << endl;
}

void display()
{
    cout << "\nHash Table (Quadratic Probing):\n";
    for (int i=0;i<TABLE_SIZE;i++)
    {
        cout <<"Index "<<i<<": ";
        if (hashTable[i] == -1)
            cout<<"EMPTY";
        else
            cout<<hashTable[i];
        cout<<endl;
    }
}

int main()
{
    initialize();

    int keys[]={4,6,14,9,12,34,44,19};

    for (int key : keys)
        insert(key);

    display();

    search(6);
    search(5);

    return 0;
}
