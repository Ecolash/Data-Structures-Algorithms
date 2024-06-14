// SEGMENT TREE IMPLEMENTATION
// Kth Smallest Element Queries (0 < x < 10^5 + 1)

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 100001;
ll segment_tree[4 * N];
int size;

void insert(int index, int L, int R, int val)
{
    if (L == R)
    {
        segment_tree[index] = 1;
        return;
    }

    int mid = (L + R) / 2;
    if (val <= mid) insert(index * 2, L, mid, val);
    else insert(index * 2 + 1, mid + 1, R, val);
    segment_tree[index] = segment_tree[2 * index] + segment_tree[2 * index + 1];
}

void remove(int index, int L, int R, int val)
{
    if (L == R)
    {
        segment_tree[index] = 0;
        return;
    }

    int mid = (L + R) / 2;
    if (val <= mid) remove(index * 2, L, mid, val);
    else remove(index * 2 + 1, mid + 1, R, val);
    segment_tree[index] = segment_tree[2 * index] + segment_tree[2 * index + 1];
}

ll query(int index, int L, int R, int k)
{
    if (k > size || k <= 0) return -1;
    if (L == R) return L;
    int mid = (L + R) / 2;

    if (k <= segment_tree[2 * index]) return query(2 * index, L, mid, k);
    else return query(2 * index + 1, mid + 1, R, k - segment_tree[2 * index]);
}

int main()
{
    int q;
    int X, k;
    int type;
    size = 0;

    cin >> q;
    set<int> s;

    for (int i = 0; i < q; i++)
    {
        cin >> type;

        if (type == 1) // INSERT
        {
            cin >> X;
            if (s.find(X) == s.end())
            {
                insert(1, 0, 100000, X);
                s.insert(X);
                size++;
            }
        }

        else if (type == 2) // DELETE
        {
            cin >> X;
            if (s.find(X) != s.end())
            {
                remove(1, 0, 100000, X);
                s.erase(X);
                size--;
            }
        }

        else if (type == 3) // return Kth element
        {
            cin >> k;
            cout << query(1, 0, 100000, k) << endl;
        }
    }

    return 0;
}
