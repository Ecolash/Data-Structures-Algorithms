// MAPS
// INITIALIZATION OF MAP

#include <bits/stdc++.h>
using namespace std;

void print_map(map<int, string> m)
{
    map<int, string>::iterator it;
    cout << endl;
    for (it = m.begin(); it != m.end(); it++) cout << (*it).first << " | " << (*it).second << endl;
    cout << endl;
}

void print_map_v2(map<int, string> m)
{
    map<int, string>::iterator it;
    cout << "Size : " << m.size() << endl;
    for (auto &ptr : m) cout << ptr.first << " | " << ptr.second << endl;
    cout << endl;
}

int main()
{
    map<int, string> m;

    m[1] = "abc";
    m[5] = "cdc";
    m[2] = "cba";
    print_map(m);

    m.insert({3, "efg"});
    m.insert({4, "efg"});
    print_map_v2(m);
    return 0;
}
