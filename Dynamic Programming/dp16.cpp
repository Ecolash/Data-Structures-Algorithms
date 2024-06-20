// GRID PATHS (CSES)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using vs = std::vector<string>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

void solve() {
    ll n;
    cin >> n;
    vs grid(n);
    rep(i, 0, n) cin >> grid[i];

    ll DP[n][n];
    memset(DP, 0, sizeof(DP));
    DP[0][0] = (grid[0][0] == '.')? 1 : 0;
    rep(i, 1, n)
    {
        DP[0][i] = (grid[0][i] == '.') ? DP[0][i - 1] : 0;
        if (grid[0][i] != '.') break;
    }

    rep(i, 1, n)
    {
        DP[i][0] = (grid[i][0] == '.') ? DP[i - 1][0] : 0;
        if (grid[i][0] != '.') break;
    }

    rep(i, 1, n) rep(j, 1, n)
    {
        if (grid[i][j] == '.') DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % mod;
        else DP[i][j] = 0;
    }
    cout << DP[n - 1][n - 1];
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}