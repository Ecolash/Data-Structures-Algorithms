// CSES - PLANETS AND ITS KINGDOM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using vvl = std::vector<vl>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

ll n, m;
vvl g1, g2;
vl topo;
vl vis1, vis2;
vl kingdom;

void topoSort(int i)
{
    vis1[i] = 1;
    for (auto j : g1[i]) if (!vis1[j]) topoSort(j);
    topo.pb(i);
}

void dfs(int i, ll k)
{
    vis2[i] = 1;
    kingdom[i] = k;
    for (auto j : g2[i]) if (!vis2[j]) dfs(j, k);
    return;
}


void solve() {
    cin >> n >> m;
    g1.resize(n + 1);
    g2.resize(n + 1);
    rep(i, 0, m) 
    {
        ll u, v;
        cin >> u >> v;
        g1[u].pb(v);
        g2[v].pb(u);
    }
    
    topo.clear();
    vis1.assign(n + 1, 0);
    kingdom.assign(n + 1, 0); 
    
    rep(i, 1, n + 1) if (!vis1[i]) topoSort(i);
    reverse(topo.begin(), topo.end());
    
    vis2.assign(n + 1, 0);
    ll c = 1;
    for(auto i : topo) if (!vis2[i]) {dfs(i , c); c++;}
    cout << c - 1 << endl;
    for(int i = 1; i <= n; i++) cout << kingdom[i] << " ";
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}