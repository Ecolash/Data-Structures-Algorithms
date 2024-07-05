#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

ll n;
ll mod = 1e9 + 7;
ll MAX = 1e9;
const int N = 21;
ll dp[N][1 << N];
ll v[N][N];

int ways(int node, int mask) 
{
    if (mask == (1 << n) - 1) return 1;
    if (dp[node][mask] != -1) return dp[node][mask];
    
    ll ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j)) continue;
        if (v[node][j] == 0) continue;
        ans = (ans + ways(node + 1, mask | (1 << j))) % mod;
    }
    dp[node][mask] = ans;
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> v[i][j];
    memset(dp, -1, sizeof(dp));
    cout << ways(0, 0) << endl; 
    return 0;
}