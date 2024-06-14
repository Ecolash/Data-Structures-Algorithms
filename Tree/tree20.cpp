// CHECK IF TREE IS BST BY ARRAY CONVERSION

// Principle : In-order traversal of BST gives sorted array

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

void BSTtoArray1(Node *root, int A[])
{
    static int pos = 0;
    if (root == NULL)
        return;

    BSTtoArray1(root->left, A);
    A[pos++] = root->data;
    BSTtoArray1(root->right, A);
}

void BSTtoArray2(Node *root, int A[])
{
    static int pos = 0;
    if (root == NULL)
        return;

    BSTtoArray2(root->left, A);
    A[pos++] = root->data;
    BSTtoArray2(root->right, A);
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

bool checkBST(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};
    int arr_2[] = {12, 5, 15, 3, 7, 13, 17, 1, -1, -1, 9, -1, -1, -1, 19};

    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int size2 = sizeof(arr_2) / sizeof(arr_2[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);
    Node *root_2 = createBinaryTree(arr_2, size2);

    size1 = count(root_1);
    size2 = count(root_2);

    int *array1 = new int[size1];
    int *array2 = new int[size2];

    BSTtoArray1(root_1, array1);
    BSTtoArray2(root_2, array2);

    displaySortedArray(array1, size1);
    displaySortedArray(array2, size2);

    cout << checkBST(array1, size1) << endl;
    cout << checkBST(array2, size2) << endl;

    deleteBST(root_1);
    delete[] array1;

    deleteBST(root_2);
    delete[] array2;

    return 0;
}
