// MINIMUM SPANNING TREE
// KRUSKAL'S ALGORITHM

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back

vvl graph, rev_graph;
vl visited;
queue<ll> topoOrder;
vvl SCCs;

void topoSortDFS(ll node) {
    visited[node] = 1;
    for (auto &neigh : graph[node]) {
        if (!visited[neigh]) topoSortDFS(neigh);
    }
    topoOrder.push(node);
}

void dfs(ll node, vl &component) {
    visited[node] = 1;
    component.pb(node);
    for (auto &neigh : rev_graph[node]) {
        if (!visited[neigh]) dfs(neigh, component);
    }
}

void findSCCs(ll n) {
    visited.assign(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        if (!visited[i]) topoSortDFS(i);
    }

    visited.assign(n + 1, 0);
    while (!topoOrder.empty()) {
        ll node = topoOrder.front();
        topoOrder.pop();
        if (!visited[node]) {
            vl component;
            dfs(node, component);
            SCCs.pb(component);
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    graph.assign(n + 1, vl());
    rev_graph.assign(n + 1, vl());
    SCCs.clear();
    visited.assign(n + 1, 0);
    while (!topoOrder.empty()) topoOrder.pop();

    ll u, v;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u].pb(v);
        rev_graph[v].pb(u);
    }

    findSCCs(n);

    cout << "Number of SCCs: " << SCCs.size() << endl;
    for (auto &component : SCCs) {
        for (auto &node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
