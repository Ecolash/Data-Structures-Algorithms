// SEGMENT TREE
// LAZY PROPAGATION
//----------------------------------------------------------------
/*
    QUERY : L R X -> return number of elements in A[] in range (L, R) <= X

    We solve this by offline queries
    Let the queries be
    L1 R1 X1
    L2 R2 X2
    L3 R3 X3
    L4 R4 X4
    ...

    We solve the queries in ascending order of X
    We maintain a isGreater array of elements (initially all 0)
    A range sum from L to R is our answer
    Once we set it as true, we are done with it and no need to change it further

    We sort our array and maintain a current pointer, which checks till which X we have checked
*/
#include <bits/stdc++.h>

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vp vector<pl> 

using namespace std;
const int N = 200001;

ll count_[N];
ll segTree[4 * N];

void update(int index, int L, int R, int pos, int val)
{
    if (pos < L || pos > R) return;
    if (L == R)
    {
        segTree[index] = val;
        count_[L] = val;
        return;
    }

    int mid = (L + R) / 2;
    update(index * 2, L, mid, pos, val);
    update(index * 2 + 1, mid + 1, R, pos, val);
    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

ll query(int index, int L, int R, int QL, int QR)
{
    if (L > QR || R < QL) return 0;
    if (QL <= L and QR >= R) return segTree[index];

    int mid = (L + R) / 2;
    ll x = query(2 * index, L, mid, QL, QR);
    ll y = query(2 * index + 1, mid + 1, R, QL, QR);
    return (x + y);
}

int main()
{
    int n, q;
    int L, R, X;

    cin >> n >> q;
    vector<ll> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    vp sorted(n);
    for (int i = 0; i < n; i++) sorted[i] = {v[i], i};
    sort(sorted.begin(), sorted.end());

    vector<vector<int>> queries(q, vector<int>(4, 0));
    vector<int> ans(q, 0);

    for (int i = 0; i < q; i++)
    {
        cin >> L >> R >> X;
        L--; R--;
        queries[i][0] = X;
        queries[i][1] = L;
        queries[i][2] = R;
        queries[i][3] = i;
    }

    sort(queries.begin(), queries.end());
    int curr = 0;
    for(int i = 0; i < q; i++)
    {
        while(curr < n and sorted[curr].first <= queries[i][0])
        {
            update(1, 0, n - 1, sorted[curr].second, 1);
            curr++;
        }

        ans[queries[i][3]] = query(1, 0, n - 1, queries[i][1], queries[i][2]);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << endl;
    return 0;
}