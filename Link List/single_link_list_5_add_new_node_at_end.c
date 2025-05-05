#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *ptr, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}

void print_data(struct node *head)
{
    if(head==NULL)
        printf("Node is empty\n");
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
    struct node *ptr=head;
    ptr=add_at_end(ptr,420);
    ptr=add_at_end(ptr,20);
    ptr=add_at_end(ptr,42);
    ptr=head;
    print_data(head);
    return 0;
}

