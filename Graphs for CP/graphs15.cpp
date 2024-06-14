// BELLMAN FORD ALGORITHM
// SSSP ON GRAPHS WITH -VE CYCLES

/*
5 6
1 2 6
1 3 7
2 4 5
2 3 8
3 4 -3
4 5 2
*/

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
#define mp make_pair

const int N = 1e5;

int n, m;
vp graph[N]; 
vl dist;

void bellman_ford(int s)
{
    dist[s] = 0;
    for (int i = 1; i <= n - 1; i++) // |V| - 1 times
      for (int u = 1; u <= n; u++)
        for (auto &x : graph[u])
        {
            int v = x.F;
            int w = x.S;
            if (dist[u] != MAX and dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }

    // If distance of some nodes change even after this, it means there is a -ve cycle
    for (int u = 1; u <= n; u++) 
    {
        ll flag = 0;
        for (auto &x : graph[u])
        {
            int v = x.F;
            int w = x.S;
            if (dist[u] != MAX && dist[v] > dist[u] + w)
            {
                cout << "Graph contains a -ve wt cycle" << endl;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dist.resize(n + 1, MAX);
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        pl x = make_pair(b, c);
        graph[a].push_back(x);
    }
    bellman_ford(1);
    for (int i = 1; i <= n; i++) 
    {
        if (dist[i] == MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
