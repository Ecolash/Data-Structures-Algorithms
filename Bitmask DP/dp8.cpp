#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

ll cnt[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (ll i = 1; i < n; i++) {
        ll x = s[i - 1] - 'a';
        ll y = s[i] - 'a';
        cnt[x][y]++;
        cnt[y][x]++;
    }

    vl DP((1 << m), 1e17);
    DP[0] = 0;
    for (ll mask = 0; mask < (1 << m); mask++) 
    {
        for (ll i = 0; i < m; i++) 
        {
            if ((mask & (1 << i))) continue;
            ll a = 0, b = 0;
            for (ll j = 0; j < m; j++) {
                if (i == j) continue;
                if (mask & (1 << j)) a += cnt[i][j];
                else b += cnt[i][j];
            }
            ll pos = __builtin_popcount(mask) + 1;
            DP[mask ^ (1 << i)] = min(DP[mask ^ (1 << i)], DP[mask] + a * pos - b * pos);
        }
    }
    cout << DP[(1 << m) - 1] << endl;
    return 0;
}
