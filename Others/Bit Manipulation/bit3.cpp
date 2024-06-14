#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a;
    cin >> a;

    int i = 3;
    cout << "i-TH BIT: ";
    cout << ((a >> i) & 1) << endl;        // WAY 1
    cout << ((a & (1 << i)) >> i) << endl; // WAY 2
}

int main()
{
    solve();
    return 0;
}
