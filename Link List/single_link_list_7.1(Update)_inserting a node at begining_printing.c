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
void add_at_beg(struct node **head,int n)
{
  struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->link=*head;
    *head=p;
}
int main()
{
  ///Initial Node
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=20;
    head->link=NULL;

  ///Adding Node
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link=current;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link->link=current;

  ///Adding Node at begining
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=44444;
    p->link=head;
    head=p;
  //by function
    add_at_beg(&head,5555);
    add_at_beg(&head,0);
    print_node(head);
}

