// CHECK IF SUM OF ANY PATH EQUAL TO TARGET(PATH SUM 1)

#include <iostream>
#include <queue>
#include "tree0.cpp"

using namespace std;

bool hasPathSum(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    
    if (root->left == NULL && root->right == NULL)
    {
        return target == root->data;
    }

    int X = target - root->data;
    return hasPathSum(root->left, X) || hasPathSum(root->right, X);
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};
    int arr_2[] = {1, 2, 2, 3, 4, 4, 3};

    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int size2 = sizeof(arr_2) / sizeof(arr_2[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);
    Node *root_2 = createBinaryTree(arr_2, size2);

    cout << hasPathSum(root_1, 10) << endl;
    cout << hasPathSum(root_2, 17) << endl;

    return 0;
}
