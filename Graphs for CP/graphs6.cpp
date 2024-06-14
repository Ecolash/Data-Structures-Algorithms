// MULTI-SOURCE BFS
/*
Q >> Given an M x N matrix where each element can either be # or .  (# for walls, . for void)
    Web have multiple source and multiple destination in the graph
    We need to find the shortest path between a any source cell to any destination cell.
    The path can only be created out of a cell if its value is '.'

   To extend the problem to handle multiple sources & destinations, we modify the BFS approach to start from all the source cells simultaneously.
   This can be achieved using a multi-source BFS. 
   The idea is to initialize the BFS queue with all source cells. T
   hen perform the BFS to find the shortest path to any of the destination cells.
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

vector<string> graph;
vector<vector<int>> visited;
vector<vector<int>> dist;

int m, n;
vector<pair<int, int>> sources;
vector<pair<int, int>> destinations;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int i, int j)
{
    if (i < 0 || j < 0 || i >= m || j >= n || graph[i][j] == '#') return false;
    return true;
}

void BFS()
{
    queue<pair<int, int>> Q;
    dist.assign(m, vector<int>(n, INT_MAX));
    visited.assign(m, vector<int>(n, 0));
    for (auto source : sources)
    {
        int x = source.F;
        int y = source.S;
        dist[x][y] = 0;
        visited[x][y] = 1;
        Q.push({x, y});
    }

    while (!Q.empty())
    {
        auto pos = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = pos.F + dx[i];
            int y = pos.S + dy[i];
            if (check(x, y) and dist[x][y] > dist[pos.F][pos.S] + 1)
            {
                visited[x][y] = 1;
                dist[x][y] = dist[pos.F][pos.S] + 1;
                Q.push({x, y});
            }
        }
    }
}

void solve()
{
    cin >> m >> n;
    graph.clear();
    graph.resize(m);
    for (int i = 0; i < m; i++) cin >> graph[i];
    
    int ns, nd;
    cin >> ns;
    sources.resize(ns);
    for (int i = 0; i < ns; i++) cin >> sources[i].F >> sources[i].S;
    
    cin >> nd;
    destinations.resize(nd);
    for (int i = 0; i < nd; i++) cin >> destinations[i].F >> destinations[i].S;
    

    BFS();
    int shortest_path = INT_MAX;
    for (auto destination : destinations)
    {
        int x = destination.F;
        int y = destination.S;
        if (dist[x][y] != INT_MAX) shortest_path = min(shortest_path, dist[x][y]);
    }

    if (shortest_path == INT_MAX)  cout << "No path Found!" << endl;
    else cout << "Shortest Path: " << shortest_path << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
