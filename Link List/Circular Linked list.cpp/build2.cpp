#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

void insert(struct node **tail,int n)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=n;

    if (*tail==NULL)
    {
        ptr->next=ptr;
        ptr->prev=ptr;
        *tail=ptr;
    }
    else
    {
        struct node* head=(*tail)->next;

        ptr->next=head;
        ptr->prev=*tail;
        head->prev=ptr;
        (*tail)->next=ptr;

        *tail=ptr; // new node becomes tail
    }
}
void printForward(struct node* tail)
{
    if (tail==NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    struct node* temp=tail->next;
    do
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    while(temp!=tail->next);
    cout<<endl;
}
void printBackward(struct node* tail)
{
    if (tail==NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    struct node* temp=tail;
    do
    {
        cout<<temp->data<< " ";
        temp=temp->prev;
    }
    while(temp!=tail);
    cout<<endl;
}

int main()
{
    struct node *tail=NULL;
    int n,x;
    cout <<"Enter the number of nodes: ";
    cin >>n;
    while(n--)
    {
        cin>>x;
        insert(&tail,x);
    }

    cout<<"Forward Print: ";
    printForward(tail);

    cout<<"Backward Print: ";
    printBackward(tail);
}
