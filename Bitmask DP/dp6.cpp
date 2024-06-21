// BITMASK DP - 6
// ELEVATOR RIDES (CSES)

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
#define F first 
#define S second

ll n, w;
ll a[20];
pl DP[1 << 20];

void solve() {
    cin >> n >> w;
    rep(i, 0, n) cin >> a[i];

    rep(i, 0, 1 << n) DP[i] = {n + 1, 0};  
    DP[0] = {1, 0}; 

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            pl curr = DP[mask];
            if (curr.S + a[i] <= w) curr.S += a[i];
            else {
                curr.F++;
                curr.S = a[i];
            }
            DP[mask | (1 << i)] = min(DP[mask | (1 << i)], curr);
        }
    }

.0
    cout << DP[(1 << n) - 1].F << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
