// NUMBERS MADE USING NODE VALUE FROM ROOT TO LEAF

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

void getPathNum(Node *node, int num, vector<int> &pathSums)
{
    if (node == NULL)
        return;

    num = num * 10 + node->data;

    if (node->left == NULL && node->right == NULL)
    {
        pathSums.push_back(num);
        return;
    }

    getPathNum(node->left, num, pathSums);
    getPathNum(node->right, num, pathSums);
}

vector<int> getAllPathNums(Node *root)
{
    vector<int> pathSums;
    if (root == NULL)
        return pathSums;

    getPathNum(root, 0, pathSums);
    return pathSums;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 4, 5, 6, 7, 1, 2};
    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);

    vector<int> pathSum;
    pathSum = getAllPathNums(root_1);
    print_vec(pathSum);

    return 0;
}
