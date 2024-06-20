// Rectangle Cutting (CSES)

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

ll DP[505][505];

void solve() {
    ll a, b;
    cin >> a >> b;
    rep(i, 0, a + 1) rep(j, 0, b + 1) DP[i][j] = MAX; 
    
    ll x = min(a, b);
    rep(i, 0, x + 1) DP[i][i] = 0;
    rep(i, 1, a + 1)
    {
        rep(j, 1, b + 1)
        {
            rep(c, 1, i/2 + 1) DP[i][j] = min(DP[i][j], 1 + DP[i - c][j] + DP[c][j]);
            rep(c, 1, j/2 + 1) DP[i][j] = min(DP[i][j], 1 + DP[i][j - c] + DP[i][c]);
            // cout << DP[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << DP[a][b] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}