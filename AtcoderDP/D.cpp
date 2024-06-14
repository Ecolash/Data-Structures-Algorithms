#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vp vector<pl>
#define vs vector<string>
#define vvl vector<vl>
#define sl set<ll>
#define ml map<ll, ll>
#define MAXHeap priority_queue<ll>
#define MINHeap priority_queue<ll, vector<ll>, greater<ll>>

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define po pop_back
#define mp make_pair
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define F first
#define S second

#define mset(m, v) memset(m, v, sizeof(m))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define yes cout << "YES\n"
#define no cout << "NO\n"

#define vin(v) rep(i, 0, v.size()) cin >> v[i]
#define vout(v)                              \
    rep(i, 0, v.size()) cout << v[i] << " "; \
    cout << endl;
#define all(o) (o).begin(), (o).end()
#define asort(o) sort((o).begin(), (o).end())
#define dsort(o) sort((o).rbegin(), (o).rend())
#define maxin(a) *max_element(a.begin(), a.end())
#define minin(a) *min_element(a.begin(), a.end())
#define ub_index(v, x) (ub(all(v), x) - v.begin())
#define lb_index(v, x) (lb(all(v), x) - v.begin())

void solve()
{
    ll n, W;
    cin >> n >> W;
    vvl v(n, vl(2));
    rep(i, 0, n) cin >> v[i][0] >> v[i][1];
    ll DP[W + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) DP[w][i] = 0;
            else if (v[i - 1][0] <= w) DP[w][i] = max(v[i - 1][1] + DP[w - v[i - 1][0]][i - 1], DP[w][i - 1]);
            else DP[w][i] = DP[w][i - 1];
        }
    cout << DP[W][n] << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}