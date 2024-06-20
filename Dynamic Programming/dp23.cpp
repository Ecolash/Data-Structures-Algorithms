// CSES Problem Set
// Removal Game

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

// Let DP(i, j) denote the diff b/w the score of P1 and P2
// DP(i, j) = Sp1 - Sp2

void solve() {
    ll n, sum = 0;
    cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) sum += a[i];

    ll DP[n][n];
    memset(DP, 0, sizeof(DP));
    rep(i, 0, n) DP[i][i] = a[i];

    for(int s = 1; s < n; s++) 
    {
        for(int i = 0; i < n; i++)
        {
            int j = i + s;
            if(j >= n) break;
            DP[i][j] = max(a[j] - DP[i][j - 1], a[i] - DP[i + 1][j]);
        }
    }
    // rep(i, 0, n) 
    // {
    //     rep(j, 0, n) cout << DP[i][j] << " ";
    //     cout << "\n";
    // }
    ll x = DP[0][n - 1];    // a - b
    ll y = sum;             // a + b
    cout << (x + y) / 2;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}