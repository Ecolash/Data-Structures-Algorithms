// FLIGHT DISCOUNTS

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using vp = std::vector<pl>;
using vvl = std::vector<vl>;

ll mod = 1e9 + 7;
ll MAX = 1e18;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

#define F first
#define S second

const int N = 1e5 + 5;

int n, m;
vp graph1[N], graph2[N];
ll dist[N], rdist[N];
vector<pair<pl,ll>> edges;

void dijkstra(int x, ll dist[], vp graph[])
{
    fill(dist, dist + n + 1, MAX); // Efficient initialization
    dist[x] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, x});
    while (!pq.empty())
    {
        pl p = pq.top();
        pq.pop();
        ll d = p.F;
        ll u = p.S;
        if (d > dist[u]) continue;
        for (auto i : graph[u])
        {
            ll v = i.F;
            ll wt = i.S;
            if (d + wt < dist[v])
            {
                dist[v] = d + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    rep(i, 1, n + 1) {
        graph1[i].clear();
        graph2[i].clear();
    }
    edges.clear();
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        edges.pb({mp(a, b), c});
        graph1[a].push_back({b, c});
        graph2[b].push_back({a, c});
    }

    dijkstra(1, dist, graph1);
    dijkstra(n, rdist, graph2);

    ll f = MAX;
    for(auto edge: edges)
    {
        ll a = edge.F.first;
        ll b = edge.F.second;
        ll w = edge.S;
        if(dist[a] != MAX and rdist[b] != MAX) { // Only consider valid distances
            ll ans = dist[a] + rdist[b] + w / 2;
            f = min(ans, f);
        }
    }
    cout << f << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
