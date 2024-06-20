// CSES Problem Set
// Money Sums

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

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    sl s1, s2;
    s1.insert(0);
    rep(i, 0, n)
    {
        cin >> a[i];
        for (auto x : s1)
        {
            s2.insert(x);
            s2.insert(x + a[i]);
        }
        s1 = s2;
        s2.clear();
    }
    s1.erase(0);
    cout << s1.size() << endl;
    for (auto x : s1) cout << x << " ";
    cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--) solve();
    return 0;
}