// Takeshi's Castle
// Link : https://www.hackerrank.com/contests/goc-cdc-series-20/challenges/takeshis-castle-2-2


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
vvl graph;

ll mod = 1e9 + 7;
ll MAX = 1e9;

ll n, m, k;
ll ans;

void solve(ll x, ll y, ll val)
{
    ll nval = (graph[x][y] + val) % k;
    if (x == n - 1 and y == m - 1)
    {
        ll x = nval % k;
        if (x == 0) ans++;
        return;
    }
    if (x != n - 1) solve(x + 1, y, nval);
    if (y != m - 1) solve(x, y + 1, nval);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    graph = vvl(n, vl(m, 0));
    for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin >> graph[i][j];

    ans = 0;
    solve(0, 0, 0);
    cout << ans << '\n';
    return 0;
}