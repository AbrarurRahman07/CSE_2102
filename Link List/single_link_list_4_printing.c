#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void print_data(struct node *head)
{
    if(head==NULL)
        printf("Node is empty");
    struct node *temp=NULL;
    temp =head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->link;
        if(temp!=NULL)
            printf(" -> ");
    }
}
int main()
{
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;

    struct node *current=NULL;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link->link=current;
    print_data(head);
    return 0;
}

