// SLIDING WINDOW APPROACH

// A - array of 0's and 1's
// n - size of array, k - no. of bits you can toggle
// Find the maximum length of contiguous subarray of all 1's which can be formed by toggling bits

#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int k)
{
    int x = 0;
    int ans = 0;
    int head = -1;
    int tail = 0;
    int c0 = 0;

    while (tail < n)
    {
        while (head + 1 < n and c0 + (1 - arr[head + 1]) <= k)
        {
            head++;
            c0 = c0 + (1 - arr[head + 1]);
        }
        ans = max(ans, head - tail + 1);

        if (head >= tail)
        {
            c0 = c0 - (1 - arr[tail]);
            tail++;
        }

        else
        {
            tail++;
            head = tail - 1;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << search(arr, n, k) << endl;
    return 0;
}
