// UNLIMITED KNAPSACK

#include <bits/stdc++.h>
using namespace std;

int solve(int W, vector<int> &wt, vector<int> &val, vector<int> &ans, int n)
{
    if (ans[W] != -1) return ans[W];
    for (int i = 0; i < n; i++)
    {
        if (W - wt[i] >= 0)
        {
            int x = val[i] + solve(W - wt[i], wt, val, ans, n);
            ans[W] = max(ans[W], x);
        }
        else ans[W] = max(ans[W], 0);
    }
    return ans[W];
}

int main()
{
    int W = 100;
    vector<int> values = {10, 30, 20};
    vector<int> weight = {5, 10, 15};
    int n = values.size();
    vector<int> ans(W + 1, -1);
    cout << "The maximum value of items that can be taken is: " << solve(W, weight, values, ans, n) << endl;
    return 0;
}
