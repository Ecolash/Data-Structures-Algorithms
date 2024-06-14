// MAXIMUM PAIRWISE XOR VALUE IN ARRAY
// Given an array of n integers, find the max among XOR of all pairs of numbers in the array.

// C++ implementation of the above approach

#include <bits/stdc++.h>
using namespace std;

int max_xor(int arr[], int n)
{
    int Max = 0, mask = 0;
    set<int> S;

    for (int i = 30; i >= 0; i--)
    {

        // Set the i'th bit in mask like 100000, 110000, 111000..
        mask |= (1 << i);
        for (int i = 0; i < n; ++i)
        {
            S.insert(arr[i] & mask);
        }

        int newMax = Max | (1 << i);
        for (int prefix : S)
        {
            // Find two pair in set such that a^b = newMax which is the highest possible bit can be obtained
            if (S.count(newMax ^ prefix))
            {
                Max = newMax;
                break;
            }
        }
        S.clear();
    }
    return Max;
}

// Driver Code
int main()
{

    int arr[] = {25, 10, 2, 8, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << max_xor(arr, n) << endl;

    return 0;
}
