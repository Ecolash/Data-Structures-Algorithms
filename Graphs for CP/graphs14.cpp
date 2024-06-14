// DIJKSTRA's APPLICATION
// GRAPH COST

/*
lINK : https://www.codechef.com/problems/GRAPHCOST
------------------------------------------------------------------------------------------------
You have an array A of size N, a complete weighted graph with N nodes
All possible n . (n - 1) / 2 undirected weighted edges b/w each pair of nodes.
Weight b/w i and j wt(i, j) = |j - i| max(A[i], A[j])
Find the distance between nodes i and j
------------------------------------------------------------------------------------------------
SOLUTION:
suppose there are three indices i < j < k such that A[j] <= max(Ai, Ak).
Then, we don’t need to consider the edge i to k at all

Suppose there exists an index i > 1 such that A[i] < A[1] | Cost : A[1] x (iL - 1)
Suppose there exists an index i > 1 such that A[i] > A[1] | Cost : A[i] x (iL - 1)
NOTE: Choosing the leftmost is always optimal

The first step has us repeatedly move to the next smaller element; which is just a prefix minimum.
The second step has us repeatedly move to the smallest element of a suffix; so a suffix minimum.


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
#define pb push_back

const int N = 1e5;

int n, m;
vp graph[N]; 
bool visited[N];
ll dist[N];

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

void solve()
{
    cin >> n;
    vl a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) graph[i].clear();

    ll last = 1, w;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < a[last])
        {
            w = abs(i - last) * a[last];
            graph[i].pb(mp(last, w));
            graph[last].pb(mp(i, w));
            // cout << i << " " << last << " " << w << endl;
            last = i;
        }
    }

    last = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] <= a[last])
        {
            w = abs(last - i) * a[last];
            graph[i].pb(mp(last, w));
            graph[last].pb(mp(i, w));
            // cout << i << " " << last << " " << w << endl;
            last = i;
        }
    }
    dijkstra(1);
    cout << dist[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}