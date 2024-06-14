// BINARY SEARCH ON ANS

// A - array of 0's and 1's
// n - size of array, k - no. of bits you can toggle
// Find the maximum length of contiguous subarray of all 1's which can be formed by toggling bits

#include <bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n, int k, int x)
{
    int c0 = 0, c1 = 0;
    for (int i = 0; i < x; i++)
    {
        if (arr[i] == 0)
            c0++;
        else
            c1++;
    }

    if (c0 <= k)
        return true;

    for (int i = x; i < n; i++)
    {
        if (arr[i] == 0)
            c0++;
        else
            c1++;

        if (arr[i - x] == 0)
            c0--;
        else
            c1++;

        if (c0 <= k)
            return true;
    }
    return false;
}

int search(int arr[], int n, int k, int L, int R)
{
    int x = 0;
    int ans = 0;
    while (L <= R)
    {
        x = L + (R - L) / 2;
        if (solve(arr, n, k, x))
        {
            L = x + 1;
            ans = max(ans, x);
        }

        else
            R = x - 1;
    }
    return ans;
}

int main()
{

    int arr[] = {0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int L = 0, R = n;
    // Min possible ans = L  = 0
    // Max possible ans = R  = n
    cout << search(arr, n, k, L, R) << endl;

    return 0;
}
