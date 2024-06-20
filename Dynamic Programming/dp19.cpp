// ARRAY DESCRIPTION

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
    ll n, m;
    cin >> n >> m;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    ll DP[n][m + 1];
    rep(i, 0, n) rep(j, 0, m + 1) DP[i][j] = 0;

    if (a[0] == 0) rep(j, 1, m + 1) DP[0][j] = 1;
    else DP[0][a[0]] = 1;

    rep(i, 1, n) 
    {
        if (a[i] == 0) {
            rep(j, 1, m + 1)
            {
                DP[i][j] = (DP[i][j] + DP[i - 1][j]) % mod;
                if (j != 1) DP[i][j] = (DP[i][j] + DP[i - 1][j - 1]) % mod;
                if (j != m) DP[i][j] = (DP[i][j] + DP[i - 1][j + 1]) % mod;
            }
        }

        else
        {
            ll j = a[i];
            DP[i][j] = (DP[i][j] + DP[i - 1][j]) % mod;
            if (j != 1) DP[i][j] = (DP[i][j] + DP[i - 1][j - 1]) % mod;
            if (j != m) DP[i][j] = (DP[i][j] + DP[i - 1][j + 1]) % mod;
        }
    }
    // rep(i, 0, n) 
    // {
    //     rep(j, 1, m + 1) cout << DP[i][j] << " ";
    //     cout << "\n";
    // }
    ll ans = 0;
    rep(j, 1, m + 1) ans = (ans + DP[n - 1][j]) % mod;
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}