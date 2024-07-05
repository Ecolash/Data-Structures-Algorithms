// CSES - GAME ROUTE
// TOPOLOGICAL SORT APPLICATION 
// COUNT OF DISTINCT PATHS FROM 1 TO N

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

ll n, m;
vector<vl> graph;
vl indegree;
vl ans, path;

void topo() 
{
    queue<ll> Q;
    for (ll i = 1; i <= n; i++) if (indegree[i] == 0) Q.push(i);
    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop();
        ans.push_back(u);
        for (auto v : graph[u])
        {
            indegree[v]--;
            if (indegree[v] == 0) Q.push(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    graph.resize(n + 1);
    indegree.resize(n + 1);
    
    for (ll i = 0; i < m; i++) 
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    vl DP(n + 1, 0);
    topo();
    DP[1] = 1;
    for(auto x : ans)
    {
        for(auto y : graph[x])
        {
            DP[y] = (DP[y] + DP[x]) % mod;
        }
    }
    cout << DP[n] << endl;
}


signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}