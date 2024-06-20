// REMOVING DIGITS (CSES)

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

const ll N = 1e6 + 5;
ll DP[N];
void solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n + 2; i++) DP[i] = MAX;
    DP[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        ll x = i, d;
        while (x > 0)
        {
            d = x % 10;
            x /= 10;
            DP[i] = min(1 + DP[i - d], DP[i]);
        }
    }
    cout << DP[n];
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}