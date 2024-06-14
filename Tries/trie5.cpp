// BIT TRIE APPLICATION
// Given an array of N numbers find i, j (i != j) st A[i] ^ A[j] is maximum

// For every A[i] we do XOR query (which basically tries to select the opposite bit in each step if possible)
// Finally we take max of all XOR queries over A[i]

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<long long>;
using vp = vector<pl>;
using vs = vector<string>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define po pop_back

struct node
{
    int prefix;
    node *next[2];
    node()
    {
        prefix = 0;
        next[0] = next[1] = NULL;
    }
};

class Trie
{
private:
    node *root;
    ll getBit(ll num, ll i) { return (num >> i) & 1; }

public:
    Trie() { root = new node(); }
    ~Trie() { deleteTrie(root); }

    void deleteTrie(node *curr)
    {
        rep(i, 0, 2) if (curr->next[i]) deleteTrie(curr->next[i]);
        delete curr;
    }

    void insert(ll num)
    {
        node *curr = root;
        for (ll i = 63; i >= 0; i--)
        {
            curr->prefix++;
            ll bit = getBit(num, i);
            if (curr->next[bit] == NULL) curr->next[bit] = new node();
            curr = curr->next[bit];
        }
        curr->prefix++;
    }

    ll MaxXOR(ll num)
    {
        node *curr = root;
        ll ans = 0;
        for (ll i = 63; i >= 0; i--)
        {
            ll bit = getBit(num, i);
            if (curr->next[bit ^ 1]!= NULL)
            {
                ans += ((bit ^ 1) << i);
                curr = curr->next[bit ^ 1];
            }
            else curr = curr->next[bit];
        }
        return ans;
    }

    
};

// SOLVE FUNCTION
// This function demonstrates usage of the Trie with integers.
void solve()
{
    vl v = {2,3,4,5,6,7,8,9,16};
    pl p;
    ll maxiXOR = 0;
    Trie t;
    rep(i, 0, v.size()) t.insert(v[i]);
    rep(i, 0, v.size())
    {
        ll a = v[i];
        ll b = t.MaxXOR(a);
        if (a ^ b > maxiXOR)
        {
            maxiXOR = a ^ b;
            p = {a, b};
        }
    }
    cout << p.first << " " << p.second << "\n";
    cout << maxiXOR; 
    return;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
