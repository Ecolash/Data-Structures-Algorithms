// DIJKSTRA's APPLICATION
// THREAD BURNING PROBLEM

/*
============================
5 7
1 2 5
1 3 4
1 4 5
2 3 1
3 4 2
2 5 5
4 5 2
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
const ll N = 1e5;

#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))
#define mp make_pair
#define pb push_back

int n, m;
vp graph[N]; 
bool visited[N];
vl time_;

class prioritize{
    public: bool operator()(pl &p1, pl &p2) const
    { return p1.S > p2.S; } // Sorts in ascending order
};

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++) time_[i] = 1e18, visited[i] = 0;
    time_[s] = 0;

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
            if (time_[v] > time_[u] + w)
            {
                time_[v] = time_[u] + w;
                Q.push(mp(v, time_[v]));
            }
        }
    }
} 

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    time_.resize(n + 1, MAX);
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        pl x = make_pair(b, c);
        pl y = make_pair(a, c);
        graph[a].push_back(x);
        graph[b].push_back(y);
    }
    dijkstra(1);
    double time = 0, t;
    for (int i = 1; i <= n; i++)
    {
        for (auto &x: graph[i])
        {
            ll v = x.F;
            ll len = x.S;
            ll A = time_[i];
            ll B = time_[v];
            if (abs(A - B) >= len) t = (double)(min(A, B) + len);
            else t = (double)((A + B + len) / 2.0);
            time = max(time, t);
            // cout << i << " " << v << " " << t << endl;
        }
    }
    cout << time << endl;
    cout << endl;
    return 0;
}