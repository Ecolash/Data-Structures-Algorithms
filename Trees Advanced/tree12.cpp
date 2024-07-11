// EULER TOUR OF A TREE
// CSES - PATH QUERIES (SUM FROM ROOT TO NODE)

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;
int n, q, x, y;
vector<int> tree[N];
int st[N], en[N], val[N];
vector<int> euler;

int segTree[8 * N];

void build(int i, int l, int r)
{
    if (l == r)
    {
        segTree[i] = euler[l];
        return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build((i << 1) | 1, m + 1, r);
    segTree[i] = segTree[i << 1] + segTree[(i << 1) | 1];
}

void update(int i, int l, int r, int x, int p)
{
    if (p < l || p > r) return;
    if (l == r)
    {
        segTree[i] = x;
        euler[p] = x;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(i << 1, l, m, x, p);
    else update((i << 1) | 1, m + 1, r, x, p);
    segTree[i] = segTree[i << 1] + segTree[i << 1| 1];
}

int query(int i, int l, int r, int lq, int rq)
{
    int ans = 0;
    if (lq > r || rq < l) return 0;
    if (lq <= l and rq >= r) return segTree[i];
    int m = (l + r) >> 1;
    ans += query(i << 1, l, m, lq, rq);
    ans += query((i << 1) | 1, m + 1, r, lq, rq);
    return ans;
}

int t;
void dfs1(int u, int p)
{
    st[u] = t++;
    euler.push_back(val[u]);
    for(auto v : tree[u])
    {
        if (v == p) continue;
        dfs1(v, u);
    }
    en[u] = t++;
    euler.push_back(-val[u]);
}

signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        tree[y].push_back(x);
        tree[x].push_back(y);
    }
    t = 0;
    dfs1(1, 0);
    int l = 0, r = euler.size() - 1;
    build(1, l, r);
    while(q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, x;
            cin >> s >> x;
            update(1, l, r, x, st[s]);
            update(1, l, r, -x, en[s]);
            val[s] = x;
        }

        else
        {
            int s;
            cin >> s;
            // for(auto it : euler) cout << it << " "; cout << " | ";
            cout << (query(1, l, r, 0, st[s])) << endl;
        }
    }
    return 0;
}
