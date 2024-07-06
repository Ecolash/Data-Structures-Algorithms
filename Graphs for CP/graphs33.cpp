// KOSARAJO'S ALGORITHMS
// STRONGLY CONNECTED COMPONENTS FOR DIRECTED GRAPHS
// ----------------------------------------------------------------
// Every node can be visited from every other node 
// IDEA : Tf we reverse all edges, we can still traverse all components if it is SCC

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back

vvl graph, rev_graph;
vl visited;
stack<ll> st;
vvl SCCs;

void dfs1(ll node) {
    visited[node] = 1;
    for (auto &neigh : graph[node]) {
        if (!visited[neigh]) dfs1(neigh);
    }
    st.push(node);
}

void dfs2(ll node, vl &component) {
    visited[node] = 1;
    component.pb(node);
    for (auto &neigh : rev_graph[node]) {
        if (!visited[neigh]) dfs2(neigh, component);
    }
}

void findSCCs(ll n) {
    visited.assign(n + 1, 0);
    for (ll i = 1; i <= n; ++i)  if (!visited[i]) dfs1(i);

    visited.assign(n + 1, 0);
    while (!st.empty()) {
        ll node = st.top();
        st.pop();
        if (!visited[node]) {
            vl component;
            dfs2(node, component);
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
    while (!st.empty()) st.pop();

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