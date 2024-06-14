// COUNTING NUMBER OF NODES OF ANY TREE

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

void deleteBST(Node *root)
{
    if (root == NULL)
        return;

    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

int count(Node *root)
{
    if (root == NULL)
        return 0;

    int counter = 1;
    if (root != NULL)
    {
        counter = counter + count(root->left) + count(root->right);
    }
    return counter;
}

int main()
{
    int arr[] = {12, 5, 15, 3, 7, 13, 17, 1, -1, -1, 9, -1, -1, -1, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, size);

    int numNodes = count(root);
    cout << "Number of nodes: " << numNodes << endl;
    deleteBST(root);
    return 0;
}
