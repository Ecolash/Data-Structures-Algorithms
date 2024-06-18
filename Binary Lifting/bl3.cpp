// TREE PATH NODE AGGREGATES 
// BITWISE AGGGREGATES (AND / OR OF PATHS)
// BINARY LIFTING - 3

// 1 u v -> AND of all nodes on path from u to v
// 2 u v -> OR of all nodes on path from u to v

// NOTE : For XOR, just take XOR of paths to u and v from root

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
ll AND[N][H];
ll OR[N][H];
ll depth[N]; 

void dfs(int u, int p, int d)
{
    par[u][0] = p;
    AND[u][0] = u;
    OR[u][0] = u;
    depth[u] = d;
    for (int i = 1; i < H; i++)
    {
        par[u][i] = par[par[u][i - 1]][i - 1];
        AND[u][i] = AND[u][i - 1] & AND[par[u][i - 1]][i - 1];
        OR[u][i] = OR[u][i - 1] | OR[par[u][i - 1]][i - 1];
    }
    for (auto &x : tree[u]) if (x != p) dfs(x, u, d + 1);
}

ll Query(int t, int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    ll ans1 = ~0, ans2 = 0;

    for (int i = H - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            ans1 = ans1 & AND[u][i];
            ans2 = ans2 | OR[u][i];
            u = par[u][i];
        }
    }
    if (u == v)
    {
        ans1 = ans1 & (ll)u;
        ans2 = ans2 | (ll)u;
        ll ans = (t == 1)? ans1 : ans2;
        return ans;
    }
    for (int i = H - 1; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            ans1 = ans1 & AND[u][i] & AND[v][i];
            ans2 = ans2 | OR[u][i] | OR[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans1 = ans1 & u & v & par[u][0];
    ans2 = ans2 | u | v | par[u][0];
    ll ans = (t == 1) ? ans1 : ans2;
    return ans;
}

void solve()
{
    int x, y, t;
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
        cin >> t >> x >> y;
        cout << Query(t, x, y) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}