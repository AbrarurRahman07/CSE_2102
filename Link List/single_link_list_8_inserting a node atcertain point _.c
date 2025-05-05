#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
void print_node(struct node *start)
{
  struct node *ptr=start;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->link;
  }
}
struct node* add_at_end(struct node *ptr,int x)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->link=NULL;
  ptr->link=temp;
  return temp;
};
void add_at_pos(struct node *ptr,int pos,int num)
{
  struct node *ptr1=ptr;
  struct node *ptr2=(struct node*)malloc(sizeof(struct node));
  ptr2->data=num;
  pos-=2;
  while(pos--)
  {
    ptr1=ptr1->link;
  }
  ptr2->link=ptr1->link;
  ptr1->link=ptr2;
}
void add_at_beg(struct node **ptr,int x)
{
  struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->link=*ptr;
    *ptr=p;
}
int main()
{
  struct node *head=(struct node*)malloc(sizeof(struct node));
  head->data=30;
  head->link=NULL;

  struct node *ptr=(struct node*)malloc(sizeof(struct node));
  ptr=head;
  ptr=add_at_end(ptr,40);
  ptr=add_at_end(ptr,50);

  add_at_beg(&head,20);
  add_at_beg(&head,10);

  add_at_pos(head,3,1971);
  add_at_pos(head,4,2024);

  print_node(head);
}
