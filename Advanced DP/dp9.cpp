// MAGIC NUMBERS
// CF LINK : https://codeforces.com/contest/628/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
ll mod = 1e9 + 7;
ll MAX = 1e9;

#define mset(m, v) memset(m, v, sizeof(m))


void precompute() {}

ll len;
ll m, k, start;
string strL, strR;
ll DP[2005][2][2][2005];

ll numify(int idx, int lo, int hi, int rem)
{
    if (idx == len)
    {
        if (rem == 0) return 1;
        else return 0;
    }

    if (DP[idx][lo][hi][rem] == -1)
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
            if (idx % 2 == 1)
            {
                if (i != k) continue;
                ll newr = (rem * 10 + i) % m;
                ans = ans + numify(idx + 1, newlo, newhi, newr);
                ans %= mod;
            }
            else if(idx % 2 == 0)
            {
                if (i == k) continue;
                ll newr = (rem * 10 + i) % m;
                ans = ans + numify(idx + 1, newlo, newhi, newr);
                ans %= mod;
            } 
        }
        DP[idx][lo][hi][rem] = ans;
    }
    return DP[idx][lo][hi][rem];
}



void solve() {
    cin >> m >> k;
    cin >> strL >> strR;
    ll l1 = strL.size();
    ll r1 = strR.size();
    ll ex = r1 - l1;
    mset(DP, -1);

    len = r1;
    ll ans = numify(0, 1, 1, 0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    precompute();
    while (t--) solve();
    return 0;
}