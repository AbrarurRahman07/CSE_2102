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
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<root->data<<" ";
    }
}

void search(struct node* root,int item,int step=1)
{
    if (root==NULL)
    {
        cout<<"Item not found."<<endl;
        return;
    }

    if (root->data==item)
    {
        cout<<"Found at step "<<step<<endl;
    }
    else if(item<root->data)
    {
        search(root->lchild,item,step+1);
    }
    else
    {
        search(root->rchild,item,step+1);
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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    search(root,33);
}


