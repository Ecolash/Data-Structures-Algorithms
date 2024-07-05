// CSES - INVESTIGATION
// DJIKSTRA IMPLEMENTATION

// COUNT OF NUMBER OF SMALLEST PATH
// MAX NUMBER OF NODES IN SMALLEST PATH
// MIN NUMBER OF NODES IN SMALLEST PATH

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using ppl = pair<pl, pl>;
using vp = std::vector<pl>;

const ll N = 1e5 + 5;
ll mod = 1e9 + 7;
ll MAX = 1e18;

ll n, m;
vp graph[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    vl dist(n + 1, MAX);
    vl cnt(n + 1, 0);
    vl mini(n + 1, MAX);
    vl maxi(n + 1, 0);

    priority_queue<pl> Q;
    Q.push({0, 1});
    dist[1] = 0;
    cnt[1] = 1;
    mini[1] = maxi[1] = 0;

    while(!Q.empty())
    {
        pl x = Q.top();
        Q.pop();
        ll d = -x.first;
        ll u = x.second;

        if (d > dist[u]) continue;
        for(auto &x : graph[u])
        {
            ll v = x.first;
            ll w = x.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mini[v] = mini[u] + 1;
                maxi[v] = maxi[u] + 1;
                Q.push({-dist[v], v});
            }
            else if (dist[u] + w == dist[v])
            {
                cnt[v] = (cnt[v] + cnt[u]) % mod;
                mini[v] = min(mini[v], mini[u] + 1);
                maxi[v] = max(maxi[v], maxi[u] + 1);
            }
        }
    }
    cout << dist[n] << " ";
    cout << cnt[n] << " ";
    cout << mini[n] << " ";
    cout << maxi[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}