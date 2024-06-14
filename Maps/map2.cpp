// MAPS
// FINDING ELEMENT IN MAP

#include <bits/stdc++.h>
using namespace std;

void find(map<int, string> m, int n)
{
    auto it = m.find(n);
    if (it == m.end()) cout << n << "-->" << " No value | KEY not found" << endl;
    else cout << n << "--> " << (*it).first << " | " << (*it).second << endl;
}

int main()
{
    map<int, string> m;

    m[1] = "abc";
    m[5] = "cdc";
    m[2] = "cba";
    m[6] = "adc";
    m[7] = "gdc";
    m[3] = "cfa";

    find(m, 1);
    find(m, 5);
    find(m, 3);
    find(m, 4);
    find(m, 9);
    return 0;
}
