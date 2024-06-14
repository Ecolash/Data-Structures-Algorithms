// DIGIT DP
// ATCODER DP SERIES - S- DIGIT SUM
// 1- SIDED BOUND (only right bound in this case)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<long long>;
using vp = vector<pl>;
using vs = vector<string>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define po pop_back 

string str;
ll d, len;
ll DP[10001][2][101];
const ll MOD = 1e9 + 7;

ll rec(ll idx, ll lo, ll hi, ll remainder)
{
    if (idx == len) 
    {
        if (remainder == 0) return 1;
        else return 0;
    }

    if (DP[idx][hi][remainder] == -1) 
    {
        ll ans = 0;
        int s = 0;
        int e = 9;
        if (hi == 1) e = str[idx] - '0';
        for (int i = s; i <= e; i++)
        {
            ll newhi = hi;
            if (i != e) newhi = 0;
            ll newrem = (remainder + i) % d;
            ans = (ans + rec(idx + 1, lo, newhi, newrem)) % MOD;
        }
        DP[idx][hi][remainder] = ans;
    }
    return DP[idx][hi][remainder];
}

void solve()
{
    cin >> str >> d;
    len = str.length();
    memset(DP, -1, sizeof(DP));
    ll ans = rec(0, 1, 1, 0);
    ans = (ans + MOD - 1) % MOD; // exclude 0
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
