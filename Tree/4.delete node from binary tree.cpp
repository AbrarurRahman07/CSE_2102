#include<iostream>
using namespace std;

void inorder(int i,int n,int tree[])
{
    if(i<n && tree[i]!=-1)
    {
        inorder(2*i+1,n,tree);
        cout<<tree[i]<<" ";
        inorder(2*i+2,n,tree);
    }
}
void deleteNode(int i,int n,int tree[],int item)
{
  while(i<n && tree[i]!=-1)
  {
    if(tree[i]==item)
    {
      int left=2*i+1;
      int right=2*i+2;


      if((left>=n || tree[left]==-1) && (right>=n || tree[right]==-1))
      {
        tree[i]=-1;
      }


      else if(left>=n || tree[left]==-1)
      {
        tree[i]=tree[right];
        tree[right]=-1;
      }
      else if(right>=n || tree[right]==-1)
      {
        tree[i]=tree[left];
        tree[left]=-1;
      }


      else
        {
          int k=left;
          while(2*k+2 <n && tree[2*k+2]!=-1)
          {
            k=2*k+2;
          }
          tree[i]=tree[k];
          tree[k]=-1;
        }
    }
    else if(item<tree[i])
    {
      i=2*i+1;
    }
    else
    {
      i=2*i+2;
    }
  }
}
int main()
{
    int tree[] = {43,31,64,20,40,56,89,-1,28,33,-1,47,59,-1,-1};
    int n=sizeof(tree)/sizeof(tree[0]);
    inorder(0,n,tree);
    cout<<endl;
    deleteNode(0,n,tree,40);
    inorder(0,n,tree);
}
