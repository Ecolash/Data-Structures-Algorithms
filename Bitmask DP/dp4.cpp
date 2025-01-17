// BITMASK DP - 4
// HAMILTONIAN CYCLES FOR A NODE N

// Hamiltonian Cycle in a graph G is a path that visits every vertex of G exactly once and returns back to start


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

const int N = 15;

ll n, m, start;
ll dp[N][1 << N];
vl graph[N];

int ways(int node, int mask) {
    if (mask == (1 << n) - 1) {
        bool f = 0;
        for(auto v : graph[node]) if(v == start) f = 1;
        if (f) return 1;
        return 0;
    }
    if (dp[node][mask] != -1) return dp[node][mask];
    
    int ans = 0;
    for (auto v : graph[node]) {
        if (mask & (1 << v)) continue;
        ans += ways(v, mask | (1 << v));
    }
    dp[node][mask] = ans;
    return ans;
}

void solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n) graph[i].clear();
    rep(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        --u, --v; 
        graph[u].pb(v);
        graph[v].pb(u);
    }
    cin >> start;
    --start;
    int ans = ways(start, 1); 
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}