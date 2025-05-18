#include<stdio.h>
#include<stdlib.h>
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
void reverse_all_node(node **head)
{
    node *ptr=NULL;
    node *temp=*head;
    while(temp !=NULL)
    {
        node* n=(node*)malloc(sizeof(node));
        n->data=temp->data;
        n->link=ptr;
        ptr=n;
        temp=temp->link;
    }
    *head=ptr;
}
int main()
{
    node *head=NULL;
    add_node_in_row(&head,10);
    add_node_in_row(&head,20);
    add_node_in_row(&head,20);
    add_node_in_row(&head,30);
    add_node_in_row(&head,40);
    add_node_in_row(&head,40);
    add_node_in_row(&head,40);
    add_node_in_row(&head,50);
    print_data(head);

    reverse_all_node(&head);
    print_data(head);

}


