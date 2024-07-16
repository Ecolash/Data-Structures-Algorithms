// DP OPTIMIZATIONS (USING SEGMENT TREE)
// LONGEST INCREASING SUBSEQUENCE - 2

/* Find the longest subsequence of nums that meets the following requirements:
===========================================================================
(1) --> The subsequence is strictly increasing and
(2) --> The diff b/w adjacent elements in the subsequence is at most k
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
int n;

void init(int n_) {
    n = n_;
    int size = (int)(ceil(log2(n)));
    size = (2 * pow(2, size)) - 1;
    tree = vector<int>(size, INT_MIN);
}

int query(int node, int start, int end, int l, int r) {
    if (l > end || r < start) return INT_MIN;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    int lc = query(2 * node + 1, start, mid, l, r);
    int rc = query(2 * node + 2, mid + 1, end, l, r);
    return max(lc, rc);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end)  tree[node] = max(tree[node], val);
    else 
    {
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node + 1, start, mid, idx, val);
        else update(2 * node + 2, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

int lengthOfLIS(vector<int>& nums, int k) {
    init(1e5 + 1);
    int result = 0;

    for (int i : nums) {
        int lower = max(0, i - k);
        int cur = 1 + query(0, 0, n - 1, lower, i - 1);
        update(0, 0, n - 1, i, cur);
        result = max(result, cur);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << lengthOfLIS(nums, k) << endl; 
    return 0;
}
