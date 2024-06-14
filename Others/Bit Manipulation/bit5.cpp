// CUMULATIVE XOR (repeating pattern property) from 1 to N

/*

f(n) = 1 ^ 2 ^ 3 ... ^ n

f(1) = 1
f(2) = 1 ^ 2 = 3
f(3) = 3 ^ 3 = 0
f(4) = 0 ^ 4 = 4

f(5) = 4 ^ 5 = 1
f(6) = 1 ^ 6 = 7
f(7) = 7 ^ 7 = 0
f(8) = 0 ^ 8 = 8

f(4K + 0) = 4K
f(4K + 1) = 1
f(4K + 2) = 4K + 3
f(4K + 3) = 0

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n % 4 == 0)
        cout << n << endl;

    if (n % 4 == 1)
        cout << 1 << endl;

    if (n % 4 == 2)
        cout << n + 1 << endl;

    else
        cout << 0 << endl;
}

int main()
{
    solve();
    return 0;
}