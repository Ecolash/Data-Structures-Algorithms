// CSES - SHORTEST ROUTE - 1
// DIJKSTRA FOR DIRECTED GRAPH

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

const int N = 1e5 + 5;

int n, m;
vp graph[N]; 
bool visited[N];
vl dist;

class prioritize{
    public: bool operator()(pl &p1, pl &p2) const
    { return p1.S > p2.S; } // Sorts in ascending order
};

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++) dist[i] = 1e18, visited[i] = 0;
    dist[s] = 0;

    priority_queue<pl, vp, prioritize> Q;
    Q.push(mp(s, 0));
    while (!Q.empty())
    {
        pl p = Q.top();
        Q.pop();
        int u = p.F;
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto &x : graph[u])
        {
            int v = x.F;
            int w = x.S;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                Q.push(mp(v, dist[v]));
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
    dijkstra(1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
    return 0;
}