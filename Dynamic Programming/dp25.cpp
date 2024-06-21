// PROJECTS (CSES)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

struct Project { ll s, e, v;};
bool compareBye(Project a, Project b){ return a.e < b.e; }

void solve() {
    ll n;
    cin >> n;
    vector<Project> projects(n);
    for (ll i = 0; i < n; ++i) cin >> projects[i].s >> projects[i].e >> projects[i].v;

    sort(projects.begin(), projects.end(), compareBye);

    vl dp(n + 1, 0);
    vl ends(n);
    for (ll i = 0; i < n; ++i) ends[i] = projects[i].e;

    for (ll i = 1; i <= n; ++i)
    {
        ll take = projects[i - 1].v;
        ll l = upper_bound(ends.begin(), ends.end(), projects[i - 1].s - 1) - ends.begin();

        if (l > 0) take += dp[l];
        dp[i] = max(dp[i - 1], take);
    }
    cout << dp[n] << endl;
}


signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
