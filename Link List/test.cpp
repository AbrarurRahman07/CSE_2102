#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_data(struct node *ptr,int n)
{
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=n;
  temp->link=NULL;
  ptr->link=temp;
  return temp;
}
void print_node(struct node* start)
{
    struct node *temp=start;
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start=start->link;
    }
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=20;
    head->link=NULL;
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link=current;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link->link=current;

    struct node *ptr=head->link->link;
    ptr=add_data(ptr,420);
    ptr=add_data(ptr,420);
    ptr=add_data(ptr,420);

    print_node(head);
}
