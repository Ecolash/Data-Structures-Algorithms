// FIND KTH BOSS OF EMPLOYEE 
// BINARY LIFTING APPLICATION
// CSES - COMPANY QUERIES 1

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int H = 32;

int n, m;
vector<int> tree[N];
int par[N][H];

void dfs(int u, int p)
{
    par[u][0] = p;
    for(auto v : tree[u])
    {
        if(v == p) continue;
        dfs(v, u);
    }
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
    dfs(1, 0);
    for (int j = 1; j < H; j++)
    for (int i = 1; i <= n; i++)
    {
        par[i][j] = par[par[i][j - 1]][j - 1];
    }

    while(q--)
    {
        int v, k;
        cin >> v >> k;
        int ans = v;
        for(int i = H - 1; i >= 0; i--)
        {
            if (k & (1 << i)) ans = par[ans][i];
        }
        if (ans == 0) ans = -1;
        cout << ans << endl;
    }
}