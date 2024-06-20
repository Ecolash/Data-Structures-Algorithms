// Coin Change 2
// Return the total number of ordered ways to make up the amount 

// 9 = 2 + 2 + 5 = 2 + 5 + 2 (considered same order)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll DP[N];

ll ways(vector<ll> &coins, ll t)
{
    ll n = coins.size();
    fill(DP, DP + n, 0);
    DP[0] = 1;
    for (ll j = 0; j < n; j++)
    {
        for (ll i = coins[j]; i <= t; i++)
        {
            DP[i] = (DP[i] + DP[i - coins[j]]) % MOD;
        }
    }
    return DP[t];
}

int main()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    cout << ways(coins, t);
    return 0;
}
