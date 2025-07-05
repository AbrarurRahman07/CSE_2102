#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *link;
}*top;

void push(char data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    ptr->link=top;
    top=ptr;
}

char pop()
{
    struct node *temp;
    temp=top;
    char val=temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}
char peek()
{
  return top->data;
}

void print()
{
    struct node *ptr=top;
    while(ptr!=NULL)
    {
        printf("%c ",ptr->data);
        ptr=ptr->link;
    }
}
int main()
{
    char s[100];
    fgets(s,sizeof(s),stdin);
    fflush(stdin);
    int len = strlen(s);
    for (int i = 0; i<len; i++)
    {
        if(s[i]=='(')
        {
            push(s[i]);
        }
        if(s[i]==')')
        {
            if(top==NULL)
            {
                printf("NO\n");
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
   if(top==NULL)
   {
     printf("YES\n");
   }
   else
   {
     printf("NO\n");
   }
}
