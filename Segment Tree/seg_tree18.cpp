// Count of Range Sum
// Given an integer array nums and two integers lower and upper
// Return the number of range sums that lie in [lower, upper] inclusive

#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int segTree[4 * N];

void build(int n) {
    for (int i = 0; i < n; ++i) segTree[i + n] = 1;
    for (int i = n - 1; i > 0; --i) segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
}

void update(int n, int idx, int val) 
{
    idx += n;
    segTree[idx] += val;
    while (idx > 1) 
    {
        if (idx % 2) segTree[idx / 2] = segTree[idx - 1] + segTree[idx];
        else segTree[idx / 2] = segTree[idx] + segTree[idx + 1];
        idx >>= 1;
    }
}

int query(int n, int l, int r) 
{
    int count = 0;
    l += n, r += n;
    while (l <= r) 
    {
        if (l % 2) count += segTree[l++];
        if (r % 2 == 0) count += segTree[r--];
        l >>= 1;
        r >>= 1;
    }
    return count;
}

int solve(vector<int>& nums, int lower, int upper) 
{
    vector<long long> sum(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) sum[i + 1] = sum[i] + nums[i];

    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());
    int n = A.size();
    build(n);
    int count = 0;
    for (const auto &x : sum) 
    {
        int idx = lower_bound(A.begin(), A.end(), x) - A.begin();
        int low = lower_bound(A.begin(), A.end(), x + lower) - A.begin();
        int high = upper_bound(A.begin(), A.end(), x + upper) - A.begin() - 1;
        update(n, idx, -1);
        count += query(n, low, high);
    }
    return count;
}

int main() {
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)  cin >> nums[i];
    cout << solve(nums, L, R) << endl;
    return 0;
}
