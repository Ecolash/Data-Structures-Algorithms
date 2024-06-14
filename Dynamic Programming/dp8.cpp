#include <bits/stdc++.h>
using namespace std;

/*
Solve the 0/1 Knapsack Problem using a single array space-optimized approach
We can take advantage of the fact that we only need the current and previous states of our DP array. By iterating from the maximum weight down to the minimum weight, we can reuse the same array for the DP values, ensuring that the updates do not affect the values needed for future calculations within the same iteration.

    We use a single-dimensional array DP of size W+1 where DP[w] represents the maximum profit for weight w.
    By iterating from the maximum weight to the minimum weight, we ensure that we do not overwrite
    This works because DP[w] depends on DP[w - wt[i]] which are weights smaller than w
    So filling the array in reverse order we take previous values
    (And new values do not overwrite the previous values until they are needed)
*/

int knapSack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<int> DP(W + 1, 0); 
    for (int i = 0; i < n; i++)
      for (int w = W; w >= wt[i]; w--)
        DP[w] = max(DP[w], val[i] + DP[w - wt[i]]);

    return DP[W]; 
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
