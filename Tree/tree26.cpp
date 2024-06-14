// MAX PATH SUM (NODE TO NODE)
// Return max possible sum of any sequence of interconnected nodes

#include <iostream>
#include <queue>
#include "tree0.cpp"

using namespace std;

int maxPath(Node *root, int &maximum)
{
    if (root == NULL)
        return 0;

    int L = max(0, maxPath(root->left, maximum));
    int R = max(0, maxPath(root->right, maximum));
    maximum = max(maximum, L + R + root->data);
    return max(L, R) + root->data;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 4, 5, 6, 7, 1, 2};
    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);
    Node *root = createBinaryTree(arr_1, size1);

    int maximum = INT32_MIN;
    maxPath(root, maximum);
    cout << maximum;
    return 0;
}