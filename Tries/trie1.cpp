// STRING TRIES
// Basic Function Implementations

/*
=========================================================================
1) INSERT FUNCTION
-------------------------------------------------------------------------
For each character in the word: Calculate its index as ch - 'a'
If the corresponding child node does not exist, create a new node.
Move to the child node and increment the prefix counter.
At end of string, add the word to the ends list of the terminal node.
Time Complexity: O(L), where L is the length of the word being inserted

=========================================================================
2) SEARCH FUNCTION
-------------------------------------------------------------------------
Start at the root node. For each character in the word:
Calculate its index, if the corresponding child node does not exist, return false.
Else Move to the child node recursively till end of string
At end of string, check if the word exists in the ends list of the terminal node.
Time Complexity: O(L + k), k is no. of words in ends vectors (max k = no. of words)

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
    int prefix;     // count of strings having this as prefix
    vs ends;        //  list of strings that end here
    node *next[26]; // next node for each character
    node() {
        prefix = 0;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class Trie {
private:
    node* root;

    int charToi(char ch) {
        return ch - 'a';
    }

public:
    Trie() { root = new node(); }
    ~Trie() { deleteTrie(root); }

    void deleteTrie(node* curr) {
        rep(i, 0, 26) if (curr->next[i])  deleteTrie(curr->next[i]);
        delete curr;
    }

    void insert(const string& s) {
        node* curr = root;
        for (char ch : s) {
            curr->prefix++;
            int i = ch - 'a';
            if (curr->next[i] == NULL) curr->next[i] = new node();
            curr = curr->next[i];
        }
        curr->ends.pb(s);
    }

    bool search(const string& s) {
        node* curr = root;
        for (char ch : s) {
            int i = ch - 'a';
            if (curr->next[i] == NULL) return false;
            curr = curr->next[i];
        }
        for (const string& ends : curr->ends) if (ends == s) return true;
        return false;
    }

    bool startsWith(const string& prefix) {
        node* curr = root;
        for (char ch : prefix) {
            int i = ch - 'a';
            if (curr->next[i] == NULL) return false;
            curr = curr->next[i];
        }
        return (curr->prefix > 0);
    }
};


void solve() {
    Trie trie;
    trie.insert("hello");
    trie.insert("hell");
    trie.insert("heaven");
    trie.insert("goodbye");

    cout << boolalpha;                                               
    cout << trie.search("hello") << endl;       // T
    cout << trie.search("hell") << endl;        // T
    cout << trie.search("heaven") << endl;      // T
    cout << trie.search("good") << endl;        // F
    
    cout << trie.startsWith("he") << endl;      // T
    cout << trie.startsWith("good") << endl;    // T
    cout << trie.startsWith("bye") << endl;     // F
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}