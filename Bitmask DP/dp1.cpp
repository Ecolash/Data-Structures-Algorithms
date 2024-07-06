// BITMASK DP - 1
// HAMILTONIAN WALKS FROM CITY 1 TO N

// Hamiltonian Path in a graph G is a path that visits every vertex of G exactly once 
// A Hamiltonian Path doesn’t have to return to the starting vertex.It’s an open path.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<long long>;
using sl = set<ll>;
using ml = map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

// CHECK => mask & (1 << j)
// SET => mask | (1 << j)

const ll N = 20;

ll n, m;
ll dp[N][1 << N];
vl graph[N];

ll ways(ll node, ll mask) {
    if (mask == (1 << n) - 1) {
        if (node == n - 1) return 1; // Reach the last city (0-based index)
        return 0;
    }
    if (dp[node][mask] != -1) return dp[node][mask];
    
    ll ans = 0;
    for (auto v : graph[node]) {
        if (mask & (1 << v)) continue;
        ans += ways(v, mask | (1 << v));
        ans %= mod;
    }
    dp[node][mask] = ans;
    return ans;
}

void solve() {
    cin >> n >> m;
    rep(i, 0, N) rep(j, 0, 1 << N) dp[i][j] = -1;  // Initialize dp table with -1
    rep(i, 0, n) graph[i].clear();
    rep(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        --u, --v; 
        graph[u].pb(v);
        // graph[v].pb(u);
    }
    ll ans = ways(0, 1); // Start from city 1 (0-based index) with mask 1 (first city visited)
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}