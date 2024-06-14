// BIT TRIE APPLICATION
// Create a data structure that performs following operations
// + X --> add X to DS
// - X --> remove X from DS
// ? Y K --> no. of X s.t (X ^ Y) <= K

// X = --(already processed)---a---(to process)---
// Y = --(already processed)---b---(to process)---
// K = --(already processed)---c---(to process)---

// a ^ 0 <= 0 ====> count in 0 side
// a ^ 1 <= 0 ====> count in 1 side
// a ^ 0 <= 1 ====> add prefix of 0 side and count in 1 side
// a ^ 1 <= 1 ====> add prefix of 1 side and count in 0 side

/*
TEST CASE:
-------------------
20
+ 10
+ 20
+ 30
+ 40
+ 50
+ 60
? 15 20
? 15 27
- 40
? 15 5
+ 70
? 15 5
? 25 10
+ 80
+ 35
? 25 10
? 35 15
-35
? 35 15
? 0 100
*/

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
    ll getBit(ll num, ll i){ return (num >> i) & 1;}

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

    void remove(ll num)
    {
        node *curr = root;
        if (search(num) == false) return;
        for (ll i = 63; i >= 0; i--)
        {
            curr->prefix--;
            ll bit = getBit(num, i);
            if (curr->next[bit] == NULL) curr->next[bit] = new node();
            curr = curr->next[bit];
        }
        curr->prefix--;
    }

    bool search(ll num)
    {
        node *curr = root;
        for (ll i = 63; i >= 0; i--)
        {
            ll bit = getBit(num, i);
            if (curr->next[bit] == NULL) return false;
            curr = curr->next[bit];
        }
        if (curr->prefix - ((curr->next[0])? curr->next[0]->prefix : 0 + (curr->next[1])? curr->next[1]->prefix : 0 )) return true;
        return false;
    }

    ll query(ll y, ll k)
    {
        ll ans = 0;
        node *curr = root;
        for (ll i = 63; i >= 0; i--)
        {
            ll b = getBit(y, i);
            ll c = getBit(k, i);
            if (curr == NULL) return ans;
            if (c == 0) curr = curr->next[b];
            else if (c == 1)
            {
                if (curr->next[b] != NULL) ans += curr->next[b]->prefix;
                curr = curr->next[1 - b];
            }
        }
        if (curr != NULL) ans += curr->prefix;
        return ans;
    }
};

// SOLVE FUNCTION
// This function demonstrates usage of the Trie with integers.
void solve()
{
    Trie trie;
    ll q, y, k;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            cin >> y;
            trie.insert(y);
        }
        else if (c == '-')
        {
            cin >> y;
            trie.remove(y);
        }
        else if (c == '?')
        {
            cin >> y >> k;
            cout << trie.query(y, k) << "\n";
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
