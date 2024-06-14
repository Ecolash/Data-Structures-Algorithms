/* Q >> In a Class of N people, you know which pairs are friends.
        Is there a way to divide the class in 2 Sections such that no 2 friend is in the same section
        Find if its possible or not to split into 2 sections

    A >> We start a DFS with colour 1 say
         As we move in DFS we colour the next with colour 2
         Basically 2 connected nodes are coloured with opposite colours (denoting their section)
         If we are unable to do so, we return false
*/

#include <bits\stdc++.h>
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

    string out = (ans) ? "YES" : "NO";
    cout << out << endl;
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