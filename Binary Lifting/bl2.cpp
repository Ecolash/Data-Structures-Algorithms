// TREE PATH AGGREGATES 
// GCD AGGGREGATES (GCD OF PATHS)
// BINARY LIFTING - 2

// ? u v -> GCD of all nodes on path from u to v

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
ll GCD[N][H];
ll depth[N]; 

void dfs(int u, int p, int d)
{
    par[u][0] = p;
    GCD[u][0] = u;
    depth[u] = d;
    for (int i = 1; i < H; i++)
    {
        par[u][i] = par[par[u][i - 1]][i - 1];
        GCD[u][i] = __gcd(GCD[u][i - 1], GCD[par[u][i - 1]][i - 1]);
    }
    for (auto &x : tree[u]) if (x != p) dfs(x, u, d + 1);
}

ll GCDQuery(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    ll ans = 0;
    for (int i = H - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            ans = __gcd(ans, GCD[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return ans = __gcd(ans, (ll)u);
    for (int i = H - 1; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            ans = __gcd(ans, GCD[u][i]);
            ans = __gcd(ans, GCD[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans = __gcd(ans, (ll)u);
    ans = __gcd(ans, (ll)v);
    ans = __gcd(ans, par[u][0]);
    return ans;
}

void solve()
{
    int x, y;
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
        cin >> x >> y;
        cout << GCDQuery(x, y) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}