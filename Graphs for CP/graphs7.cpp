/* TOPOLOGICAL SORT APPLICATION
Finding the longest path in a Directed Acyclic Graph (DAG)
============================================================================
It can be efficiently achieved using topological sorting
We then do DP on the topologically sorted nodes from the end
We update the DP as DP[i] = max(1 , 1 + DP[neighbors : i])
Since we process from back,  DP[neighbors : i] is already computed
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
#define pb push_back
#define mset(m, v) memset(m, v, sizeof(m))

vvl graph;
vl dist;
vl topo_order;
vl indegree;
int n, m;

void topological_sort() {
    queue<int> q;
    for (int i = 1; i <= n; ++i)  if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo_order.pb(node);
        for (auto neighbor : graph[node]) 
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }
}

void findPath() {
    dist.assign(n + 1, 1);
    topological_sort();
    reverse(topo_order.begin(), topo_order.end());
    for (auto node : topo_order)
    {
        for (auto v : graph[node])
        dist[node] = max(dist[node], dist[v] + 1);  
    }

    ll maxi = *max_element(dist.begin() + 1, dist.end());
    cout << "Longest Path Length: " << maxi << endl;
}

void solve() {
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    indegree.assign(n + 1, 0);

    int a, b;
    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        indegree[b]++;
    }

    findPath();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
