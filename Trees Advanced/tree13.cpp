#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;
int n, q, x, y;
vector<int> tree[N];
int val[N];
int st[N], en[N], parent[N], depth[N], sz[N], heavy[N], head[N], pos[N], cur_pos;

int segTree[8 * N];

void build(int i, int l, int r)
{
    if (l == r)
    {
        segTree[i] = val[pos[l]];
        return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build((i << 1) | 1, m + 1, r);
    segTree[i] = max(segTree[i << 1], segTree[(i << 1) | 1]);
}

void update(int i, int l, int r, int p, int x)
{
    if (p < l || p > r) return;
    if (l == r)
    {
        segTree[i] = x;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(i << 1, l, m, p, x);
    else update((i << 1) | 1, m + 1, r, p, x);
    segTree[i] = max(segTree[i << 1], segTree[(i << 1) | 1]);
}

int query(int i, int l, int r, int lq, int rq)
{
    if (lq > r || rq < l) return 0;
    if (lq <= l && rq >= r) return segTree[i];
    int m = (l + r) >> 1;
    return max(query(i << 1, l, m, lq, rq), query((i << 1) | 1, m + 1, r, lq, rq));
}

void dfs(int u, int p)
{
    parent[u] = p;
    depth[u] = (p == -1 ? 0 : depth[p] + 1);
    sz[u] = 1;
    int max_sz = 0;
    for (int v : tree[u])
    {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > max_sz)
        {
            max_sz = sz[v];
            heavy[u] = v;
        }
    }
}

void decompose(int u, int h)
{
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1) decompose(heavy[u], h);
    for (int v : tree[u])
    {
        if (v != parent[u] && v != heavy[u]) decompose(v, v);
    }
}

int query_path(int a, int b)
{
    int res = 0;
    while (head[a] != head[b])
    {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, query(1, 0, n - 1, pos[head[a]], pos[a]));
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, query(1, 0, n - 1, pos[a], pos[b]));
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        tree[y].push_back(x);
        tree[x].push_back(y);
    }

    memset(heavy, -1, sizeof(heavy));
    cur_pos = 0;

    dfs(1, -1);
    decompose(1, 1);

    build(1, 0, n - 1);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, x;
            cin >> s >> x;
            update(1, 0, n - 1, pos[s], x);
            val[s] = x;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b) << endl;
        }
    }
    return 0;
}
