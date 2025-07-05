#include<stdio.h>
#define MAX 100
int stack_arr[MAX];
int first=-1;
void push(int n)
{
    int i;
    first++;
    for(i=first; i>0; i--)
    {
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=n;
}
void print()
{
    for(int i=0 ; i<=first ; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}
int pop()
{
    int i, value;
    value = stack_arr[0];
    for(i=0; i<first; i++)
        stack_arr[i] = stack_arr[i+1];
    stack_arr[first]=0;
    first -= 1;
    return value;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();



}











