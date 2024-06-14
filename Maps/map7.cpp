// APPLICATION OF MAPS
// FINDING SMALLEST K-MEX ELEMENT

/*
----------------------------------------------------------------------------------------------------------
Initially you have a set containing one element — 0. You need to handle q queries of the following types:

+ x — add the integerto the set. It is guaranteed that this integer is not contained in the set;
? k — find the k-mex of the set of numbers
The k-mex is the smallest non -ve integer x that is divisible by k and not contained in the set.
----------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, x;
    cin >> q;
    map<int, int> p1, p2;
    char type;
    while (q--)
    {
        cin >> type;
        cin >> x;
        if (type == '+') p1[x] = 1;
        else
        {
            while (p1[p2[x] + x]) p2[x] += x;
            cout << p2[x] + x << "\n";
        }
    }
    return;
}