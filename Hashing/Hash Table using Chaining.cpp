#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct Node
{
    int value;
    Node* next;
};
struct Node* hashTable[TABLE_SIZE];

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key)
{
    int index=hashFunction(key);
    Node* newNode=new Node;

    newNode->value=key;
    newNode->next=hashTable[index];
    hashTable[index] = newNode;
}

void search(int key)
{
    int index = hashFunction(key);
    Node* current = hashTable[index];

    while (current != nullptr)
    {
        if (current->value == key)
        {
            cout << "Key found! Value: " << current->value << " in bucket " << index << endl;
            return;
        }
        current = current->next;
    }
    cout << "Key not found!" << endl;
}
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "Index " << i << ": ";
        Node* current = hashTable[i];
        while (current != nullptr)
        {
            cout << "["<< current->value << "] -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    /*for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = nullptr;*/

    int key[]= {4,6,14,9,12,34,44,19};

    for(auto x: key)
        insert(x);

    display();

    search(6);
    search(5);

    return 0;
}
