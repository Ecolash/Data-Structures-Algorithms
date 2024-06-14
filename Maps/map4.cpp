// MAPS
// USING MAPS TO MAKE FREQUENCY TABLES ( count characters in a string )

#include <bits/stdc++.h>
using namespace std;

void print_map(map<char, int> m)
{
    map<char, int>::iterator it;
    cout << endl;
    for (it = m.begin(); it != m.end(); it++) cout << (*it).first << " | " << (*it).second << endl;
    cout << "_____________________________________________________";
}

int main()
{
    map<char, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        m[c] = m[c] + 1;
    }

    print_map(m);
    return 0;
}