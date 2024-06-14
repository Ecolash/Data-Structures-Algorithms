// SEGMENT TREE
// LAZY PROPAGATION
//----------------------------------------------------------------
/*
    4 TYPES OF OPERATIONS:
    1 L R -> sum of all elements in [L, R]
    2 L R -> max of all elements in [L, R]
    3 L R -> min of all elements in [L, R]
    4 L R V -> set A[i] = V for all i in [L, R]

    3 range queries + 1 range update

*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 100001;
const int MAX = 1e9;
ll arr[N];

struct node
{
    ll sum, mini, maxi, lazy;
    bool isLazy;
    node()
    {
        sum = 0;
        mini = MAX;
        maxi = -MAX;
        isLazy = 0;
        lazy = 0;
    }
    node(ll x)
    {
        sum = mini = maxi = x;
        isLazy = 0;
    }
};

node segT[4 * N];

node merge(const node& node1, const node& node2)
{
    node temp;
    temp.sum = node1.sum + node2.sum;
    temp.mini = min(node1.mini, node2.mini);
    temp.maxi = max(node1.maxi, node2.maxi);
    return temp;
}

void build(int index, int L, int R)
{
    if (L == R)
    {
        segT[index] = node(arr[L]);
        return;
    }

    int mid = (L + R) / 2;
    build(index * 2, L, mid);
    build(index * 2 + 1, mid + 1, R);
    segT[index] = merge(segT[2 * index], segT[2 * index + 1]);
}

void push(int i, int L, int R)
{
    if (segT[i].isLazy)
    {
        segT[i].sum = segT[i].lazy * (R - L + 1);
        segT[i].mini = segT[i].maxi = segT[i].lazy;
        if (L != R)
        {
            segT[i<<1].lazy = segT[i].lazy;
            segT[i<<1|1].lazy = segT[i].lazy;
            segT[i<<1].isLazy = segT[i<<1|1].isLazy = 1;
        }
        segT[i].lazy = 0;
        segT[i].isLazy = 0;
    }
}

void update(int index, int L, int R, int lq, int rq, ll val)
{
    push(index, L, R);
    if (lq > R || rq < L) return;
    if (lq <= L and rq >= R)
    {
        segT[index].lazy = val;
        segT[index].isLazy = 1;
        push(index, L, R);
        return;
    }
    int mid = (L + R) / 2;
    update(index<<1, L, mid, lq, rq, val);
    update(index<<1|1, mid + 1, R, lq, rq, val);
    segT[index] = merge(segT[index<<1], segT[index<<1|1]);
}

node query(int index, int L, int R, int lq, int rq)
{
    push(index, L, R);
    if (lq > R || rq < L) return node();
    if (lq <= L and rq >= R) return segT[index];
    int mid = (L + R) / 2;
    return merge(query(index<<1, L, mid, lq, rq), query(index<<1|1, mid + 1, R, lq, rq));
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);

    ll type, l, r, val;
    while(q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r).sum << endl;
        }
        else if (type == 2)
        {
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r).maxi << endl;
        }
        else if (type == 3)
        {
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r).mini << endl;
        }
        else if (type == 4)
        {
            cin >> l >> r >> val;
            l--, r--;
            update(1, 0, n - 1, l, r, val);
        }
    }
    return 0;
}