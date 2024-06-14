// BIT TRIE

// INSERT FUNCTION
// Convert the number to its binary representation and insert bit by bit
// Time Complexity: O(L), where L is the number of bits (usually 32 for int)

// SEARCH FUNCTION
// Convert the number to its binary representation and search bit by bit
// Time Complexity: O(L + k), where L is the number of bits, and k is the size of the ends vector


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
};

// SOLVE FUNCTION
// This function demonstrates usage of the Trie with integers.
void solve()
{
    Trie trie;
    trie.insert(10); // Binary: 1010
    trie.insert(5);  // Binary: 0101
    trie.insert(9);  // Binary: 1001
    trie.insert(6);  // Binary: 0110

    cout << boolalpha;
    cout << trie.search(10) << endl; // T
    cout << trie.search(5) << endl;  // T
    cout << trie.search(9) << endl;  // T
    cout << trie.search(7) << endl;  // F

    trie.remove(10); 
    trie.remove(11);
    cout << "-------------------------" << endl;
    cout << trie.search(10) << endl; // F
    cout << trie.search(5) << endl;  // T
    cout << trie.search(9) << endl;  // T
    cout << trie.search(7) << endl;  // F
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
