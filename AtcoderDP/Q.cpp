// MODIFICATION OF LCS
// (CONDITIONAL LCS)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using sl = std::set<ll>;
using ml = std::map<ll, ll>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

signed main() {
    ll n;
    cin >> n;
    vl arr(n), beauty(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> beauty[i];
    vector<pl> lis;

    for (int i = 0; i < n; i++)
    {
        pl x = make_pair(arr[i], beauty[i]); 
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it != lis.end())
        {
            if (beauty[i] >= it->second) *it = x;
            // else *it = x;
        }
        else lis.push_back(x);
    }

    ll ans = 0;
    cout << lis.size() << endl;
    for(int i = 0; i < lis.size(); i++) ans += lis[i].second;
    cout << ans << '\n';
    return 0;
}
