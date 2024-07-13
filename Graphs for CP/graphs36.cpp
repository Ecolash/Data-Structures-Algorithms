// EDGE SPACE REDUCTION APPLICATION
// FRIENDLY SPIDERS

// Link : https://codeforces.com/problemset/problem/1775/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = std::pair<ll, ll>;
using vl = std::vector<long long>;
using vp = std::vector<pl>;

const int N = 3e5 + 5;
int SPF[N];

vl graph[]

void precompute() 
{
    SPF[1] = 1;
    for(int i = 2; i < N; i++)
    {
        for(int j = i; j < N; j += i)
        if (SPF[j] == 0) SPF[j] = i;
    }
}

void solve() 
{
    int n, x;
    cin >> n;
    
    
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    precompute();
    solve();
    return 0;
}