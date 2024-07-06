// KOSARAJO'S ALGORITHMS APPLICATION
// CSES - FLIGHT ROUTES CHECK

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back

vvl g1, g2;
vl visited;
vl indegree;
vl topo;
vl SCCs;

void topoSortDFS(int u)
{
    visited[u] = 1;
    for (int v : g1[u]) if (!visited[v]) topoSortDFS(v);
    topo.pb(u);
}

void dfs1(int u)
{
    visited[u] = 1;
    for (int v : g2[u]) if (!visited[v]) dfs1(v);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    g1.assign(n + 1, vl());
    g2.assign(n + 1, vl());

    indegree.assign(n + 1, 0);
    visited.assign(n + 1, 0);

    ll u, v;
    for (ll i = 0; i < m; ++i) 
    {
        cin >> u >> v;
        indegree[v]++;
        g1[u].pb(v);
        g2[v].pb(u);
    }

    for (ll i = 1; i <= n; ++i) if (!visited[i]) topoSortDFS(i);
    reverse(topo.begin(), topo.end());
    visited.assign(n + 1, 0);
    for (int u : topo)
    {
        if (!visited[u])
        {
            dfs1(u);
            SCCs.pb(u);
        }
    }
    if (SCCs.size() > 1)
    {
        cout << "NO" << endl;
        cout << SCCs[1] << " " << SCCs[0] << endl;
    }
    else cout << "YES" << endl;
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