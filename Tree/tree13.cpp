// TREE INVERTER

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
        return root;
    }

    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }

    else if (data >= root->data)
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

Node *invert(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invert(root->left);
    invert(root->right);

    return root;
}

int main()
{
    Node *Root = NULL;
    Root = Insert(Root, 15);
    Root = Insert(Root, 10);
    Root = Insert(Root, 20);
    Root = Insert(Root, 12);
    Root = Insert(Root, 8);
    Root = Insert(Root, 6);
    Root = Insert(Root, 16);
    Root = Insert(Root, 18);
    Root = Insert(Root, 25);
    Root = Insert(Root, 36);

    InorderTraversal(Root);
    Root = invert(Root);

    cout << endl;
    InorderTraversal(Root);
    return 0;
}