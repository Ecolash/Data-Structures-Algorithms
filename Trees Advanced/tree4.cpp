// MAX DISTANCE OF A NODE FROM EACH NODE
// CSES - TREE DISTANCE 1

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, x, y;
vector<int> tree[N];
int inDP[N], outDP[N];
int mini[N], par[N];

void dfs1(int u, int p)
{
    inDP[u] = 0;
    mini[u] = 0;
    for(auto v : tree[u])
    {
        if (v == p) continue;
        dfs1(v, u);
        if (inDP[u] <= inDP[v] + 1)
        {
            mini[u] = max(mini[u],inDP[u]);
            inDP[u] = inDP[v] + 1;
        }
        else if (mini[u] <= inDP[v] + 1) mini[u] = inDP[v] + 1;
    }
}

void dfs2(int u, int p)
{
    outDP[u] = 0;
    if(p != 0)
    {
        if (mini[p] != 0) outDP[u] = mini[p] + 1;
        if (inDP[p] > inDP[u] + 1 and mini[p] != 0) outDP[u] = inDP[p] + 1;
        outDP[u] = max(outDP[u], outDP[p] + 1);
    } 
    for(auto v : tree[u])
    {
        if(v == p) continue;
        dfs2(v, u);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        tree[y].push_back(x);
        tree[x].push_back(y);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << inDP[i] << " " << mini[i] << " ";
        cout << outDP[i] << " ";
        cout << max(outDP[i] , inDP[i]) << " ";
        cout << "\n";
    }
    return 0;
}
