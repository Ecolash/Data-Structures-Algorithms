// CSES - CYCLE FINDING

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<long long>;
using vvl = vector<vl>;

int main()
{
    int t = 1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, pl>> edges;
        for(int i = 0; i < m; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, {a, b}});
        }
        vl dis(n + 1, 1e18);
        vl par(n + 1, 0);
        dis[1] = 0;
        ll f = 0;

        for(int i = 0; i < n; i++)
        {
            f = 0;
            for (auto e : edges)
            {
                ll u = e.second.first;
                ll v = e.second.second;
                ll w = e.first;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    par[v] = u;
                    f = v;
                }
            }
        }
        if (!f) cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++)f = par[f];
            vl cyc;
            ll x = f;
            while (1)
            {
                cyc.push_back(x);
                if (x == f and cyc.size() > 1) break;
                x = par[x];
            }
            reverse(cyc.begin(), cyc.end());
            for (auto u : cyc) cout << u << " ";
            cout << '\n';
        }
    }
    return 0;
}