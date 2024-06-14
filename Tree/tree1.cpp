// CREATION OF A BINARY SEARCH TREE

#include <iostream>

// NOTE : This Code is specific to binary search trees only

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

    else if (data < root->data)
    {
        root->left = Insert(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }

    else if (data == root->data)
    {
        printf("Data already present \n");
    }

    return root;
}

int main()
{
    Node *Root = NULL;
    Root = Insert(Root, 15);
    Root = Insert(Root, 10);
    Root = Insert(Root, 20);
    Root = Insert(Root, 15);
    Root = Insert(Root, 8);
    Root = Insert(Root, 6);
    Root = Insert(Root, 16);
    Root = Insert(Root, 18);
    Root = Insert(Root, 25);
    Root = Insert(Root, 36);

    return 0;
}
