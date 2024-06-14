// PAINT A TREE
// CODEFORCES - 1975D

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

const int N = 2 * 1e5 + 5;

int n, m;
vl tree[N];
int parent[N];
int depth[N];
int maxi;
vl path;

void dfs(int u, int p)
{
    parent[u] = p;
    depth[u] = depth[p] + 1;
    maxi = max(maxi, depth[u]);
    for (auto &x: tree[u]) if (x != p) dfs(x, u);
}

void tracePath(int x, int y)
{
    if (depth[x] > depth[y]) swap(x, y);
    int extra = depth[y] - depth[x];
    path.pb(y);

    while (extra--)
    {
        y = parent[y];
        path.pb(y);
    }
    if (y == x) return;
    vl xpath;
    xpath.pb(x);

    while (parent[x] != parent[y])
    {
        x = parent[x];
        y = parent[y];
        path.pb(y);
        xpath.pb(x);
    }

    path.pb(parent[y]);
    reverse(xpath.begin(), xpath.end());
    for (int i : xpath) path.pb(i);
    return;
}

void solve()
{
    int a, b, x, y;
    cin >> n;
    cin >> a >> b;

    for(int i = 1; i <= n; i++) tree[i].clear();
    path.clear();
    depth[0] = -1;
    m = n - 1;
    while(m--)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    
    if (a == b)
    {
        maxi = 0;
        dfs(a, 0);
        cout << 2 * (n - 1) - maxi << endl;
        return;
    }

    dfs(1, 0);
    tracePath(a, b);
    ll s = path.size();
    depth[0] = -1;

    if(path[0] != a) reverse(path.begin(),path.end());
    int v = path[(s - 1) / 2];
    maxi = 0;
    dfs(v, 0);
    ll ans = 2 * (n - 1) - maxi + s/2;
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}