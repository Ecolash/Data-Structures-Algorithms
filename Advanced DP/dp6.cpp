// TREE DP
// MAX PROFIT SELECTING NON ADJACENT NEIGHBOURS

/*
7
1 2
2 3
2 4
5 4
6 4
1 7
----------------------------
Node 1 : 2 + 0 = 2
Node 2 : 3 + 0 = 3
Node 3 : 4 + 0 = 4
Node 4 : 4 + 0 = 4
Node 5 : 3 + 0 = 3
Node 6 : 3 + 0 = 3
Node 7 : 3 + 0 = 3
Min cost: 2
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pl>
ll MAX = 1e9;

#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))
#define mp make_pair
#define pb push_back

const int N = 1e3 + 5;

int n, m;
vl tree[N];
ll size[N];
ll profit[N];
ll DP[N][2][N];

void dfs(int u, int p)
{
   size[u] = 1;
   for (int i = 0; i < N; i++) DP[u][0][i] = DP[u][1][i] = 0;

   DP[u][0][0] = 0;
   DP[u][1][1] = profit[u];
   for (auto v: tree[u])
   {
      if (v == p) continue;
      dfs(v, u);

      for (int i = size[u]; i >= 0; i--)
      for (int j = size[v]; j >= 0; j--)
      {
         DP[u][0][i + j] = max(DP[u][0][i + j], DP[u][0][i] + max(DP[v][0][j], DP[v][1][j]));
         DP[u][1][i + j] = max(DP[u][1][i + j], DP[u][1][i] + DP[v][0][j]);
      }
   }
}

void solve()
{
    int x, y;
    cin >> n;
    for(int i = 1; i <= n; i++) tree[i].clear();
    m = n - 1;
    while(m--)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    

    int ans = MAX;

    cout << "Min cost: "<< ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}