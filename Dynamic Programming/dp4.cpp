// Coin Change 2
// Return the total number of ways to make up the amount

#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int n;
    cout << "Enter the amount: ";
    cin >> n;

    vector<int> coins = {6, 2, 5};
    cout << change(n, coins);
    return 0;
}