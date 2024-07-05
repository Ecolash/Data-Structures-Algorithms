#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

vl tree[N];
ll DP[N][2];

void dfs(ll n, ll p)
{
    DP[n][0] = 1;
    DP[n][1] = 1;
    for (auto u : tree[n])
    {
        if (u == p) continue;
        dfs(u, n);
        DP[n][0] *= (DP[u][0] + DP[u][1]) % mod;
        DP[n][1] *= DP[u][0];
        DP[n][0] %= mod;
        DP[n][1] %= mod;
    }
}

int main()
{
    ll n;
    cin >> n;
    ll x, y;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    cout << (DP[1][0] + DP[1][1]) % mod << endl;
    return 0;
}