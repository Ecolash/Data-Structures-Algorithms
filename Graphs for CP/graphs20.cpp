// HIGH SCORE (CSES)

// BELLMAN FORD ALGORITHM
// SSSP ON GRAPHS WITH +VE CYCLES (FIND MAX POSSIBLE SCORE)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pl>
#define pb push_back

ll MAX = 1e18;

#define F first
#define S second
#define mp make_pair

const int N = 1e5 + 5;

int n, m;
vp graph[N]; 
vl dist;
vector<bool> rechable;

void bellman_ford(int s)
{
    dist[s] = 0;
    for (int i = 1; i <= n - 1; i++) // |V| - 1 times
    {
        for (int u = 1; u <= n; u++)
        {
            if (dist[u] == MAX) continue;
            for (auto &x : graph[u])
            {
                int v = x.F;
                int w = x.S;
                if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            }
        }
    }

    ll x = dist[n];

    vl cycle;
    for (int u = 1; u <= n; u++)
    {
        if (dist[u] == MAX) continue;
        for (auto &x : graph[u])
        {
            int v = x.F;
            int w = x.S;
            if (dist[u] + w < dist[v]) cycle.pb(v);
        }
    }

    rechable.assign(n + 1, false);
    queue<int> q;
    for (int node : cycle)
    {
        q.push(node);
        rechable[node] = true;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &x : graph[u])
        {
            int v = x.F;
            if (!rechable[v])
            {
                rechable[v] = true;
                q.push(v);
            }
        }
    }

    if (rechable[n] || x == MAX) cout << "-1" << endl;
    else cout << -x << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dist.assign(n + 1, MAX);

    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, -c});
    }
    bellman_ford(1);
    return 0;
}