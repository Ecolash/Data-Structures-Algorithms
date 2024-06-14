// SEGMENT TREE IMPLEMENTATION
// Dynamic Max Range Prefix Sum Queries

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 200001;

struct node
{
    ll max_sum;
    ll total_sum;

    node(int x = 0)
    {
        max_sum = max(x, 0);
        total_sum = x;
    }
};

ll arr[N];
node segment_tree[4 * N];

node merge(node a, node b)
{
    node c;
    c.max_sum = max(a.max_sum, a.total_sum + b.max_sum);
    c.total_sum = a.total_sum + b.total_sum;
    return c;
}

void build(int index, int L, int R)
{
    if (L == R)
    {
        segment_tree[index] = node(arr[L]);
        return;
    }

    int mid = (L + R) / 2;
    build(index * 2, L, mid);
    build(index * 2 + 1, mid + 1, R);
    segment_tree[index] = merge(segment_tree[2 * index], segment_tree[2 * index + 1]);
}

void update(int index, int L, int R, int pos, int val)
{
    if (pos < L || pos > R)
        return;

    if (L == R)
    {
        arr[L] = val;
        segment_tree[index] = node(arr[L]);
        return;
    }

    int mid = (L + R) / 2;
    update(index * 2, L, mid, pos, val);
    update(index * 2 + 1, mid + 1, R, pos, val);
    segment_tree[index] = merge(segment_tree[2 * index], segment_tree[2 * index + 1]);
}

node query(int index, int L, int R, int QL, int QR)
{
    if (L > QR || R < QL)
        return node(0);

    if (QL <= L and QR >= R)
        return segment_tree[index];

    int mid = (L + R) / 2;
    node x = query(2 * index, L, mid, QL, QR);
    node y = query(2 * index + 1, mid + 1, R, QL, QR);
    return merge(x, y);
}

int main()
{
    int n, q;
    int L, R;
    int pos, X;
    int type;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> pos >> X;
            update(1, 0, n - 1, pos - 1, X);
        }

        else
        {
            cin >> L >> R;
            node N = query(1, 0, n - 1, L - 1, R - 1);
            cout << N.max_sum << endl;
        }
    }

    return 0;
}
