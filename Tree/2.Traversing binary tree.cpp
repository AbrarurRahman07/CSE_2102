#include<iostream>
using namespace std;
void Inorder(int i,int n, int tree[])
{
    if(i<n && tree[i]!=-1)
    {
        Inorder(2*i+1,n,tree);
        cout<<tree[i]<<" ";
        Inorder(2*i+2,n,tree);
    }
}
void preorder(int i,int n, int tree[])
{
    if(i<n && tree[i]!=-1)
    {
        cout<<tree[i]<<" ";
        preorder(2*i+1,n,tree);
        preorder(2*i+2,n,tree);
    }
}
void Postorder(int i,int n, int tree[])
{
    if(i<n && tree[i]!=-1)
    {
        Postorder(2*i+1,n,tree);
        Postorder(2*i+2,n,tree);
        cout<<tree[i]<<" ";
    }
}
int main()
{
    int tree[] = {43,31,64,20,40,56,89,-1,28,33,-1,47,59,-1,-1};
    cout<<"Preorder Traversal : ";
    preorder(0,15,tree);
    cout<<endl;
    cout<<"Inorder Traversal : ";
    Inorder(0,15,tree);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    Postorder(0,15,tree);
    cout<<endl;
}
