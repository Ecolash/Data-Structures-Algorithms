// BINARY LIFTING APPLICATION 
// CSES - DISTANCE BETWEEN 2 NODES
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int H = 20; // Use log2(N) + 1, H = 20 is sufficient for N up to 2e5

int n, q;
vector<int> tree[N];
int par[N][H];
int depth[N];

void dfs(int u, int p, int d)
{
    par[u][0] = p;
    depth[u] = d;
    for (auto v : tree[u])
    {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

void preprocess()
{
    for (int j = 1; j < H; j++)
    for (int i = 1; i <= n; i++)
    {
        if (par[i][j - 1] != 0)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    int dist = 0;
    for (int i = H - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            u = par[u][i];
            dist += (1 << i);
        }
    }

    if (u == v) return dist;
    for (int i = H - 1; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
            dist += 2 * (1 << i);
        }
    }
    return dist + 2;
}

int main()
{
    int x, y;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    { 
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0, 0); 
    preprocess();
    while (q--)
    {
        int v, k;
        cin >> v >> k;
        cout << lca(v, k) << endl;
    }

    return 0;
}
