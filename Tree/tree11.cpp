// CREATION OF A GENERAL BINARY TREE

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

Node *createBinaryTree(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    Node *root = NewNode(arr[0]);

    queue<Node *> Q;
    Q.push(root);

    int i = 1;
    while (!Q.empty() && i < size)
    {
        Node *current = Q.front();
        Q.pop();

        if (arr[i] != -1) // -1 : Represents null node
        {
            current->left = NewNode(arr[i]);
            Q.push(current->left);
        }
        i++;

        if (i >= size)
            break;

        if (arr[i] != -1)
        {
            current->right = NewNode(arr[i]);
            Q.push(current->right);
        }
        i++;
    }

    return root;
}

void InorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, size);

    InorderTraversal(root);
    cout << " " << endl;
    breadthFirstTraversal(root);

    return 0;
}
