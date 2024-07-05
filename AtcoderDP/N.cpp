#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

int main() {
    ll n;
    cin >> n; 
    vl v(n), pre(n + 1, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + v[i - 1];

    ll DP[n][n];
    
    for(int i = 0; i < n; i++) DP[i][i] = 0;
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            DP[i][j] = 1e18;
            for (int k = i; k < j; k++)
            {
                ll c = pre[k + 1] - pre[i];
                c += pre[j + 1] - pre[k + 1];
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + c);
            }
        }
    }
    
    cout << DP[0][n - 1] << "\n";
    return 0;
}