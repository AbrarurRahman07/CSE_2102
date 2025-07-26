#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* cirSingly(int data){
 struct node* temp =(struct node*) malloc(sizeof(struct node));
 temp->data = data;
 temp->next = temp;

 return temp;
};

struct node* add_beg(struct node* tail, int d){
  struct node* newN =(struct node*)malloc(sizeof(struct node));

  newN->data = d;
  newN->next = tail->next;
  tail->next = newN;

  return tail;
};

void print(struct node* tail){
 struct node* ptr = tail->next;
 do{
    printf("%d ", ptr->data);
    ptr = ptr->next;
 }while(ptr!=tail->next);
}

int main(){
 struct node* tail =(struct node*) malloc(sizeof(struct node));
 tail = cirSingly(45);
 tail = add_beg(tail,34);
 tail = add_beg(tail,3);
 tail = add_beg(tail,4);
 print(tail);

 return 0;
}
