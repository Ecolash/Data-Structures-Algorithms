// Coin Change 1
// Return the fewest number of coins that you need to make up that amount

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 5;
ll DP[N];

ll minimize(vector<ll> &coins, ll t)
{
    ll n = coins.size();
    sort(coins.begin(), coins.end());

    ll m = t + 1;
    for (ll i = 0; i < m; i++) DP[i] = 1e9;

    DP[0] = 0;
    for (ll i = 1; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i >= coins[j]) DP[i] = min(DP[i], 1 + DP[i - coins[j]]);
            else break;
        }
        // cout << DP[i] << " ";   
    }

    if (DP[t] != 1e9) return DP[t];
    return -1;
}

signed main()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    cout << minimize(coins, t);
    return 0;
}