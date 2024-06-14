// Traversal of A tree
// Breadth - First Traversal

#include <iostream>
#include <queue>

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

void breadthFirstTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";

        if (current->left != NULL)
            Q.push(current->left);

        if (current->right != NULL)
            Q.push(current->right);

        Q.pop();
    }
}

void breadthFirstTraversal2(Node *root)
{
    if (root == NULL)
        return;

    Node *Q[100];
    int front = 0;
    int rear = 0;

    Q[rear++] = root;

    while (front != rear)
    {
        Node *current = Q[front];
        cout << current->data << " ";

        if (current->left != NULL)
            Q[rear++] = (current->left);

        if (current->right != NULL)
            Q[rear++] = (current->right);

        Q[front++];
    }
    printf("\n");
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

    breadthFirstTraversal(Root);
    breadthFirstTraversal2(Root);
    return 0;
}