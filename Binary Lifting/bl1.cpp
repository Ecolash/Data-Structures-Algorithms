// LOWEST COMMON ANCESTOR OF A ROOTED TREE
// BINARY LIFTING - 1

/*----------------------------------------------------------------
 Step 1 : Bring nodes to same level
 Step 2 : Jump simultaneously till not same

    1
   / \
  2   3      LCA (2 ,3) = 1
 / \   \     LCA (4 ,5) = 2
4   5   6    LCA (6, 5) = 1

*/

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
ll depth[N];

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
        cout << lca(x, y) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}