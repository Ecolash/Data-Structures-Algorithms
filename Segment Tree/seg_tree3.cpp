// SEGMENT TREE IMPLEMENTATION
// Dynamic Range Minimum Queries

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 200001;

ll arr[N];
ll segment_tree[4 * N];

void build(int index, int L, int R)
{
    if (L == R)
    {
        segment_tree[index] = arr[L];
        return;
    }

    int mid = (L + R) / 2;
    build(index * 2, L, mid);
    build(index * 2 + 1, mid + 1, R);
    segment_tree[index] = min(segment_tree[2 * index], segment_tree[2 * index + 1]);
}

void update(int index, int L, int R, int pos, int val)
{
    if (pos < L || pos > R)
        return;

    if (L == R)
    {
        segment_tree[index] = val;
        arr[L] = val;
        return;
    }

    int mid = (L + R) / 2;
    update(index * 2, L, mid, pos, val);
    update(index * 2 + 1, mid + 1, R, pos, val);
    segment_tree[index] = min(segment_tree[2 * index], segment_tree[2 * index + 1]);
}

ll query(int index, int L, int R, int QL, int QR)
{
    if (L > QR || R < QL)
        return INT_MAX;

    if (QL <= L and QR >= R)
        return segment_tree[index];

    int mid = (L + R) / 2;
    ll x = query(2 * index, L, mid, QL, QR);
    ll y = query(2 * index + 1, mid + 1, R, QL, QR);
    return min(x, y);
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
            cout << query(1, 0, n - 1, L - 1, R - 1) << endl;
        }
    }

    return 0;
}