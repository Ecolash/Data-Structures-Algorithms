// MAKE WORDS FROM WORDS
// Link : https://www.hackerrank.com/contests/goc-cdc-series-19/challenges/aryan-and-his-stickers

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vs = vector<string>;
using vvl = vector<vl>;

ll mod = 1e9 + 7;
ll MAX = 1e9;

ll DP[1 << 15];
vs stickers;
string s;
ll ans;
ll s1, s2, n;

void solve(ll mask, ll cnt)
{
    if (cnt >= ans) return; 
    if (mask == ((1LL << s1) - 1))
    {
        ans = min(ans, cnt);
        return;
    }
    if (DP[mask] != -1 and DP[mask] <= cnt) return;
    DP[mask] = cnt;

    for(int x = 0; x < n; x++)
    {
        multiset<char> c;
        string t = stickers[x];
        ll nmask = mask;
        c.insert(t.begin(), t.end());

        for(int i = 0; i < s1; i++)
        {
            if ((nmask & (1LL << i)) == 0 and c.find(s[i]) != c.end())
            {
                c.erase(c.find(s[i]));
                nmask = nmask | (1LL << i);
            }
        }
        if (mask != nmask) solve(nmask, cnt + 1);
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> n;
    set<char> c;
    for (ll i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        stickers.push_back(t);
        c.insert(t.begin(), t.end());
    }
    s1 = s.length();
    bool f = 1;
    for(ll i = 0; i < s1; i++) if(c.find(s[i]) == c.end()) f = 0;

    if (f == 0)
    {
        cout << "Impossible";
        return 0;
    }

    ans = 1e18;
    memset(DP, -1, sizeof(DP));
    solve(0, 0);
    cout << ans;
    return 0;
}
