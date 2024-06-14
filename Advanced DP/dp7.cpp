// TREE DP
// DISTANCE BETWEEN NODES
// Find number of node pairs exactly at distance k from each other


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pl>
ll MAX = 1e9;

#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))
#define mp make_pair
#define pb push_back

const ll N = 50005;
const ll K = 501;

ll n, k;
vl tree[N];
ll parent[N];
ll inDP[N][K];
ll outDP[N][K];

void dfs1(ll u, ll p)
{
    inDP[u][0] = 1;
    parent[u] = p;
    for (auto &x : tree[u])
    {
        if (x == p) continue;
        dfs1(x, u);
        for (int i = 0; i < k; i++) inDP[u][i + 1] += inDP[x][i];
    }
}

void dfs2(ll u, ll p)
{
    outDP[u][k] = 0;
    for (auto &x : tree[u])
    {
        if (x == p) continue;
        for (ll i = 1; i < k; i++) outDP[u][k] += inDP[x][i - 1] * (inDP[u][k - i] - inDP[x][k - i - 1]);
    }

    outDP[u][k] /= 2;
    for (auto &x : tree[u])
    {
        if (x == p) continue;
        dfs2(x, u);
    }
}

void solve()
{
    ll x, y;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) tree[i].clear();
    ll m = n - 1;
    while(m--)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        // cout << "Node " << i << " : ";
        // cout << inDP[i][k] << " + ";
        // cout << outDP[i][k] << " = ";
        // cout << outDP[i][k] + inDP[i][k] << endl;
        ans += (outDP[i][k] + inDP[i][k]);
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}