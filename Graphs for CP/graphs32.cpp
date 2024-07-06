// MINIMUM SPANNING TREE - KRUSKAL'S ALGORITHM
// ROAD & PLANT CONSTRUCTION

// N nodes - cost of converting ith node to plant is C[i]
// We want to ensure that each node is plant or connected to a plant by road

/*
5 4
5 5 5 5 5
1 3 5
2 3 10
3 4 100
4 5 2
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

const int N = 1e5 + 5;
int par[N];
int cnt[N];

int find(int x)
{
    if (x != par[x]) par[x] = find(par[x]);
    return par[x];
}

void merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        if (cnt[x] > cnt[y]) swap(x, y);
        par[x] = y;
        cnt[y] += cnt[x];
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vl c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i <= n; ++i) par[i] = i, cnt[i] = 1;

    vector<pair<ll,pl>> edges;
    for(int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    // Create a supernode 0 and connect to all other nodes
    for(int i = 1; i <= n; i++) edges.push_back({c[i], {0 , i}});
    sort(edges.begin(), edges.end());
    
    ll ans = 0;
    for(auto edge : edges)
    {
        ll w = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;
        
        if (find(u) != find(v))
        {
            merge(u, v);
            ans += w;
        }
    }

    cout << ans << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}