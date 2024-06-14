// DIJKSTRA's APPLICATION
// VEHICLE FUEL PROBLEM

/*
============================
5 4 10
1 2 1
2 3 2
3 4 3
4 5 5
2 10 10 10 10
===========================
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define ppl pair<pl, ll>
#define vl vector<long long>
#define vvl vector<vl>
#define vp vector<pl>
ll MAX = 1e9;

#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))
#define mp make_pair
#define pb push_back

const int cities = 1000 + 1;
const int max_cap = 100 + 1;

int n, m, cap;
vector<pair<pl, ll>> graph[cities][max_cap];
bool visited[cities][max_cap];
ll fuel_cost[cities][max_cap];

class prioritize{
    public: bool operator()(ppl &p1, ppl &p2) const
    { return p1.S > p2.S; } // Sorts in ascending order
};

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= cap; j++) 
    fuel_cost[i][j] = 1e18, visited[i][j] = 0;

    fuel_cost[s][0] = 0;
    priority_queue<ppl, vector<ppl>, prioritize> Q;
    Q.push(mp(mp(s, 0), 0));
    while (!Q.empty())
    {
        ppl p = Q.top();
        Q.pop();
        pl u = p.F;
        if (visited[u.F][u.S]) continue;
        visited[u.F][u.S] = 1;
        for (auto &x : graph[u.F][u.S])
        {
            pl v = x.F;
            ll w = x.S;
            if (fuel_cost[v.F][v.S] > fuel_cost[u.F][u.S] + w)
            {
                fuel_cost[v.F][v.S] = fuel_cost[u.F][u.S] + w;
                Q.push(mp(v, fuel_cost[v.F][v.S]));
            }
        }
    }
} 

void solve()
{
    cin >> n >> m >> cap;
    vl cost(n + 1);
    ll a, b, c;
    vp temp[n + 1];
    while (m--)
    {
        cin >> a >> b >> c;
        pl x = make_pair(b, c);
        pl y = make_pair(a, c);
        temp[a].push_back(x);
        temp[b].push_back(y);
    }    

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        ll x = cost[i];
        for (int j = 0; j < cap; j++) graph[i][j].push_back(mp(mp(i, j + 1), x));
    }

    for (int i = 1; i <= n; i++)
    for (auto &x : temp[i])
    {
        ll u = i, v = x.F, w = x.S;
        for (int j = 0; j <= cap; j++) if (j >= w) graph[u][j].pb(mp(mp(v, j - w), 0));
    }

    dijkstra(1);
    ll ans = 1e18;
    for (int j = 0; j <= cap; j++) ans = min(ans, fuel_cost[n][j]);
    if (ans == 1e18) cout << "Impossible" << endl;
    else cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}