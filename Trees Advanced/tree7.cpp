// BINARY LIFTING APPLICATION (LCA)
// CSES - COMPANY QUERIES II

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int H = 32;

int n, m;
vector<int> tree[N];
int par[N][H];
int depth[N];

void dfs(int u, int p, int d)
{
    par[u][0] = p;
    depth[u] = d;
    for(auto v : tree[u])
    {
        if(v == p) continue;
        dfs(v, u, d + 1);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = H - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) u = par[u][i];
    if (u == v) return u;
    for (int i = H - 1; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main()
{
    int q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
    {
        cin >> m;
        tree[m].push_back(i);
        tree[i].push_back(m);
    }
    dfs(1, 0, 0);
    for (int j = 1; j < H; j++)
    for (int i = 1; i <= n; i++)
    {
        par[i][j] = par[par[i][j - 1]][j - 1];
    }

    while(q--)
    {
        int v, k;
        cin >> v >> k;
        cout << lca(v, k) << endl;
    }
}