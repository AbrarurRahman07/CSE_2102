#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};
struct node* createBST(struct node* root,int value)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(root==NULL)
    {
        ptr->data=value;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
        root=ptr;
        return root;
    }
    else
    {
        if(value<root->data)
            root->lchild=createBST(root->lchild,value);
        else if(value>root->data)
            root->rchild=createBST(root->rchild,value);
        else
            cout<<"Duplicate not ALLOWED."<<endl;
        return root;
    }
};
void inorder(struct node* root)
{
  if(root!=NULL)
  {
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
  }
}
int main()
{
  struct node* root=NULL;
  int x,n;
  cout<<"Enter the number of Node: ";
  cin>>n;
  while(n--)
  {
    cin>>x;
    root=createBST(root,x);
  }
   inorder(root);
}
