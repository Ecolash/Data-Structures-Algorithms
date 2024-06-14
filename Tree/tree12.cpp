// CHECK FOR SAME TREE

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

bool isSameTree(Node *p, Node *q)
{

    if (p == NULL && q == NULL)
        return 1;

    if (p == NULL || q == NULL || (p->data != q->data))
        return 0;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    Node *root1 = NULL;
    root1 = Insert(root1, 15);
    root1 = Insert(root1, 10);
    root1 = Insert(root1, 20);
    root1 = Insert(root1, 12);
    root1 = Insert(root1, 8);
    root1 = Insert(root1, 6);
    root1 = Insert(root1, 16);
    root1 = Insert(root1, 18);
    root1 = Insert(root1, 25);
    root1 = Insert(root1, 36);

    Node *root2 = NULL;
    root2 = Insert(root2, 15);
    root2 = Insert(root2, 10);
    root2 = Insert(root2, 20);
    root2 = Insert(root2, 12);
    root2 = Insert(root2, 8);
    root2 = Insert(root2, 6);
    root2 = Insert(root2, 16);
    root2 = Insert(root2, 18);
    root2 = Insert(root2, 5);
    root2 = Insert(root2, 36);

    cout << isSameTree(root1, root2) << endl;
    return 0;
}