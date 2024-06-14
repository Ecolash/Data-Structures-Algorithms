// Coin Change 1
// Return the fewest number of coins that you need to make up that amount

#include <bits/stdc++.h>
using namespace std;

int min_coin(vector<int> &coins, int amount)
{
    int n = coins.size();
    int m = amount + 1;
    vector<int> dp(m, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= coins[j])
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[amount] != m)
        return dp[amount];

    return -1;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << min_coin(coins, t);
    return 0;
}