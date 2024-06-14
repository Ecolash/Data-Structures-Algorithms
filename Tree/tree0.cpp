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

Node *InsertinBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
        return root;
    }

    else if (data <= root->data)
    {
        root->left = InsertinBST(root->left, data);
    }

    else if (data >= root->data)
    {
        root->right = InsertinBST(root->right, data);
    }

    return root;
}

int max_value(Node *root)
{
    Node *current = root;
    if (current == NULL)
        return -1;

    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int min_value(Node *root)
{
    Node *current = root;
    if (current == NULL)
        return -1;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
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

int depth(Node *root, int data)
{
    int Depth = 0;
    if (root == NULL)
        return -1;

    if (root->data == data)
        return Depth;

    if (data < root->data)
        return depth(root->left, data) + 1;

    else
        return depth(root->right, data) + 1;
}

void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void InorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

void PostorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
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

bool isSameTree(Node *p, Node *q)
{

    if (p == NULL && q == NULL)
        return 1;

    if (p == NULL || q == NULL || (p->data != q->data))
        return 0;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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

Node *inorderSuccessor(Node *root, Node *p)
{
    if (root == NULL)
        return NULL;

    // Case 1: If right subtree exists

    if (p->right)
    {
        p = p->right;
        while (p->left)
            p = p->left;
        return p;
    }

    // Case 2: If right subtree does not exist

    Node *successor = NULL;
    while (root)
    {
        if (p->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (p->data > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }

    return successor;
}

Node *Search(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    else if (root->data == data)
    {
        return root;
    }

    else if (data < root->data)
        return Search(root->left, data);

    else if (data > root->data)
        return Search(root->right, data);
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

void BSTtoArray(Node *root, int A[])
{
    static int pos = 0;
    if (root == NULL)
        return;

    BSTtoArray(root->left, A);
    A[pos++] = root->data;
    BSTtoArray(root->right, A);
}

void displaySortedArray(int *arr, int size)
{
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
