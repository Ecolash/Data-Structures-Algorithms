// DELETION OF A NODE OF A BINARY SEARCH TREE

// 3 CASES:

// (1) Node is a leaf
// (2) Node has a single child
// (3) Node has two children

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

void deleteBST(Node *root)
{
    if (root == NULL)
        return;

    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

Node *min_node(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *DeleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    else if (root->data > data)
        root->left = DeleteNode(root->left, data);

    else if (root->data < data)
        root->right = DeleteNode(root->right, data);

    else
    {
        // (1) Node is a leaf
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }

        // (2) Node has a single child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }

        // (3) Node has two children
        else
        {
            Node *temp = min_node(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
            return root;
        }
    }
}

int main()
{
    int arr[] = {12, 5, 15, 3, 7, 13, 17, 1, -1, -1, 9, -1, -1, -1, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, size);

    InorderTraversal(root);
    cout << endl;

    root = DeleteNode(root, 1);
    InorderTraversal(root);
    cout << endl;

    root = DeleteNode(root, 5);
    InorderTraversal(root);
    cout << endl;

    root = DeleteNode(root, 7);
    InorderTraversal(root);
    cout << endl;

    root = DeleteNode(root, 9);
    InorderTraversal(root);
    cout << endl;

    deleteBST(root);
    return 0;
}
