// CREATION OF AN AVL TREE

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

Node *NewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

int height(Node *root)
{
    if (root == NULL)
        return -1;

    int x = height(root->left);
    int y = height(root->right);
    return 1 + max(x, y);
}

int balance_factor(Node *root)
{
    int lh, rh;
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->height;

    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->height;
    return rh - lh;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node *retrace(Node *node)
{
    if (node == NULL)
        return node;

    if ((balance_factor(node) < -1))
    {
        if (balance_factor(node->left) > 0)
        {
            node->left = leftRotate(node->left);
        }
        node = rightRotate(node);
    }

    else if ((balance_factor(node) > 1))
    {
        if (balance_factor(node->right) < 0)
        {
            node->right = rightRotate(node->right);
        }
        node = leftRotate(node);
    }

    node->height = 1 + max(height(node->left), height(node->right));
    return node;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
        return retrace(root);
    }

    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else if (data >= root->data)
        root->right = Insert(root->right, data);
    root = retrace(root);
    return root;
}

int main()
{
    Node *Root = NULL;
    Root = Insert(Root, 5);
    Root = Insert(Root, 10);
    Root = Insert(Root, 20);
    Root = Insert(Root, 22);
    Root = Insert(Root, 38);
    Root = Insert(Root, 62);
    Root = Insert(Root, 66);
    Root = Insert(Root, 88);
    Root = Insert(Root, 95);
    Root = Insert(Root, 96);

    cout << Root->height;
    return 0;
}