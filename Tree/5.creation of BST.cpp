#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value)
{
    Node* newNode = new Node();  // dynamically create a node
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(Node* root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    // Inserting values into BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}

