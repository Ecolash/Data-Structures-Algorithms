// ARRAY OF ALL POSSIBLE PATH SUMS

#include <iostream>
#include <queue>
#include <vector>

#include "tree0.cpp"

using namespace std;

void print_paths(vector<vector<int>> v)
{
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        int n = v[i].size();
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " --> ";
        }
        cout << "NULL" << endl;
    }
    cout << "---------------------------------------" << endl;
}

void getPath(Node *root, int target, vector<int> &path, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);
    if (root->data == target && root->left == NULL && root->right == NULL)
    {
        ans.push_back(path);
    }

    int x = target - root->data;
    getPath(root->left, x, path, ans);
    getPath(root->right, x, path, ans);

    path.pop_back();
}

vector<vector<int>> pathSum(Node *root, int target)
{
    vector<int> path;
    vector<vector<int>> ans;

    getPath(root, target, path, ans);
    return ans;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 4, 5, 6, 7, 1, 2};
    int size1 = sizeof(arr_1) / sizeof(arr_1[0]);

    Node *root_1 = createBinaryTree(arr_1, size1);
    int target = 16;

    vector<vector<int>> ans;
    ans = pathSum(root_1, target);
    print_paths(ans);

    return 0;
}
