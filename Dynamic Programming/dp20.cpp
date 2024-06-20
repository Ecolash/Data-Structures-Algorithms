// COUNTING TOWERS

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

const ll N = 1e6 + 6;
ll DP[N][3];

/*
DP[i][1] = last blocks are separate | || |                                  _ _
DP[i][2] = last blocks are fused |   |

Transition:
             _  _    _  _    _  _    _  _     _ _
 _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
| || | =>   | || |, | || |, | || |, | || |,  | | |
             _ _    _ _    _ _
 _ _        |   |  |_|_|  |_ _|
|   |  =>   |   |, |   |, |   |

DP[i][1] = DP[i-1][1] * 4 + DP[i-1][2]
DP[i][2] = DP[i-1][1] + DP[i-1][2] * 2
*/

void solve() {


    DP[1][1] = DP[1][2] = 1;
    for (ll i = 2; i < N; i++)
    {
        DP[i][1] = ((DP[i - 1][1] * 4) % mod + DP[i - 1][2]) % mod;
        DP[i][2] = (DP[i - 1][1] + (DP[i - 1][2] * 2) % mod) % mod;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << (DP[n][1] + DP[n][2]) % mod << endl;
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}