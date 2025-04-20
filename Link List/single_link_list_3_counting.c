#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void count_of_node(struct node *head)
{
    int count =0;
    if(head==NULL)
        printf("Node is empty");
    struct node *temp=NULL;
    temp =head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    printf("There are total %d Nodes.\n",count);
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
    count_of_node(head);
    return 0;
}

