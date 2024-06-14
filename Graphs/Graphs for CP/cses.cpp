#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
bool ans;

void dfs(int i, int section)
{
    visited[i] = section;
    for (auto v : graph[i])
    {
        if (!visited[v])
            dfs(v, 1 ^ 2 ^ section);

        else if (visited[v] == visited[i])
        {
            ans = false;
            return;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    visited.assign(n + 1, 0);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int components = 0;
    ans = true;
    for (int i = 1; i <= n && ans; i++)
    {
        if (!visited[i])
        {
            int section = 1;
            dfs(i, section);
        }
    }

    if (!ans)
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << " ";
    }
}

int main()
{

    solve();
    return 0;
}