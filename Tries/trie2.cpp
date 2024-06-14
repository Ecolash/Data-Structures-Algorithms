// STRING TRIES
// For a set of strings, answer queries Q of the form:
// ? 'S' K -> lexiographically smallest top K strings for prefix match S

// TESTCASE:
// 8 5
// apple appx app apricot
// banana band bandana bandage 
// ap 2 
// band 3 
// ba 4 
// apr 3 
// band 1

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
    vs ends;        
    node *next[26]; 
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

    void dfs(node *curr, int K, priority_queue<string> &minHeap)
    {
        if (!curr) return;
        for (const string &word : curr->ends)
        {
            minHeap.push(word);
            if (minHeap.size() > K) minHeap.pop();
        }
        rep(i, 0, 26) if (curr->next[i]) dfs(curr->next[i], K, minHeap);
        return;
    }

    vs queryK(const string &prefix, int K)
    {
        node *curr = root;
        for (char ch : prefix)
        {
            int i = ch - 'a';
            if (curr->next[i] == nullptr) return {};
            curr = curr->next[i];
        }
        vs result;
        priority_queue<string> minHeap;
        dfs(curr, K, minHeap);
        while (!minHeap.empty())
        {
            string s = minHeap.top();
            result.push_back(s);
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
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
        cin >> prefix >> k;
        vs result = trie.queryK(prefix, k);
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