// APPLICATION OF MAPS
// MERGING SIMILAR ITEMS

#include <bits/stdc++.h>
using namespace std;

void print_vec_vec(vector<vector<int>> v)
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        int n = v[i].size();
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << " | ";
    }
}

vector<vector<int>> mergeSimilarItems(vector<vector<int>> items1, vector<vector<int>> items2)
{
    vector<vector<int>> ans;
    map<int, int> m;
    int n1 = items1.size();
    int n2 = items2.size();

    for (int i = 0; i < n1; i++) m[items1[i][0]] = items1[i][1];
    for (int j = 0; j < n2; j++) m[items2[j][0]] = m[items2[j][0]] + items2[j][1];
    for (auto it : m) ans.push_back({it.first, it.second});
    return ans;
}

int main()
{
    vector<vector<int>> items1 = {{1, 4}, {3, 4}, {2, 1}, {4, 3}, {6, 1}};
    vector<vector<int>> items2 = {{2, 4}, {3, 4}, {2, 3}, {4, 5}, {5, 1}};
    vector<vector<int>> items_merge = mergeSimilarItems(items1, items2);
    print_vec_vec(items1);
    print_vec_vec(items2);
    print_vec_vec(items_merge);
    return 0;
}