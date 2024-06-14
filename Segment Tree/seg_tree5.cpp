// SEGMENT TREE IMPLEMENTATION
// Dynamic Range Sum Queries
// (Range Update, Point Query)

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 200001;

ll arr[N];
ll segment_tree[4 * N];

void update(int index, int L, int R, int QL, int QR, int val)
{
    if (L > QR || R < QL)
        return;

    if (QL <= L and QR >= R)
    {
        segment_tree[index] += val;
        return;
    }

    int mid = (L + R) / 2;
    update(index * 2, L, mid, QL, QR, val);
    update(index * 2 + 1, mid + 1, R, QL, QR, val);
}

ll query(int index, int L, int R, int pos)
{
    if (L > pos || R < pos)
        return 0;

    if (L == R)
        return segment_tree[index];

    ll ans = 0;
    ans += segment_tree[index];

    int mid = (L + R) / 2;
    ll x = (pos <= mid) ? query(2 * index, L, mid, pos) : query(2 * index + 1, mid + 1, R, pos);
    return (ans + x);
}

int main()
{
    int n, q;
    int L, R;
    int pos, X;
    int type;

    cin >> n >> q;
    memset(segment_tree, 0, sizeof(segment_tree));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> L >> R >> X;
            update(1, 0, n - 1, L - 1, R - 1, X);
        }

        else if (type == 2)
        {
            cin >> pos;
            cout << arr[pos - 1] + query(1, 0, n - 1, pos - 1) << endl;
        }
    }

    return 0;
}