// DIGIT DP
// Google-KickStart/2020/Round H/Boring Numbers

//  Number is called boring if all digits at even positions are even & all of the digits at odd positions are odd.
//  Ron wants to count how many numbers in the range [L, R] (L and R inclusive) are boring
//  DP[i][lo][hi][start] = (#digits, left flag, right flag, first non-zero digit)

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
ll DP[20][2][2][20]; 
const ll MOD = 1e9 + 7;

/* ----------------------------------------------------------------
    We generate our trie to have only boring numbers
    If odd position => 1, 3, 5, 7, 9
    If even position => 0, 2, 4, 6, 8
*/

ll rec(ll idx, ll lo, ll hi, ll start)
{
    if (idx == len) return 1;

    if (DP[idx][lo][hi][start] == -1) 
    {
        ll ans = 0;
        int s = 0, e = 9;
        if (hi == 1) e = strR[idx] - '0';
        if (lo == 1) s = strL[idx] - '0';
        if (idx < start) e = 0;
        for (int i = s; i <= e; i++)
        {
            if ((idx >= start) and (idx - start - i + 1) % 2 == 1) continue;
            ll newhi = hi, newlo = lo;
            if (i != s) newlo = 0;
            if (i != e) newhi = 0;
            ans = ans + rec(idx + 1, newlo, newhi, start);
        }
        DP[idx][lo][hi][start] = ans;
    }
    return DP[idx][lo][hi][start];
}

void solve()
{
    ll L, R;
    cin >> L >> R;
    strL = to_string(L);
    strR = to_string(R);

    /*
    =========================================================
    ---------------------------------------------------------
    Here prepending the zeroes at start in not a good idea
    Because it will change the odd and even positions
    But we can handle it by keeping an extra state
    ==========================================================
    */

    len = strR.length();
    ll extra = strR.length() - strL.length();
    strL = string(extra, '0') + strL;
    cout << strL << " " << strR << endl;

    memset(DP, -1, sizeof(DP));
    ll ans = 0;
    for (int  i = 0; i < len; i++) ans += rec(0,1,1,i);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
