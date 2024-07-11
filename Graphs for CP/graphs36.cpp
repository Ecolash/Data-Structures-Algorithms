// EULERIAN TOUR OF A GRAPH
// CSES - MAIL DELIVERY

#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> head(n + 1, 0), nxt(2 * (m + 1), 0), to(2 * (m + 1), 0), cur(n + 1, 0), deg(n + 1, 0);
    int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v;
        nxt[++cnt] = head[v], head[v] = cnt, to[cnt] = u;
    }

    for (int i = 1; i <= n; i++)
    {
        cur[i] = head[i];
        if (deg[i] & 1)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> path;
    vector<bool> mark(cnt + 1, false);
    function<void(int)> dfs = [&](int node)
    {
        for (int &i = cur[node]; i; i = nxt[i])
        {
            if (!mark[i])
            {
                mark[i] = 1;
                mark[i ^ 1] = 1;
                dfs(to[i]);
            }
        }
        path.push_back(node);
    };

    dfs(1);
    if (path.size() == m + 1) for (int x : path) cout << x << " ";
    else cout<<"IMPOSSIBLE";
    return 0;
}