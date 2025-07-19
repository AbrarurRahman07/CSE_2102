#include<iostream>
using namespace std;
void search_node(int i,int n,int tree[],int item)
{
  if(i>=n || tree[i]==-1)
    return;
  if(tree[i]==item)
  {
    cout<<"Found at index: "<<i<<endl;
    return;
  }
  search_node(2*i+1,n,tree,item);
  search_node(2*i+2,n,tree,item);
}
int main()
{
    int tree[] = {43,31,64,20,40,56,89,-1,28,33,-1,47,59,-1,-1};
    search_node(0,15,tree,89);
}

