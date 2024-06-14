// 0-1 BFS APPLICATION
// TRADEMILL ROTATION PROBLEM
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pl>
ll MAX = 1e9;

#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))

const int N = 1e5;
/*
-----------------------------------------------------------
For directed graph we use array of vector of pairs
The first element in pair contains the connected node
The second element contains the weight of the edge (0 or 1)
-----------------------------------------------------------
*/
vector<string> graph;
vector<vector<int>> dist;

int m, n;
pair<int, int> S, F;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'R', 'D', 'L', 'U'}; 

bool check(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}

void BFS01(int x, int y)
{
    deque<pl> Q;
    dist.assign(n, vector<int>(m, INT_MAX));

    dist[x][y] = 0;
    Q.push_back({x, y});
    while (!Q.empty())
    {
        auto pos = Q.front();
        Q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = pos.F + dx[i];
            int ny = pos.S + dy[i];
            if (check(nx, ny))
            {
                ll d = dist[pos.F][pos.S] + (graph[pos.F][pos.S] != dir[i]);
                if (dist[nx][ny] > d)
                {
                    dist[nx][ny] = d;
                    if (graph[pos.F][pos.S] == dir[i]) Q.push_front({nx, ny});
                    else Q.push_back({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    graph.clear();
    graph.resize(n);  
    for (int i = 0; i < n; i++) cin >> graph[i];
    BFS01(0, 0);
    cout << "MIN COST: " << dist[n - 1][m - 1] << endl;
}