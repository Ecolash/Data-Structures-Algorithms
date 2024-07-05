// CYCLLE DETECTION IN DIRECTED GRAPH
// CSES - ROUND TRIP-2

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
ll stop;

void dfs(int node) {
    visited[node] = 1;
    for (auto x : graph[node]) {
        if (visited[x] == 2) continue; // Ignore fully processed nodes
        if (visited[x] == 1) { // Cycle detected
            stop = x;
            path.push_back(x);
            ll y = node;
            while (y != x) {
                path.push_back(y);
                y = parent[y];
            }
            path.push_back(x);
            return;
        }
        parent[x] = node;
        dfs(x);
        if (stop != -1) return;
    }
    visited[node] = 2; // Mark node as fully processed
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
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) dfs(i);
        if (stop != -1) break;
    }

    if (stop == -1) cout << "IMPOSSIBLE" << endl;
    else {
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto x : path) cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
