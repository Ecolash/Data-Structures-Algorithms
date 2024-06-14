//  Round Trip

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

vvl graph;
vl parent;
vl visited;
vl path;
ll ans, stop;

void dfs(int node, int par) {
    visited[node] = 1;
    for (auto x : graph[node]) 
    {
        if (x == par) continue;
        if (visited[x] == 1) {
            stop = node;
            path.push_back(x);
            ll y = node;
            while (y != x)
            {
                path.push_back(y);
                y = parent[y];
            }
            path.push_back(x);
            return;
        }
        parent[x] = node;
        dfs(x, node);
        if (stop != -1) return;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    parent.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    path.clear();
    stop = -1;

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0) dfs(i, -1);
        if (stop != -1) break;
    }
    if (stop == -1) cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << path.size() << endl;
        for (auto x : path) cout << x << " ";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}