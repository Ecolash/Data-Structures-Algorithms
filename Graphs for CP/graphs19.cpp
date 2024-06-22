// SHORTEST PATH - 2 (CSES)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<long long>
#define vvl vector<vl>
ll MAX = 1e18; 

const int N = 505; 
ll dist[N][N];
int n, m, q;

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
    cin >> n >> m >> q;
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
    while(q--)
    {
        cin >> a >> b;
        if (dist[a][b] == MAX) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
    cout << endl;
    return 0;
}
