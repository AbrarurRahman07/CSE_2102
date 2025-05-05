#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void print_node(struct node* start)
{
    struct node *temp=start;
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start=start->link;
    }
}
struct node* add_at_end(struct node *ptr,int n)
{
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=n;
  temp->link=NULL;
  ptr->link=temp;
  return temp;
}
struct node* add_at_beg(struct node *head,int n)
{
  struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->link=head;
    return p;
}
struct node* add_at_beg(struct node **head,int n)
{
  struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->link=*head;
    *head= p;
}
int main()
{
  ///Initial Node
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=20;
    head->link=NULL;\
  ///Adding Node at end
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link=current;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link->link=current;

    struct node *ptr=head->link->link;
    ptr=add_at_end(ptr,420);
    ptr=add_at_end(ptr,420);
    ptr=add_at_end(ptr,420);
  ///Adding Node at begining
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=44444;
    p->link=head;
    head=p;

    head=add_at_beg(head,5555);
    add_at_beg(&head,7);


    print_node(head);
}
