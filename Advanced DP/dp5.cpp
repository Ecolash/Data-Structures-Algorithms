// TREE DP
// FLIP PATHS
// In a directed tree, select any node to start with
// Find the min no of flips, so that we can reach any other node from that node

/*
7
1 2
2 3
2 4
5 4
6 4
1 7
----------------------------
Node 1 : 2 + 0 = 2
Node 2 : 3 + 0 = 3
Node 3 : 4 + 0 = 4
Node 4 : 4 + 0 = 4
Node 5 : 3 + 0 = 3
Node 6 : 3 + 0 = 3
Node 7 : 3 + 0 = 3
Min cost: 2
*/

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
int inDP[N];
int outDP[N];
map <pl, bool> edges;

void dfs1(int u, int p)
{
    inDP[u] = 0;
    for (auto &x: tree[u]) 
    if (x != p)
    {
        dfs1(x, u);
        inDP[u] += (inDP[x] + edges[mp(u, x)]);
    }
}

void dfs2(int u, int p)
{
    if (p == 0) outDP[u] = 0;
    else outDP[u] = inDP[p] - inDP[u] + edges[mp(u, p)] ;
    for (auto &x: tree[u]) if (x != p) dfs2(x, u);
}


void solve()
{
    int x, y;
    cin >> n;
    for(int i = 1; i <= n; i++) tree[i].clear();
    m = n - 1;
    while(m--)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
        edges[mp(x, y)] = 0;
        edges[mp(y, x)] = 1;
    }
    

    int ans = MAX;
    for(int i = 1; i <= n; i++)
    {
        dfs1(i, 0);
        dfs2(i, 0);
        cout << "Node " << i << " : ";
        cout << inDP[i] << " + ";
        cout << outDP[i] << " = ";
        cout << outDP[i] + inDP[i] << " ";
        ans = min(ans, outDP[i] + inDP[i]);
        cout << "\n";
    }
    cout << "Min cost: "<< ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}