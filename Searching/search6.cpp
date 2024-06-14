// TWO POINTER

// A - array of NUMBERS
// n - size of array, k - max no. of distinct elements in subarray
// Find the maximum length of contiguous subarray containing atmost k distinct elements

#include <bits/stdc++.h>
using namespace std;

int freq[100001];
int count_distinct;

void insert(int i)
{
    if (freq[i] == 0) count_distinct++;
    freq[i]++;
}

void remove(int i)
{
    freq[i]--;
    if (freq[i] == 0)
        count_distinct--;
}

int search(int arr[], int n, int k)
{
    int x = 0;
    int ans = 0;
    int head = -1;
    int tail = 0;
    count_distinct = 0;

    while (tail < n)
    {
        while (head + 1 < n and ((count_distinct < k and freq[arr[head + 1]] == 0) || (count_distinct <= k and freq[arr[head + 1]] > 0)))
        {
            head++;
            insert(arr[head + 1]);
        }
        ans = max(ans, head - tail + 1);

        if (head >= tail)
        {
            remove(arr[tail]);
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

    int arr[] = {0, 5, 4, 1, 6, 3, 1, 3, 1, 2, 2, 1, 1, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    memset(freq, 0, sizeof(freq));

    cout << search(arr, n, k) << endl;
    return 0;
}
