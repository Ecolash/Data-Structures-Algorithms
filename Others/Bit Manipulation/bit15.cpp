// LEXIOGRAPHICALLY MAXIMAL PREFIX AND
// (lesson on AMORTISTRATION of TC)
/*----------------------------------------/*
    You are given an array A of size N.
    You can rearrange the elements of A as you want.
    After that, construct an array B of size N:
        B[0] = A[0]
        B[i] = B[i - 1] & A[i]
        Find lexiographically maximal B
/*----------------------------------------/*
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<long long>;
using vp = vector<pl>;
using vs = vector<string>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define po pop_back

int main()
{
    vl v;
    v = {9, 9, 1, 1, 4};    // 9 9 1 1 0
    // v = {1, 2, 3, 4, 5};  // 5 4 0 0 0
    // v = {1, 1, 1, 1, 1};  // 1 1 1 1 1 

    int n = v.size();
    int f = max_element(v.begin(), v.end()) - v.begin();
    vl taken(n, 0), ans;
    ans.pb(v[f]);

    ll curr = v[f];
    taken[f] = 1;

    // TC : O(32. n)
    // This is because at each step, 1 bit in curr changes from 1 to 0 surely
    for (int i = 0; i < n; ++i)
    while (ans.size() < n)
    {
        ll mx = 0;
        vl temp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            temp[i] = v[i] & curr;
            if (taken[i] == 1) continue;
            mx = max(temp[i], mx);
        }
        for (int i = 0; i < n; ++i)
        if (taken[i] == 0 and temp[i] == mx)
        {
            taken[i] = 1;
            ans.push_back(v[i]);
        }
        curr = mx;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0) ans[i] &= ans[i-1]; 
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}