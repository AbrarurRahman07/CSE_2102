#include<stdio.h>
#define MAX 100

int stack[MAX];
int top=-1;

void push(int n)
{
  if(top>MAX-1)
  {
    printf("Stack overflow\n");
    return;
  }
  stack[++top]=n;
}

int pop()
{
  if(top==-1)
  {
    printf("Stack underflow\n");
    return;
  }
  stack[top]=0;
  return stack[top--];
}

int peek()
{
  return stack[top];
}
void size()
{
  printf("%d\n",top+1);
}
int isempty()
{
  if(top==-1)
    return 0;
  else
    return 1;
}
int main()
{
  push(10);
  push(20);
  push(30);
  push(40);
  size();
  printf("%d\n",peek());
  pop();
  printf("%d\n",peek());

  return 0;
}
