// SEGMENT TREE IMPLEMENTATION
// Range Sum Queries

#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

int arr[N];
int segment_tree[4 * N];

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
    segment_tree[index] = segment_tree[2 * index] + segment_tree[2 * index + 1];
}

int query(int index, int L, int R, int QL, int QR)
{
    if (L > QR || R < QL)
        return 0;

    if (QL <= L and QR >= R)
        return segment_tree[index];

    int mid = (L + R) / 2;
    int x = query(2 * index, L, mid, QL, QR);
    int y = query(2 * index + 1, mid + 1, R, QL, QR);
    return (x + y);
}

int main()
{
    int n, q;
    int L, R;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        cin >> L >> R;
        cout << query(1, 0, n - 1, L - 1, R - 1) << endl;
    }

    return 0;
}