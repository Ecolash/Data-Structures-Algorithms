// PASCALS'S TRIANGLE

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n)
{
    vector<vector<int>> ans;

    ans.push_back({1});
    if (n == 1)
        return ans;

    ans.push_back({1, 1});
    if (n == 2)
        return ans;

    for (int i = 3; i <= n; i++)
    {
        vector<int> v(i);
        v[0] = ans[i - 2][0];
        for (int j = 1; j < i - 1; j++)
        {
            v[j] = ans[i - 2][j - 1] + ans[i - 2][j];
        }
        v[i - 1] = ans[i - 2][i - 2];
        ans.push_back(v);
    }

    return ans;
}

void print_vec_vec(vector<vector<int>> v)
{
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        int n = v[i].size();
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter the value of no. of rows: ";
    cin >> n;

    vector<vector<int>> dp = generate(n);
    print_vec_vec(dp);
    return 0;
}
