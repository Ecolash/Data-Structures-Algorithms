#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll MAX_N = 20;

ll n, m;
ll dp[MAX_N][1 << MAX_N];
vector<ll> graph[MAX_N];

void solve()
{
    cin >> n >> m;

    for (ll i = 0; i < n; ++i)
        graph[i].clear();

    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
    }

    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1; // Starting at city 1 (0-indexed) with only city 1 visited

    for (ll mask = 1; mask < (1 << n); ++mask)
    {
        for (ll u = 0; u < n; ++u)
        {
            if (mask & (1 << u))
            {
                for (ll v : graph[u])
                {
                    if (!(mask & (1 << v)))
                    {
                        dp[mask | (1 << v)][v] += dp[mask][u];
                        dp[mask | (1 << v)][v] %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << "\n"; // Number of Hamiltonian paths ending at city n (0-indexed)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
