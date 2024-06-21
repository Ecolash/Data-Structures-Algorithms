// TWO SETS - 2 (CSES)

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

ll DP[505][100000];

/*
    This is a 0-1 knapsack in disguise. 
    If we are to have two subsets of equal sum, they must sum to half the total sum each. 
    This means if the total sum n(n+1) / 2 is odd, the answer is 0 (no possibilities). 
    Otherwise we run 0-1 knapsack to get the number of ways to reach n(n+1) / 4
    We use subsets of the numbers 1..n-1. Why n-1? Because by only considering numbers up to n-1
    We always put n in the second set, and therefore only count each pair of sets once (otherwise we count every pair of sets twice).

    DP[i][x] = number of ways to make sum x using subsets of the numbers 1..i .
*/

void solve() {
    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;
    if (s % 2 == 1) 
    {
        cout << 0 << endl;
        return;
    }

    s = s / 2;
    DP[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            DP[i][j] = DP[i - 1][j];
            ll x = j - i;
            if (x >= 0) (DP[i][j] += DP[i - 1][x]) %= mod;
        }
    }
    cout << DP[n - 1][s] << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}