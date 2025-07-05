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
  top++;
  stack[top]=n;
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

int main()
{
  push(10);
  push(20);
  push(30);
  push(40);
  pop();
  printf("%d\n",stack[3]);
  return 0;
}
