// 0/1 Knapsack Problem

// Weights and profits of N items, in the form of {profit, weight}
// Put these items in a knapsack of capacity W to get the max total profit in the knapsack.

// Let 𝑠[𝑖,𝑗] be the optimal value for total weight 𝑖 using only the first 𝑗 items

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> &wt, vector<int> &val, int n)
{
    int i, w;
    vector<vector<int>> DP(W + 1, vector<int>(n + 1, 0));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) DP[w][i] = 0;
            else if (wt[i - 1] <= w) DP[w][i] = max(val[i - 1] + DP[w - wt[i - 1]][i - 1], DP[w][i - 1]);
            else DP[w][i] = DP[w][i - 1];
        }
    }
    return DP[W][n];
}

int main()
{
    vector<int> profit = {60, 100, 120, 60};
    vector<int> weight = {5, 20, 30, 2};
    int W = 30;
    int n = profit.size();
    cout << "The maximum value of items that can be taken is: " << knapSack(W, weight, profit, n) << endl;
    return 0;
}
