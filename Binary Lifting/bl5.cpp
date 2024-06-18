// TREE PATH NODE AGGREGATES
// PARTIAL SUM OF NODES 
// BINARY LIFTING - 5

// Initially all nodes in the tree have value 0
// + X U V -> add X to all nodes on path from U to V
// Print values of nodes after Q updates


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pair<ll, ll>>
ll MAX = 1e9;

#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))
#define mp make_pair
#define pb push_back

const int N = 2 * 1e5 + 5;
const int H = 20;

int n, m, q;
vl tree[N];
ll par[N][H];
ll depth[N], val[N];

void dfs(int u, int p, int d)
{
    par[u][0] = p;
    depth[u] = d;
    for (int i = 1; i < H; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto &x : tree[u]) if (x != p) dfs(x, u, d + 1);
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

// For [u , v] = [u, l] + [v, l) (include LCA once)
// So -x will happen at LCA and parent of LCA

void add(ll u, ll v, ll x)
{
    val[u] += x;
    val[v] += x;
    ll l = lca(u, v);
    val[l] -= x;
    val[par[l][0]] -= x;
}

void addUp(ll u, ll p)
{
    for (auto v : tree[u])
    {
        if (v == p) continue;
        addUp(v, u);
    }
    val[p] += val[u];
}

void solve()
{
    int x, y, v;
    cin >> n;

    for (int i = 1; i <= n; i++) tree[i].clear();
    m = n - 1;
    while (m--)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    dfs(1, 0, 0);
    cin >> q;
    while (q--)
    {
        cin >> x >> y >> v;
        add(x, y, v);
    }
    addUp(1, 0);
    for (int i = 1; i <= n; i++) cout << val[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}