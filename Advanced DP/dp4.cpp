// TREE DP
// Given a tree, find sum of distances of all other nodes from a particular node

/*
7
1 2
2 3
2 4
5 4
6 4
1 7
----------------------------
12 + 0 = 12
6 + 3 = 9
0 + 14 = 14
2 + 8 = 10
0 + 15 = 15
0 + 15 = 15
0 + 17 = 17
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
int size[N];
int inDP[N];
int outDP[N];

void dfs1(int u, int p)
{
    size[u] = 1;
    inDP[u] = 0;
    for (auto &x: tree[u]) 
    if (x != p)
    {
        dfs1(x, u);
        size[u] += size[x];
        inDP[u] += (inDP[x] + size[x]);
    }
}

void dfs2(int u, int p)
{
    if (p == 0) outDP[u] = 0;
    else outDP[u] = outDP[p] + inDP[p] - inDP[u] + (n - 2 * size[u]);
    for (auto &x: tree[u])
    if (x != p) dfs2(x, u);
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
    }
    
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++)
    {
        cout << inDP[i] << " + ";
        cout << outDP[i] << " = ";
        cout << outDP[i] + inDP[i] << " ";
        cout << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}