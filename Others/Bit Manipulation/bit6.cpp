// CUMULATIVE XOR from L to R

/*
NOTE:  XOR-ing a value with itself results in 0

X ^ X = 0
Y ^ 0 = Y
X ^ Y ^ X = Y

f(n) = 1 ^ 2 ^ 3 ... ^ n
f(l , r) = f(r) ^ f(l - 1) (all values from 1 to l - 1 get nullified)
*/

#include <bits/stdc++.h>
using namespace std;

int XOR(int n)
{
    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;

    return 0;
}

void solve()
{
    int L, R;
    cin >> L >> R;

    cout << (XOR(L - 1) ^ XOR(R)) << endl;
}

int main()
{
    solve();
    return 0;
}