// DIGIT DP
// ATCODER DP SERIES - S- DIGIT SUM
// Modification : Instead of finding in range [1, k] find in [L, R]
// 2- SIDED BOUND (only right bound in this case)


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

string strL, strR;
ll d, len;
ll DP[10001][2][2][101];
const ll MOD = 1e9 + 7;

ll rec(ll idx, ll lo, ll hi, ll remainder)
{
    if (idx == len) 
    {
        if (remainder == 0) return 1;
        else return 0;
    }

    if (DP[idx][lo][hi][remainder] == -1) 
    {
        ll ans = 0;
        int s = 0, e = 9;
        if (hi == 1) e = strR[idx] - '0';
        if (lo == 1) s = strL[idx] - '0';
        for (int i = s; i <= e; i++)
        {
            ll newhi = hi, newlo = lo;
            if (i != s) newlo = 0;
            if (i != e) newhi = 0;
            ll newrem = (remainder + i) % d;
            ans = (ans + rec(idx + 1, newlo, newhi, newrem)) % MOD;
        }
        DP[idx][lo][hi][remainder] = ans;
    }
    return DP[idx][lo][hi][remainder];
}

void solve()
{
    cin >> strL;
    cin >> strR;
    cin >> d;
    len = strR.length();
    ll extra = strR.length() - strL.length();
    strL = string(extra, '0') + strL;

    memset(DP, -1, sizeof(DP));
    ll ans = rec(0, 1, 1, 0);
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
