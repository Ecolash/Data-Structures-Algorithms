// ARRAY OF ALL POSSIBLE PATH SUMS

#include <iostream>
#include <queue>
#include <vector>

#include "tree0.cpp"

using namespace std;

void print_vec(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void getPathSums(Node *node, int sum, vector<int> &pathSums)
{
    if (node == NULL)
        return;

    sum = sum + node->data;

    if (node->left == NULL && node->right == NULL)
    {
        pathSums.push_back(sum);
        return;
    }

    getPathSums(node->left, sum, pathSums);
    getPathSums(node->right, sum, pathSums);
}

vector<int> getAllPathSums(Node *root)
{
    vector<int> pathSums;
    if (root == NULL)
        return pathSums;

    getPathSums(root, 0, pathSums);
    return pathSums;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 4, 5, 6, 7, 1, 2};
    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);

    vector<int> pathSum;
    pathSum = getAllPathSums(root_1);
    print_vec(pathSum);

    return 0;
}
