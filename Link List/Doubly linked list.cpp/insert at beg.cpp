#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* pre;
    int data;
    struct node* next;
};
void insert(struct node **head,int n)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=n;
    ptr->pre=NULL;
    ptr->next=NULL;
    if(*head==NULL)
    {
        *head=ptr;
    }
    else
    {
        struct node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->pre=temp;
    }
}
void insert_beg(struct node **head,int n)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=n;
    ptr->pre=NULL;
    ptr->next=NULL;
    if(*head==NULL)
    {
        *head=ptr;
    }
    else
    {
        struct node* temp=*head;
        ptr->next=temp;
        temp->pre=ptr;
        *head=ptr;
    }
}
void print(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL)
        {
            printf("->");
        }
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    struct node* head=NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert_beg(&head,5);
    insert_beg(&head,4);
    insert_beg(&head,3);
    insert_beg(&head,2);
    insert_beg(&head,1);
    print(head);
}

