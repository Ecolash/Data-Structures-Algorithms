// REMOVE THE LAST '1' BIT (LEAST SIGNIFICANT BIT)

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a;
    cin >> a;
    int b = a & (a - 1);
    cout << b << endl;
}

// IMPLEMENT POPCOUNT USING THIS IDEA

void popcount()
{
    int a;
    cin >> a;
    int count = 0;

    while (a != 0)
    {
        a = (a & (a - 1));
        count++;
    }
    cout << count << endl;
}

int main()
{
    solve();
    popcount();
    return 0;
}