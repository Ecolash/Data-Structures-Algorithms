#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll mod = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vvl DP(n + 1, vl(k + 1, 0));
    vvl pre(n + 1, vl(k + 1, 0));

    for (int i = 0; i < n + 1; i++) DP[i][0] = 1;
    for (int i = 0; i < n + 1; i++) pre[i][0] = 1;
    
    for (int j = 1; j < k + 1; j++) DP[0][j] = 0;
    for (int j = 1; j < k + 1; j++) pre[0][j] = 1; 

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < k + 1; j++) {
            int maxi = a[i - 1];
            if (maxi >= j) DP[i][j] = pre[i - 1][j];
            else DP[i][j] = (pre[i - 1][j] - pre[i - 1][j - maxi - 1] + mod) % mod;
            pre[i][j] = (pre[i][j - 1] + DP[i][j]) % mod;
        }
    }
    cout << DP[n][k] << endl;
    return 0;
}
