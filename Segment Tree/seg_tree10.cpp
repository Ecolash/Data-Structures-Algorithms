//  COORDINATE COMPRESSION
//  COMPRESSED SEGMENT TREE
/*
    Coordinate compression is a technique used to map large or sparse coordinate values into a smaller range of indices.
    Typically starting from 1 and going up to the number of unique values. 
    This technique is useful where direct indexing with large coordinate values may be inefficient or impractical.
*/

/*
Use this technique to find length of the longest subsequence of an array A ST:
For the subsequence, the absolute difference between 2 consecutive indices is <= D
i.e. abs(A[i] - A[j]) <= D for i < j. Find longest subsequence length
Problem is similar to LIS, we use DP
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<long long>
#define ml map<ll, ll>
const int N = 200001;
const int MAX = 1e9;

ll arr[N];
ll segment_tree[4 * N];

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

void update(int i, int L, int R, int pos, ll val)
{
    if (pos < L || pos > R) return;
    if (L == R)
    {
        segment_tree[i] = max(segment_tree[i], val);
        return;
    }
    int mid = (L + R)>>1;
    update(i<<1, L, mid, pos, val);
    update(i<<1|1, mid+1, R, pos, val);
    segment_tree[i] = max(segment_tree[i<<1], segment_tree[i<<1|1]);
}

ll query(int i, int L, int R, int lq, int rq)
{
    if (L > rq || R < lq) return 0;
    if (L >= lq && R <= rq)
    {
        ll ans = segment_tree[i];
        return ans;
    }
    int mid = (L + R)>>1;
    ll x = query(i<<1, L, mid, lq, rq);
    ll y = query(i<<1|1, mid+1, R, lq, rq);
    return max(x, y);
}

void solve() {
    ll n, D, ans = 0;
    cin >> n >> D;
    CompSet X;
    X.add(MAX);
    X.add(-MAX);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        X.add(arr[i]);
    }

    X.build();
    ll DP[n];
    for (int i = 0; i < n; i++) 
    {
        ll lo = X.getPrev(arr[i] - D);
        ll hi = X.getNext(arr[i] + D);
        ll x = query(1, 0, X.getCount(), lo, hi);

        DP[i] = x + 1;
        update(1, 0, X.getCount() - 1, X.getComp(arr[i]), DP[i]);
        ans = max(ans, DP[i]);
    } 

    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}