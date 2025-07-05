#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *right;
  struct node *left;
};
struct node* newnode(int x)
{
  struct node *element=new struct node();

  element->data=x;
  element->left=NULL;
  element->right=NULL;

  return element;
}
void preorder(struct node *n)
{
  if(n!=NULL)
  {
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
  }
}

void inorder(struct node *n)
{
  if(n!=NULL)
  {
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
  }
}
void postorder(struct node *n)
{
  if(n!=NULL)
  {
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
  }
}
int main()
{
  struct node *root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->left=newnode(4);
  root->left->right=newnode(5);
  root->right->left=newnode(6);
  root->right->right=newnode(7);
  preorder(root);
}
