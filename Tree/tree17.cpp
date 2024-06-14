// INORDER SUCCESSOR IN A BST

// Inorder Traversal : Time Complexity = O(n)
// Inorder Successor : Time Complexity = O(h)

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

int main()
{
    int arr[] = {12, 5, 15, 3, 7, 13, 17, 1, -1, -1, 9, -1, -1, -1, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, size);

    cout << "Enter node value to find its Inorder Successor: ";

    int x;
    cin >> x;
    Node *node = Search(root, x);
    Node *successor = inorderSuccessor(root, node);

    cout << "Inorder Successor is: " << successor->data << endl;

    // InorderTraversal(root); // PROOF

    deleteBST(root);
    return 0;
}
