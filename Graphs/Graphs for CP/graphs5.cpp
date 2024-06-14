/*
Q >> Syrjälä's network has n computers and m connections.
     Your task is to find out if Uolevi can send a message to Maija.
     If it is possible, what is the minimum number of computers on such a route.

    INPUT
    The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
    Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
    Every connection is between two different computers, and there is at most one connection between any two computers.

    OUTPUT
    If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
    If there are no routes, print "IMPOSSIBLE".

*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

vector<vector<int>> graph;
vector<int> visited;
vector<int> dist;
vector<int> parent;

int m, n;
pair<int, int> S, F;

void BFS(int x)
{
    queue<int> Q;
    dist[x] = 0;
    visited[x] = 1;

    Q.push(x);
    while (!Q.empty())
    {
        int pos = Q.front();
        Q.pop();

        for (auto v : graph[pos])
        {
            if (dist[v] > dist[pos] + 1)
            {
                visited[v] = 1;
                dist[v] = dist[pos] + 1;
                parent[v] = pos;
                Q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    visited.assign(n + 1, 0);
    dist.assign(n + 1, INT_MAX);
    parent.assign(n + 1, -1);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BFS(1);
    if (!visited[n])
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    cout << dist[n] + 1 << endl;
    stack<int> S;
    int curr = n;
    for (int i = dist[n]; i > 0; i--)
    {
        S.push(parent[curr]);
        curr = parent[curr];
    }

    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    cout << n << " ";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}