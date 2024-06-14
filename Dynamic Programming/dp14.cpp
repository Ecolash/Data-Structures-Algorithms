// EDIT DISTANCE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using vp = std::vector<pl>;
using vs = std::vector<string>;
using vvl = std::vector<vl>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;
using MAXHeap = std::priority_queue<ll>;
using MINHeap = std::priority_queue<ll, vector<ll>, greater<ll>>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define po pop_back
#define mp make_pair
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define F first
#define S second

ll minDistance(string &word1, string &word2) {
    ll m = word1.size();
    ll n = word2.size();

    ll DP[m + 1][n + 1];
    memset(DP, 100000, sizeof(DP));
    for(ll i = 0; i <= m; i++) DP[i][0] = i;
    for(ll i = 0; i <= n; i++) DP[0][i] = i;

    for(ll i = 0; i < m; i++)
        for(ll j = 0; j < n; j++)
        {
            if (word1[i] == word2[j]) DP[i + 1][j + 1] = DP[i][j];
            else
            {
                ll ins = DP[i + 1][j];
                ll del = DP[i][j + 1];
                ll rep = DP[i][j];
                DP[i + 1][j + 1] = 1 + min(ins, min(del, rep));
            }
        }
    return DP[m][n];
}

void solve() {
    string s, t;
    cin >> s >> t;
    cout << minDistance(s, t) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}