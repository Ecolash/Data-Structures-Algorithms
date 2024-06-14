// Height of A tree

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

int height(Node *root)
{
    if (root == NULL)
    { // NOTE : For only one node height is 0
        return -1;
    }

    int x = height(root->left);
    int y = height(root->right);
    return 1 + max(x, y);
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

    cout << height(Root);
    return 0;
}