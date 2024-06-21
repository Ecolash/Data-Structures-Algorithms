// LONGEST INCREASING SUBSEQUENCE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

#define rep(i,a,b) for(ll i = a;i < b;i++)
#define rev(i,a,b) for(ll i = a;i >= b;i--)
#define pb push_back
#define mp make_pair

// APPROACH - 1 : BRUTE FORCE APPROACH (checking all previous elements)
// TIME COMPLEXITY : O(N^2)
void solve1() {
    ll n;
    cin >> n;
    vl arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vl lis(n, 1);
    ll maxi = 1;

    for (int i = 1; i < n; i++)
    {
        rep(j, 0, i) if (arr[i] > arr[j]) lis[i] = max(lis[i], lis[j] + 1);
        maxi = max(lis[i], maxi);
    }
    cout << maxi << endl;
    return;
}

// APPROACH - 2 : BINARY SEARCH ON PREVIOUS ANSWERS (checking previous elements using binary search)
// TIME COMPLEXITY : O(N log N)

// Use binary search to find the index of the smallest element in lis which is >= arr[i]
// If found, replace that element with arr[i] (always optimal to have smaller number in LIS greedily)
// If no such element exists, append arr[i] to the end of list

void solve2() {
    ll n;
    cin >> n;
    vl arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vl lis;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it != lis.end()) *it = arr[i]; 
        else lis.pb(arr[i]); 
    }
    cout << lis.size() << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve2();
    return 0;
}
