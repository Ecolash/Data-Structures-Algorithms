// ----------------------------------------------------------------
// CSES - FLIGHT ROUTES

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using vp = std::vector<pl>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

ll mod = 1e9 + 7;
ll MAX = 1e18;
ll n, m, k;

const int N = 1e5 + 5;
vp graph[N];
priority_queue<ll> dist[N];

void solve() {
    cin >> n >> m >> k;
    rep(i, 0, m) 
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].pb(mp(v, w));
    }
    
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, 1});
    dist[1].push(0);
    
    while (!pq.empty()) {
        pl x = pq.top();
        ll d = x.first, u = x.second;
        pq.pop();
        
        if (dist[u].top() < d) continue; 
        for (auto &y : graph[u]) {
            ll v = y.first;
            ll w = y.second;
            ll new_dist = d + w;
            if (dist[v].size() < k || new_dist < dist[v].top()) 
            {
                if (dist[v].size() == k) dist[v].pop();
                dist[v].push(new_dist);
                pq.push({new_dist, v});
            }
        }
    }
    
    vector<ll> result;
    while (!dist[n].empty()) 
    {
        result.pb(dist[n].top());
        dist[n].pop();
    }
    sort(result.begin(), result.end());
    for (ll d : result)  cout << d << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}
