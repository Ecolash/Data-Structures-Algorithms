// SUM OF DISTANCES OF ALL NODES FROM A NODE

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pl>

#define F first
#define S second
#define mp make_pair
#define pb push_back

const int N = 2 * 1e5 + 5;

int n, m;
vl tree[N];
int size_[N];
int inDP[N];
int outDP[N];

void dfs1(int u, int p)
{
    size_[u] = 1;
    inDP[u] = 0;
    for (auto &x: tree[u]) 
    if (x != p)
    {
        dfs1(x, u);
        size_[u] += size_[x];
        inDP[u] += (inDP[x] + size_[x]);
    }
}

void dfs2(int u, int p)
{
    if (p == 0) outDP[u] = 0;
    else outDP[u] = outDP[p] + inDP[p] - inDP[u] + (n - 2 * size_[u]);
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
    for(int i = 1; i <= n; i++) cout << outDP[i] + inDP[i] << " ";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}