// FLOYD - WARSALL ALGORITHM
// IMPLEMENTATION (Standard)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<long long>
#define vvl vector<vl>
ll MAX = 1e18; 

const int N = 500; // Maximum number of nodes
ll dist[N][N]; // Distance matrix

/*
-----------------------------------------------------------
The Floyd-Warshall algorithm calculates the shortest path
between all pairs of vertices in a weighted graph.
We use a 2D array `dist` where dist[i][j] represents the 
shortest distance from node i to node j.

DP(i, j, k) => Shortest path from i to j using (1, 2, .. k)
Base Case : All edges 

DP(i, j, k) ===> DP(i, j, k + 1)
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
-----------------------------------------------------------
*/

int n, m;

void floydWarshall() {
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][k] < MAX and dist[k][j] < MAX) 
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        if (i == j) dist[i][j] = 0;
        else dist[i][j] = MAX;
    }
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (ll)c);
        dist[b][a] = min(dist[b][a], (ll)c); 
    }

    floydWarshall();
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        if (dist[i][j] == MAX) cout << "INF ";
        else cout << dist[i][j] << " ";
    }
    cout << endl;
    return 0;
}
