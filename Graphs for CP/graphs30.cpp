// MINIMUM SPANNING TREE
// KRUSKAL'S ALGORITHM
//-----------------------------
// CSES - ROAD CONSTRUCTION

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll maxi, curr;
const ll N = 1e5 + 5;
ll par[N];
ll cnt[N];

ll find(ll x)
{
    if (x != par[x]) par[x] = find(par[x]);
    return par[x];
}

void merge(ll a, ll b)
{
    ll x = find(a);
    ll y = find(b);
    if (x != y)
    {
        if (cnt[x] > cnt[y]) swap(x, y);
        par[x] = y;
        cnt[y] += cnt[x];
        curr--;
        maxi = max(maxi, cnt[y]);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    
    for (ll i = 0; i <= n; ++i) par[i] = i, cnt[i] = 1;
    vector<pl> edges(m);
    curr = n; maxi = 1;
    for(ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (find(u) != find(v)) merge(u, v);
        cout << curr << " " << maxi << '\n';
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}