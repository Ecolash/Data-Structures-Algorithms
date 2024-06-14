// PAIRWISE AND SUM IN ARRAY
// Given an array of n integers, find the sum of XOR of all pairs of numbers in the array.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

// Naive Solution: A Brute Force approach is to run two loops and time complexity is O(n^2).
/*
int pairANDSum(int arr[], int n)
{
    int ans = 0;
    // Consider all pairs (arr[i], arr[j) such that i < j

    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
         ans += arr[i] & arr[j];

    return ans;
}
*/

/*
Efficient Solution can solve this problem in O(n) time.

Suppose that numbers have a rightmost 1-bit, and b numbers have a 0-bit.
Then out of the pairs, aC2 of them will have 1 in the rightmost bit of the AND.
This is because there are aC2 ways to choose one number that has a 0-bit and one that has a 1-bit.
These bits will therefore contribute aC2 towards the total of all the ANDs.
This can be done in O(kn) time, where k is the number of bits in the given values.

arr[] = { 7, 3, 5 }
7 = 1 1 1
3 = 0 1 1
5 = 1 0 1
For bit position 0 :
    Bits with zero = 0
    Bits with one = 3
    Answer = (2 * 3 )/2 * 2 ^ 0 = 3

Similarly, for bit position 1 :
    Bits with zero = 1
    Bits with one = 2
    Answer = (1 * 2) / 2 * 2 ^ 1 = 2

Similarly, for bit position 2 :
    Bits with zero = 1
    Bits with one = 2
    Answer = (1 * 2)/2 * 2 ^ 2 = 4
 Final answer = 3 + 4 + 2 = 9
*/

void pairANDSum(vector<ll> a)
{
    ll n = a.size();
    ll ans = 0;

    for (int i = 0; i < 32; i++)
    {
        ll c0 = 0, c1 = 0;
        for (ll j = 0; j < n; j++)
        {
            if (a[j] & (1 << i))
                c1++;
        }
        ans += (c1 * (c1 - 1)) / 2 * pow(2, i);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> A(n, 0);

    for (ll i = 0; i < n; i++)
        cin >> A[i];

    pairANDSum(A);
    return 0;
}
