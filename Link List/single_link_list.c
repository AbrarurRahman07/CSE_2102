#include<stdio.h>
#include<stdlib.h>
typedef struct link_list
{
    int data;
    struct node *link;
} node;
int main()
{
    node *head=NULL;
    head=(node*)malloc(sizeof(node));
    head->data=10;
    head->link=NULL;

    node *current=NULL;
    current=(node*)malloc(sizeof(node));
    current->data=20;
    current->link=NULL;
    head->link=current;

   printf("%d %d",head->data,current->data);
}
