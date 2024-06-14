// STRING TRIES
// For a set of strings, answer queries Q of the form:
// ? 'S' K -> all strings in the set that have atmost K position mismatch with string S
// The results must be of the same length as S

/*
TEST CASE:
------------------
8 2
abcd
axcd
albd
bcbb
acdb
pacc
aaaa
xxsx
2 abcd
4 xxxx
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
vs result;

struct node
{
    int prefix;     
    vs ends;        
    node *next[26]; 
    node() {
        prefix = 0;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class Trie {
public:
    node *root;

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

    void Kmismatches(node *curr, const string &prefix, int k, int pos, int mismatch) 
    {
        if (mismatch > k) return;
        if (pos == prefix.length()) {
            for (auto &x : curr->ends) result.pb(x);
            return;
        }
        for(int i = 0; i < 26; i++)
        {
            int z = prefix[pos] - 'a';
            if (curr->next[i] == NULL) continue;
            Kmismatches(curr->next[i], prefix, k, pos + 1, mismatch + (i != z));
        }
    }
};


void solve() {
    ll n, q, k;
    cin >> n >> q;
    string s, prefix;
    Trie trie;
    rep(i, 0, n)
    {
        cin >> s;
        trie.insert(s);
    }
    rep(i, 0, q)
    {
        cin >> k >> prefix;
        result.clear();
        trie.Kmismatches(trie.root, prefix, k, 0, 0);
        for (const string &word : result) cout << word << " ";
        cout << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}