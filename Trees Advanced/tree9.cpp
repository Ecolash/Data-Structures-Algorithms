// CSES - COUNTING PATHS
// PARTIAL SUM ON A TREE

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

void add(ll u, ll v)
{
    val[u] += 1;
    val[v] += 1;
    ll l = lca(u, v);
    val[l] -= 1;
    val[par[l][0]] -= 1;
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

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x, y, v;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) tree[i].clear();
    m = n - 1;
    while (m--)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    dfs(1, 0, 0);
    while (q--)
    {
        cin >> x >> y;
        add(x, y);
    }
    addUp(1, 0);
    for (int i = 1; i <= n; i++) cout << val[i] << " ";
    cout << endl;
    return 0;
}