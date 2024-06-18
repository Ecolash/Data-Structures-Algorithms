// TREE PATH EDGE AGGREGATES
// PATH SUM AGGGREGATES
// BINARY LIFTING - 4

// VARIATIONS (XOR, DISTANCE)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vp = std::vector<pl>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

#define pb push_back
#define mp make_pair
const int N = 100005;
const int H = 17;

vp tree[N];
ll depth[N];
ll par[N][H];
ll presum[N];

void dfs(ll u, ll p, ll d, ll sum)
{
    par[u][0] = p;
    depth[u] = d;
    presum[u] = sum;

    for (int i = 1; i < H; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto &x : tree[u])
    {
        ll v = x.first;
        ll w = x.second;
        if (v == p) continue;
        dfs(v, u, d + 1, sum + w);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = H - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) u = par[u][i];
    if (u == v) return u;
    for (int i = H - 1; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
ll query(ll u, ll v)
{
    ll l = lca(u, v);
    ll s = presum[u] + presum[v] - 2 * presum[l];
    return s;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i < n; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        tree[u].pb({v, w});
        tree[v].pb({u, w});
    }

    memset(par, -1, sizeof(par));
    dfs(1, -1, 0, 0); 

    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << query(u, v) << '\n';
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}