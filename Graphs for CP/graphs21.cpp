// CYCLE FINDING (CSES)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define vl vector<long long>
#define vp vector<pl>
#define F first
#define S second
#define mp make_pair

const int N = 2505;
const ll MAX = 1e18;

int n, m;
vl dist;
vector<int> parent;
vector<tuple<int, int, ll>> edges;

bool findNegativeCycle() {
    dist[1] = 0;
    int last = -1;

    for (int i = 1; i <= n; i++) {
        last = -1;
        for (auto &x: edges) {
            ll u = get<0>(x);
            ll v = get<1>(x);
            ll w = get<2>(x);
            if (dist[u] != MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                last = v;
            }
        }
    }

    if (last == -1) return false;

    for (int i = 1; i <= n; i++) last = parent[last];
    parent[0] = last; // Ensure a valid cycle start point.
    return true;
}

void printCycle() {
    int start = parent[0];
    vl cycle;
    for (int v = start;; v = parent[v]) {
        cycle.push_back(v);
        if (v == start && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for (int v : cycle) cout << v << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dist.resize(n + 1, MAX);
    parent.resize(n + 1, -1);

    int a, b;
    ll c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    if (findNegativeCycle()) {
        printCycle();
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
