// CHECK IF A TREE IS SYMMETRIC ( mirror images )

#include <iostream>
#include <queue>
#include "tree0.cpp"

using namespace std;

bool isSymmetric(Node *root)
{
    Node *p = root->left;
    Node *q = invert(root->right);
    return isSameTree(p, q);
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};
    int arr_2[] = {1, 2, 2, 3, 4, 4, 3};

    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int size2 = sizeof(arr_2) / sizeof(arr_2[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);
    Node *root_2 = createBinaryTree(arr_2, size2);

    cout << isSymmetric(root_1) << endl;
    cout << isSymmetric(root_2) << endl;

    return 0;
}
