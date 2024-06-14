/*
Q >> Given an M x N matrix where each element can either be # or .  (# for walls, . for void)
    We need to find the shortest path between a given source cell to a destination cell.
    The path can only be created out of a cell if its value is '.'

    We perform BFS for this!
    NOTE : BFS gives us shortest path to each node
     TC: O(V + E)
     SC: O(V)

    In a M X N maze, |V| = M X N, |E| = 4 x M X N
    TC: O(M * N)
    SC: O(M * N)

     We start from the source cell and call the BFS procedure.
     We maintain a queue to store the coordinates of the matrix and initialize it with the source cell.
     We LOOP till queue is not empty
     Dequeue front cell from the queue
     Return if the destination coordinates have been reached.
     For each of its four adjacent cells, if the value is 1 and not visited we enqueue it.

*/

#include <bits\stdc++.h>
using namespace std;

#define F first
#define S second

vector<string> graph;
vector<vector<int>> visited;
vector<vector<int>> dist;
vector<vector<pair<int, int>>> parent;

int m, n;
pair<int, int> S, F;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int i, int j)
{
    if (i < 0 || j < 0 || i >= m || j >= n || graph[i][j] == '#')
        return false;

    return true;
}

void BFS(int x, int y)
{
    queue<pair<int, int>> Q;
    dist.assign(m, vector<int>(n, INT_MAX));
    parent.assign(m, vector<pair<int, int>>(n, {0, 0}));
    visited.assign(m, vector<int>(n, 0));

    dist[x][y] = 0;
    visited[x][y] = 1;

    Q.push({x, y});
    while (!Q.empty())
    {
        auto pos = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            x = pos.F + dx[i];
            y = pos.S + dy[i];
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
    for (int i = 0; i < m; i++)
    {
        cin >> graph[i];
    }

    cin >> S.F >> S.S;
    cin >> F.F >> F.S;
    BFS(S.first, S.second);

    if (dist[F.F][F.S] == INT_MAX)
    {
        cout << "No path Found!" << endl;
        return;
    }

    cout << "Shortest Path: " << dist[F.F][F.S] << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}