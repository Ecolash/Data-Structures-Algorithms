// ---------------------------------------------------------------------------------------------
/* HEIGHT PROBLEM
// (Kth LARGEST ELEMENT)
------------------------------------------------------------------------------------------------
    N people with all distinct height are standing in a queue
    We are given ARR[i] which is the number of people of greater heightin front of ith person
    We need to assign the height of person in the line from a random height array
*/

/* SOLUTION:
    We build the ans array from the last (right to left)
    We start from the last element and assign the height of the last element as the (K + 1)th greatest element
    If its 0, we assign the height to be max
    If it is 1, we assign the second smallest value, so that only 1 person of greater height can be in front

    We recursively build the ans array by removing the assigned value from the set
    Then we assign the height of the element at last as the (K + 1)th greatest element
 */


#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100001;
ll segment_tree[4 * N];
int size;

void insert(int index, int L, int R, int val)
{
    if (L == R)
    {
        segment_tree[index] = 1;
        return;
    }

    int mid = (L + R) / 2;
    if (val <= mid) insert(index * 2, L, mid, val);
    else insert(index * 2 + 1, mid + 1, R, val);
    segment_tree[index] = segment_tree[2 * index] + segment_tree[2 * index + 1];
}

void remove(int index, int L, int R, int val)
{
    if (L == R)
    {
        segment_tree[index] = 0;
        return;
    }

    int mid = (L + R) / 2;
    if (val <= mid) remove(index * 2, L, mid, val);
    else remove(index * 2 + 1, mid + 1, R, val);
    segment_tree[index] = segment_tree[2 * index] + segment_tree[2 * index + 1];
}

ll query(int index, int L, int R, int k)
{
    if (k > size || k <= 0) return -1;
    if (L == R) return L;
    int mid = (L + R) / 2;

    // Inverted condition
    if (k <= segment_tree[2 * index + 1]) return query(2 * index + 1, mid + 1, R, k);
    else return query(2 * index, L, mid, k - segment_tree[2 * index + 1]); 
}

int main()
{
    int n, h, p; // (number of persons in line)

    cin >> n;
    vector<ll> order(n), ans(n);
    size = n;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        insert(1, 0, 100000, h);
    }

    for (int i = 0; i < n; i++) cin >> order[i];

    for (int i = n - 1; i >= 0; i--)
    {
        p = order[i];
        ans[i] = query(1, 0, 100000, p + 1);
        remove(1, 0, 100000, ans[i]);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
