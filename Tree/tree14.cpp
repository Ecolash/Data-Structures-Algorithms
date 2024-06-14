// CHECK IF A TREE IS BST

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

bool isSubtreelesser(Node *root, int value)
{
    if (root == NULL)
        return true;

    if (root->data <= value && isSubtreelesser(root->left, value) && isSubtreelesser(root->right, value))
        return true;

    return false;
}

bool isSubtreegreater(Node *root, int value)
{
    if (root == NULL)
        return true;

    if (root->data >= value && isSubtreegreater(root->left, value) && isSubtreegreater(root->right, value))
        return true;

    return false;
}

bool checkBST(Node *root, int min, int max)
{
    // Integer min and max marks the range of possible data values in node

    if (root == NULL)
        return true;

    if (isSubtreelesser(root->left, root->data) && isSubtreegreater(root->right, root->data) && checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max))
        return true;

    else
        return false;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};
    int arr_2[] = {7, 4, 9, 1, 6, -1, -1};

    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int size2 = sizeof(arr_2) / sizeof(arr_2[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);
    Node *root_2 = createBinaryTree(arr_2, size2);

    cout << checkBST(root_1, INT16_MIN, INT16_MAX) << endl;
    cout << checkBST(root_2, INT16_MIN, INT16_MAX) << endl;
    return 0;
}
