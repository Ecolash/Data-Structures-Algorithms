// 0-1 BFS IMPLEMENTATION

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

const int N = 1e5;
/*
-----------------------------------------------------------
For directed graph we use array of vector of pairs
The first element in pair contains the connected node
The second element contains the weight of the edge (0 or 1)
-----------------------------------------------------------
*/
vp graph[N]; 
bool visited[N];
vl dist;
void bfs01(int s)
{
    deque<int> q;
    visited[s] = 1;
    dist[s] = 0;
    q.push_back(s);

    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();
        for (auto x : graph[node])
        {
            ll next = x.first;
            ll wt = x.second;
            if (dist[next] > dist[node] + wt)
            {
                dist[next] = dist[node] + wt;
                if (wt == 0) q.push_front(next);
                else q.push_back(next);
            }
        }
    }
} 

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    dist.resize(n + 1, MAX);
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        pl x = make_pair(b, c);
        pl y = make_pair(a, c);
        graph[a].push_back(x);
        graph[b].push_back(y);
    }
    bfs01(1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
    return 0;
}