// STACK APPLICATION
/* ----------------------------------------------------------------
NEXT GREATER ELEMENT (NGE) AND NEXT SMALLER ELEMENT (NSE)
PREVIOUS GREATER ELEMENT (PGE) AND PREVIOUS SMALLER ELEMENT (PSE)

You are given an an array A of length N.
The beauty of a subarray is defined as the diff b/w  max element & min element in the subarray.
You need to find the sum of beauty of all the subarrays of the given array

Link : https://www.hackerrank.com/contests/goc-cdc-series-11/challenges/subarray-beauty/problem
----------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

signed main()
{
    ll n, ans = 0;
    cin >> n;
    vl v(n);
    vl NGE(n, n), NSE(n, n);   // Initialize with n to represent the end of the array
    vl PGE(n, -1), PSE(n, -1); // Initialize with -1 to represent the beginning of the array
    for (int i = 0; i < n; i++) cin >> v[i];
    stack<ll> S1, S2;

    // Compute Next Greater Element (NGE)
    for (int i = 0; i < n; i++)
    {
        while (!S1.empty() && v[S1.top()] < v[i])
        {
            NGE[S1.top()] = i;
            S1.pop();
        }
        S1.push(i);
    }

    // Compute Next Smaller Element (NSE)
    for (int i = 0; i < n; i++)
    {
        while (!S2.empty() && v[S2.top()] > v[i])
        {
            NSE[S2.top()] = i;
            S2.pop();
        }
        S2.push(i);
    }

    while(!S1.empty()) S1.pop();
    while(!S2.empty()) S2.pop();

    // Compute Previous Greater Element (PGE)
    for (int i = n - 1; i >= 0; i--)
    {
        while (!S1.empty() && v[S1.top()] <= v[i])
        {
            PGE[S1.top()] = i;
            S1.pop();
        }
        S1.push(i);
    }

    // Compute Previous Smaller Element (PSE)
    for (int i = n - 1; i >= 0; i--)
    {
        while (!S2.empty() && v[S2.top()] >= v[i])
        {
            PSE[S2.top()] = i;
            S2.pop();
        }
        S2.push(i);
    }

    // Compute the final answer
    for (ll i = 0; i < n; i++)
    {
        ll maxi = (i - PGE[i]) * (NGE[i] - i); // Times v[i] is maximum
        ll mini = (i - PSE[i]) * (NSE[i] - i); // Times v[i] is minimum
        ans += maxi * v[i];
        ans -= mini * v[i];
    }

    cout << ans << "\n";
    return 0;
}
