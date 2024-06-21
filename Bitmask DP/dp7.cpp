// COUNTING TILINGS (CSES)

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

ll n, m;
ll dp[1005][1 << 11];
void genNext(int curr, int newMask, int j, vl &nextMask)
{
    if (j == n)
    {
        nextMask.push_back(newMask);
        return;
    }
    if (j + 1 < n and (((1 << j) & (curr)) == 0) and (((1 << (j + 1)) & (curr)) == 0)) genNext(curr, newMask, j + 2, nextMask);    // Place a 2 x 1 tile
    if ((((1 << j) & (curr)) == 0)) genNext(curr, newMask + (1 << j), j + 1, nextMask);                                            // Place a 1 x 2 tile
    if ((((1 << j) & (curr)) != 0)) genNext(curr, newMask, j + 1, nextMask);                                                       // Move to next if filled
}

ll count(int col, int mask) {
    if (col == m)
    {
        if (mask == 0) return 1; // No overflow of tiles
        else return 0;
    }

    if(dp[col][mask]!= -1) return dp[col][mask];

    ll ans = 0;
    vl nextMask;
    genNext(mask, 0, 0, nextMask);
    for(auto i : nextMask)
    {
        ans += count(col + 1, i);
        ans %= mod;
    }
    return dp[col][mask] = ans;
}

void solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << count(0, 0) << "\n";    
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}