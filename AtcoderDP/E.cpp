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
#define vout(v) rep(i, 0, v.size()) cout << v[i] << " "; cout << endl;
#define all(o) (o).begin(), (o).end()
#define asort(o) sort((o).begin(), (o).end())
#define dsort(o) sort((o).rbegin(), (o).rend())
#define maxin(a) *max_element(a.begin(), a.end())
#define minin(a) *min_element(a.begin(), a.end())
#define ub_index(v, x) (ub(all(v), x) - v.begin())
#define lb_index(v, x) (lb(all(v), x) - v.begin())

ll DP[105][100005];

void solve()
{
    ll n, W;
    cin >> n >> W;
    vl val(n + 1);
    vl wt(n + 1);
    ll maxP = n * 1000;

    rep(i, 1, n + 1) cin >> wt[i] >> val[i];
    mset(DP, 0x5f);

    DP[0][0] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= maxP; j++)
    {
        DP[i][j] = DP[i - 1][j];
        if (val[i] <= j) DP[i][j] = min(DP[i][j], DP[i - 1][j - val[i]] + wt[i]);
    }
    
    ll ans = 0;
    rep (i, 1, maxP + 1) if (DP[n][i] <= W) ans = i;
    cout << ans << endl;
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