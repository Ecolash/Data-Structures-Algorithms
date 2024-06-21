// CSES - Monsters

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll INF = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

vector<string> graph;
bool vis1[1005][1005];
bool vis2[1005][1005];
ll dist1[1005][1005];
ll dist2[1005][1005];
pl parent[1005][1005];
queue<pl> Q1, Q2;
pl source;

int m, n;
pair<int, int> S, F;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int i, int j)
{
    if (i < 0 || j < 0 || i >= m || j >= n || graph[i][j] == '#') return false;
    return true;
}

void BFS1()
{
    while (!Q1.empty()) {
    auto pos = Q1.front();
    Q1.pop();
    for (int i = 0; i < 4; i++) {
        ll x = pos.F + dx[i];
        ll y = pos.S + dy[i];
        if (check(x, y) and dist1[x][y] > dist1[pos.F][pos.S] + 1)
        {
            vis1[x][y] = 1;
            dist1[x][y] = dist1[pos.F][pos.S] + 1;
            Q1.push({x, y});
        }
    }
    }
}

void BFS2()
{
    while (!Q2.empty()) {
    auto pos = Q2.front();
    Q2.pop();
    for (int i = 0; i < 4; i++) {
        ll x = pos.F + dx[i];
        ll y = pos.S + dy[i];
        if (check(x, y) and dist2[x][y] > dist2[pos.F][pos.S] + 1)
        {
            vis2[x][y] = 1;
            parent[x][y] = mp(pos.F, pos.S);
            dist2[x][y] = dist2[pos.F][pos.S] + 1;
            Q2.push({x, y});
        }
    }
    }
}

void solve()
{
    cin >> m >> n;
    graph.resize(m);
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        graph[i] = s;
        for (int j = 0; j < n; j++)
        {
            dist1[i][j] = dist2[i][j] = INF;
            if (s[j] == '#') dist1[i][j] = dist2[i][j] = 0;
            if (s[j] == 'M')
            {
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
            if (s[j] == 'A')
            {
                Q2.push({i, j});
                dist2[i][j] = 0;
                source = mp(i, j);
                parent[i][j] = mp(-1, -1);
            }
        }
    }

    BFS1();
    BFS2();
    // for(int i = 0; i < m; i++)
    // { for(int j = 0; j < n; j++)
    //     { cout << dist1[i][j] << " "; } cout << "\n";
    // }
    // cout << "------------------------------\n";
    // for(int i = 0; i < m; i++)
    // { for(int j = 0; j < n; j++)
    //     { cout << dist2[i][j] << " "; } cout << "\n";
    // }

    bool possible = false;
    pl mini = {-1, -1};
    ll maxi = INF;
    rep(i, 0, m)
    {
        if((graph[i][0] != '#') and (dist1[i][0] > dist2[i][0]) and (dist2[i][0] < maxi)) maxi = dist2[i][0], mini = mp(i, 0);
        if((graph[i][n - 1] != '#') and (dist1[i][n - 1] > dist2[i][n - 1]) and (dist2[i][n - 1] < maxi)) maxi = dist2[i][n - 1], mini = mp(i, n - 1);
    }
    rep(j, 0, n)
    {
        if((graph[0][j] != '#') and (dist1[0][j] > dist2[0][j]) and (dist2[0][j] < maxi)) maxi = dist2[0][j], mini = mp(0, j);
        if((graph[m - 1][j] != '#') and (dist1[m - 1][j] > dist2[m - 1][j]) and (dist2[m - 1][j] < maxi)) maxi = dist2[m - 1][j], mini = mp(m - 1, j);
    }
    // cout << maxi << endl;
    // cout << mini.F << " " << mini.S << endl;

    if (maxi != INF) possible = true;

    if (possible)
    {
        cout << "YES" << endl;
        string ans;
        pl pos = mini;
        while (pos != source)
        {
            pl par = parent[pos.F][pos.S];
            if (par.F == pos.F + 1) ans.pb('U');
            if (par.F == pos.F - 1) ans.pb('D');
            if (par.S == pos.S + 1) ans.pb('L');
            if (par.S == pos.S - 1) ans.pb('R');
            pos = par;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}