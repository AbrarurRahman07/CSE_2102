#include <iostream>
using namespace std;

const int TABLE_SIZE=10;
int hashTable[TABLE_SIZE];

void initialize()
{
    for (int i=0;i<TABLE_SIZE;i++)
        hashTable[i]=-1;
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key)
{
    int index=hashFunction(key);
    int startIndex=index;

    while(hashTable[index] !=-1)
    {
        index = (index +1)%TABLE_SIZE;

        if (index==startIndex)
        {
            cout <<"Hash Table is full. Cannot insert key: "<<key<< endl;
            return;
        }
    }

    hashTable[index]=key;
}

void search(int key)
{
    int index=hashFunction(key);
    int startIndex=index;

    while (hashTable[index]!=-1)
    {
        if (hashTable[index]==key)
        {
            cout<<"Key found at index "<<index<<endl;
            return;
        }
        index=(index+1)%TABLE_SIZE;

        if (index==startIndex)
          break;
    }

    cout<<"Key not found!"<<endl;
}

void display()
{
    cout << "\nHash Table (Linear Probing):\n";
    for (int i=0;i<TABLE_SIZE;i++)
    {
        cout <<"Index "<<i<< ": ";
        if (hashTable[i] == -1)
            cout << "EMPTY";
        else
            cout << hashTable[i];
        cout << endl;
    }
}
int main()
{
    initialize();

    int keys[] = {4,6,14,9,12,34,44,19};

    for (int key : keys)
        insert(key);

    display();

    search(6);
    search(5);

    return 0;
}

