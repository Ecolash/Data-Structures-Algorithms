// UNORDERED MAPS
// INITIALIZATION OF UNORDERED MAP

#include <bits/stdc++.h>
using namespace std;

void print_unordered_map(unordered_map<int, string> m)
{
    unordered_map<int, string>::iterator it;
    cout << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " | " << (*it).second << endl;
    }
    cout << endl;
}

void print_unordered_map_v2(unordered_map<int, string> m)
{
    unordered_map<int, string>::iterator it;
    cout << "Size : " << m.size() << endl;
    for (auto &ptr : m)
    {
        cout << ptr.first << " | " << ptr.second << endl;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, string> m;

    m[1] = "abc";
    m[5] = "cdc";
    m[2] = "cba";
    print_unordered_map(m);

    m.insert({3, "efg"});
    m.insert({4, "efg"});
    print_unordered_map_v2(m);
    return 0;
}
