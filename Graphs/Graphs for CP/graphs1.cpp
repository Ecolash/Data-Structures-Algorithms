#include <bits\stdc++.h>
using namespace std;

/*
Q >> Find number of possible edges that reduce the number of components in a graph (one edge only added)

In a graph with n vertices and m edges, each edge added can reduce the number of components by at most one.
This means that the minimum number of components is n - m.

To make each component of a graph a complete graph, the number of edges in each component must be equal to n(n-1)/2
Here n is the number of vertices in that component.

The total number of new edges that can reduce components in a graph:
n = pairwise sum of product of number of vertices in two components over all possible component pairs

Let C1,C2,C3.. be the components.
Let ai be number of nodes in Ci component

Then n = sum of all ai x aj for j > i
     n = ((sum of ai) ^ 2 - (sum of ai ^ 2)) / 2
     n = sum of aj * suffix_sum(aj)

*/

vector<vector<int>> graph;
vector<int> visited;

void dfs(int i, int flag)
{
    visited[i] = flag;
    for (auto v : graph[i])
    {
        if (!visited[v])
            dfs(v, flag);
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
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            components++;
            int flag = components;
            dfs(i, flag);
        }
    }

    int nodes[components + 1];
    memset(nodes, 0, sizeof(nodes));
    for (int i = 1; i <= n; i++)
    {
        nodes[visited[i]]++;
    }

    int ans = 0;
    int suffix_sum = 0;
    for (int i = 1; i <= components; i++)
    {
        ans += nodes[i] * suffix_sum;
        suffix_sum += nodes[i];
    }

    cout << ans << endl;
}

int main()
{
    int t, i = 0;
    cin >> t;
    while (t--)
    {
        cout << "TC : " << (++i) << endl;
        solve();
    }
}