#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void circular_singly(struct node **tail,int n)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=n;
    ptr->next=ptr;
    if(*tail==NULL)
    {
        *tail=ptr;
    }
    else
    {
        struct node* temp=*tail;
        ptr->next=(*tail)->next;
        (*tail)->next=ptr;
    }
}
void print(struct node* ptr)
{
    struct node*temp=ptr->next;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=ptr->next);
    cout<<endl;
}
int main()
{
    struct node *tail=NULL;
    int n,x;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    while(n--)
    {
      cin>>x;
      circular_singly(&tail,x);
    }
    print(tail);
}

