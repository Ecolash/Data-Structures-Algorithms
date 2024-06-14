// RANGE FREQUENCY PARITY QUERIES
// Count Fruits
// Link : https://www.hackerrank.com/contests/goc-cdc-series-23/challenges/count-fruits/problem

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

const int N = 100005;

int arr[N];
bitset<1005> segTree[4 * N];

void build(int i, int l, int r)
{
    if (l == r)
    {
        segTree[i].set(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    segTree[i] = segTree[2 * i] ^ segTree[2 * i + 1];
}

void update(int i, int l, int r, int pos, int val)
{
    if (pos < l || pos > r) return;
    if (l == r)
    {
        arr[i] = val;
        segTree[i].reset();
        segTree[i].set(val);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * i, l, mid, pos, val);
    update(2 * i + 1, mid + 1, r, pos, val);
    segTree[i] = segTree[2 * i] ^ segTree[2 * i + 1];
}

bitset<1005> query(int i, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql) return bitset<1005>(0);
    if (l >= ql and r <= qr) return segTree[i];
    int mid = (l + r) / 2;
    return query(2 * i, l, mid, ql, qr) ^ query(2 * i + 1, mid + 1, r, ql, qr);
}

void solve() {
    int n, q, z;
    cin >> n >> q;
    rep(i, 0, n) cin >> arr[i];
    build(1, 0, n - 1);

    int x, v, l, r;
    while(q--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> l >> v;
            update(1, 0, n - 1, l - 1, v);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1).count() << "\n";
        }
    }
    
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}