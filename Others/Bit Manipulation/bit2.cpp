#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a;
    cin >> a;

    cout << "No. of leading 0: " << __builtin_clz(a) << endl;
    cout << "No. of trailing 0: " << __builtin_ctz(a) << endl;
    cout << "No. of 1 bits: " << __builtin_popcount(a) << endl;
}

// NOTE : A + B = (A & B) + (A | B)

int main()
{
    solve();
    return 0;
}
