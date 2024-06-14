
#include <iostream>
#include <vector>

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

Node *buildTree(vector<int> &nums, int l, int r)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        Node *node = NewNode(nums[mid]);
        node->left = buildTree(nums, l, mid - 1);
        node->right = buildTree(nums, mid + 1, r);
        return node;
    }
    return NULL;
}

Node *sortedArrayToBST(vector<int> &nums)
{
    return buildTree(nums, 0, nums.size() - 1);
}

void InorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = new Node();

    root = sortedArrayToBST(arr);
    InorderTraversal(root);
    return 1;
}
