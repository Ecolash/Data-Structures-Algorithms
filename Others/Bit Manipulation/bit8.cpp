// CHECK IF ith BIT IN A NUMBER IS SET(1) or UNSET(0)

#include <bits/stdc++.h>
using namespace std;

void isKthBitSet(int n, int k)
{
    if (n & (1 << k))
        cout << "SET";
    else
        cout << "NOT SET";
}

// Driver code
int main()
{
    int n = 5, k = 1;
    isKthBitSet(n, k);
    return 0;
}