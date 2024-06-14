// LIST REMOVALS CSES

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vp vector<pl>

const int N = 200001;
const int MAX = 1e9;
ll ans;

ll arr[N];
ll segT[4 * N];

void build(int index, int L, int R)
{
    if (L == R)
    {
        segT[index] = 1;
        return;
    }

    int mid = (L + R) / 2;
    build(index * 2, L, mid);
    build(index * 2 + 1, mid + 1, R);
    segT[index] = segT[2 * index] + segT[2 * index + 1];
}

void update(int index, int L, int R, int x)
{
    if (x > segT[index]) return;
    if (L == R)
    {
        segT[index] = 0;
        ans = arr[L];
        return;
    }

    int mid = (L + R) / 2;
    if (x <= segT[index * 2]) 
    {
        update(index * 2, L, mid, x);
        segT[index] = segT[2 * index] + segT[2 * index + 1];
        return;
    }
    else
    {
        update(index * 2 + 1, mid + 1, R, x - segT[index * 2]);
        segT[index] = segT[2 * index] + segT[2 * index + 1];
        return;
    }
}

int main()
{
    int n, q;
    int L, R, x;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans = 0;
        update(1, 0, n - 1, x);
        cout <<  ans << ' ';
    }
    cout << endl;
    return 0;
}