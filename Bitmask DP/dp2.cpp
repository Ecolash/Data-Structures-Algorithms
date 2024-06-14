// BITMASK DP - 2
// SHORTEST HAMILTONIAN WALK FOR CITY 1 TO N IN WEIGHTED GRAPH

/*
1
4 6
1 2 10
2 3 20
3 4 30
1 4 15
1 3 15
2 4 5
*/

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

ll n, m;
ll dp[N][1 << N];
vector<pl> graph[N];

int shortest_walk(int node, int mask)
{
    if (mask == (1 << n) - 1) {
        if (node == n - 1) return 0; 
        return MAX;
    }
    if (dp[node][mask] != -1) return dp[node][mask];
    
    int ans = MAX;
    for (auto p : graph[node]) {
        int v = p.first;
        int w = p.second;
        if (mask & (1 << v)) continue;
        ans = min(ans, w + shortest_walk(v, mask | (1 << v)));
    }
    dp[node][mask] = ans;
    return ans;
}

void solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n) graph[i].clear();
    rep(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v; 
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    ll ans = shortest_walk(0, 1); 
    if (ans >= MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}