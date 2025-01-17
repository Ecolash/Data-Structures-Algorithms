// Coin Change 2
// Return the total number of ways to make up the amount

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll DP[N];

ll ways(vector<ll> &coins, ll t)
{
    ll n = coins.size();
    sort(coins.begin(), coins.end());

    ll m = t + 1;
    for (int i = 0; i < n; i++) DP[coins[i]] = 1;
    for (ll i = 1; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i > coins[j]) DP[i] =( DP[i] + DP[i - coins[j]]) % MOD;
            else break;
        }
        // cout << DP[i] << " ";   
    }
    return DP[t];
}

signed main()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    cout << ways(coins, t);
    return 0;
}