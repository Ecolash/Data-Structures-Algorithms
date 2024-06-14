// SALARY QUERY
// COORDINATE COMPRESSION

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vp vector<pl>
#define ml map<ll, ll>

const int N = 200005;
const int MAX = 1e9;
ll ans;

ll arr[N];
ll segT[4 * N];

class CompSet
{
    ml compValue;
    vl revMap;
    ll count;

public:
    void add(ll x)
    {
        compValue[x];
    }

    void build()
    {
        count = 0;
        for (auto &i : compValue)
        {
            revMap.emplace_back(i.first);
            i.second = count;
            count++;
        }
    }

    ll getComp(ll x) { return compValue[x]; }

    ll getOrig(ll x) { return revMap[x]; }

    int getCount() { return count; }

    ll getPrev(ll x)
    {
        auto it = compValue.upper_bound(x); it--;
        return it->second;
    }

    ll getNext(ll x)
    {
        auto it = compValue.lower_bound(x);
        return it->second;
    }
};

void add(int index, int L, int R, int pos)
{
    if (pos < L || pos > R) return;
    if (L == R)
    {
        segT[index]++;
        return;
    }

    int mid = (L + R) / 2;
    add(index * 2, L, mid, pos);
    add(index * 2 + 1, mid + 1, R, pos);
    segT[index] = segT[2 * index] + segT[2 * index + 1];
}

void remove(int index, int L, int R, int pos)
{
    if (pos < L || pos > R) return;
    if (L == R)
    {
        segT[index]--;
        return;
    }

    int mid = (L + R) / 2;
    remove(index * 2, L, mid, pos);
    remove(index * 2 + 1, mid + 1, R, pos);
    segT[index] = segT[2 * index] + segT[2 * index + 1];
}

int query(int index, int L, int R, int QL, int QR)
{
    if (L > QR || R < QL) return 0;
    if (QL <= L and QR >= R) return segT[index];

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
    CompSet comp;
    map<int, pl> queries;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        comp.add(arr[i]);
    }

    comp.build();
    for (int i = 0; i < n; i++)
    {
        ll x = comp.getComp(arr[i]);
        add(1, 0, n - 1, x);
    }

    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            
        }
    }

    return 0;
}