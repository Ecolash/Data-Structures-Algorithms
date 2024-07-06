// CSES - PLANET QUERIES-2
// MINIMUM TRANSITIONS TO REACH ONE NODE TO ANOTHER

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

const ll N = 2e5+ 5;
const ll H = 32;

ll par[N][H];

void solve() {
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) cin >> par[i][0];
    for (ll j = 1; j < H; ++j)
    for (ll i = 1; i <= n; ++i)
    {
        par[i][j] = par[par[i][j-1]][j-1];
    }
    
    while (q--) 
    {
        ll x, k;
        cin >> x >> k;
        ll ans = x;
        for (ll j = H - 1; j >= 0; --j)
        {
            // cout << ans << " ";
            if (k & (1 << j)) ans = par[ans][j];
        }
        cout << ans << '\n'; 
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}