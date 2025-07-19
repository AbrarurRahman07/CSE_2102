#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node* newnode(int x)
{
    struct node *element = new struct node();
    element->data = x;
    element->left = NULL;
    element->right = NULL;
    return element;
}

void levelorder(struct node *root)
{
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    levelorder(root);  // Output: 1 2 3 4 5 6 7
    return 0;
}
