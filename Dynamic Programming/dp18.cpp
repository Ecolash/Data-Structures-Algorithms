// BOOK SHOP (CSES)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

void solve() {
    ll n, k;
    cin >> n >> k;
    vl cost(n), pages(n);
    rep(i, 0, n) cin >> cost[i];
    rep(i, 0, n) cin >> pages[i];

    ll DP[k + 1];
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < n; i++)
    for (int w = k; w >= cost[i]; w--)
     DP[w] = max(DP[w], pages[i] + DP[w - cost[i]]);

    cout << DP[k];
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}