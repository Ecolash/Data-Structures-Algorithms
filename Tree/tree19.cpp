// TREE TO ARRAY CONVERSION

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
        return NULL;

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
    int arr[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, size);

    size = count(root);
    int *array = new int[size];

    BSTtoArray(root, array);
    displaySortedArray(array, size);

    deleteBST(root);
    delete[] array;

    return 0;
}
