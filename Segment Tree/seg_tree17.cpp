// SEGMENT TREE APPLICATION
// SHIFTING INDEX
// Link : https://www.hackerrank.com/contests/goc-cdc-series-11/challenges/alumni-meet/problem

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
const ll N = 2e5 + 5; 
vl seg(N << 2, 0);
vl ans(N, 0);     

void build(ll node, ll start, ll end)
{
    if (start == end) seg[node] = 1;
    else
    {
        ll mid = (start + end) / 2;
        build(node << 1, start, mid);
        build(node << 1 | 1, mid + 1, end);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

void update(ll node, ll start, ll end, ll val, ll pos)
{
    if (start == end)
    {
        seg[node] -= pos;
        ans[start] = val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if (seg[node << 1] >= pos) update(node << 1, start, mid, val, pos);
        else update(node << 1 | 1, mid + 1, end, val, pos - seg[node << 1]);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

void print(ll n)
{
    for (ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    build(1, 0, n - 1);

    vl ar1(n), ar2(n);
    for (ll i = 0; i < n; ++i) cin >> ar1[i];
    for (ll i = 0; i < n; ++i) cin >> ar2[i];

    for (ll i = n - 1; i >= 0; --i) update(1, 0, n - 1, ar2[i], ar1[i] + 1);
    print(n);
    return 0;
}
