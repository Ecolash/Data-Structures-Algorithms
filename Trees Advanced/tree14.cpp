// TROUBLESOME TREES
// Link : https://www.hackerrank.com/contests/goc-cdc-series-28/challenges/troublesome-trees

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

const int N = 2e5 + 5;
vp tree[N];
vl dist;
ll wt[N];
ll ans;
ll sum;

void dfs(int u, int p) {
    for (auto &x : tree[u])
    {
        if (x.F == p) continue;
        sum += x.S;
        dist.push_back(sum);
        dfs(x.F, u);
        dist.pop_back();
        sum -= x.S;
    }

    int i = lower_bound(dist.begin(), dist.end(), dist.back() - wt[u]) - dist.begin();
    ans += dist.size() - i;
}

void solve() {
    int n, m;
    cin >> n;
    for(int i = 0; i <= n; i++) tree[i].clear();
    dist.clear();
    dist.push_back(0);

    m = n - 1;
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++) cin >> wt[i];
    ans = sum = 0;
    dfs(1, 0);
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}