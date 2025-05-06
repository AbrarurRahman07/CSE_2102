#include<stdio.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
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
    printf("\n");
}
void add_node_in_row(node** start,int n)
{
    node *temp=(node*)malloc(sizeof(node));
    node *ptr=*start;
    temp->data=n;
    temp->link=NULL;
    if(*start==NULL)
    {
        *start=temp;
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void delete_first_node(node **start)
{
    if(*start==NULL)
        printf("Node is empty");
    node *ptr=*start;
    ptr=ptr->link;
    ///free(*start);
    *start=ptr;
}
int main()
{
    node *head=NULL;
    add_node_in_row(&head,10);
    add_node_in_row(&head,20);
    add_node_in_row(&head,30);
    add_node_in_row(&head,40);
    add_node_in_row(&head,50);
    print_data(head);

    delete_first_node(&head);
    print_data(head);
    delete_first_node(&head);
    print_data(head);
}
