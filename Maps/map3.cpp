// MAPS
// ERASING ELEMENT IN MAP

#include <bits/stdc++.h>
using namespace std;

void print_map(map<int, string> m)
{
    map<int, string>::iterator it;
    cout << endl;
    for (it = m.begin(); it != m.end(); it++) cout << (*it).first << " | " << (*it).second << endl;
    cout << "_____________________________________________________";
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

    print_map(m);

    m.erase(7);
    m.erase(3);
    print_map(m);

    auto it = m.find(6);
    if (it != m.end()) m.erase(it);
    print_map(m);

    m.clear();
    print_map(m);
    return 0;
}
