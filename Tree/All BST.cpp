#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};

// Create BST
struct node* createBST(struct node* root, int value)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (root == NULL)
    {
        ptr->data = value;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
        root = ptr;
        return root;
    }
    else
    {
        if (value < root->data)
            root->lchild = createBST(root->lchild, value);
        else if (value > root->data)
            root->rchild = createBST(root->rchild, value);
        else
            cout << "Duplicate not ALLOWED." << endl;
        return root;
    }
}

// Inorder Traversal
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}

// Search
bool search(struct node* root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->lchild, key);
    else
        return search(root->rchild, key);
}

// Find max in left subtree
struct node* findMax(struct node* root)
{
    while (root->rchild != NULL)
        root = root->rchild;
    return root;
}

// Delete Node
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->lchild = deleteNode(root->lchild, key);
    else if (key > root->data)
        root->rchild = deleteNode(root->rchild, key);
    else
    {
        // Case 1: Leaf node
        if (root->lchild == NULL && root->rchild == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->lchild == NULL)
        {
            struct node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node* temp = root->lchild;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else
        {
            struct node* temp = findMax(root->lchild);
            root->data = temp->data;
            root->lchild = deleteNode(root->lchild, temp->data);
        }
    }
    return root;
}

int main()
{
    struct node* root = NULL;
    int x, n;
    cout << "Enter the number of Nodes: ";
    cin >> n;
    while (n--)
    {
        cin >> x;
        root = createBST(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search Test
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    if (search(root, key))
        cout << key << " found in the BST.\n";
    else
        cout << key << " not found.\n";

    // Delete Test
    cout << "Enter value to delete: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << "After deletion, Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}

