#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = std::vector<long long>;
ll mod = 1e9 + 7;
ll MAX = 1e9;

struct matrix
{
    ll n;
    ll mat[50][50];
};

matrix multiply(matrix a, matrix b) 
{
    matrix res;
    res.n = a.n;
    for (ll i = 0; i < res.n; i++)
    for (ll j = 0; j < res.n; j++) 
    {
        res.mat[i][j] = 0;
        for (ll k = 0; k < a.n; k++) res.mat[i][j] = (res.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % mod) % mod;
    }
    return res;
}

matrix power(matrix mat, ll p)
{
    if (p == 1) return mat;
    matrix res = power(mat, p / 2);
    res = multiply(res, res);
    if (p & 1) res = multiply(res, mat);
    return res;
}

signed main() {
    ll n, k;
    cin >> n >> k;
    matrix M;
    M.n = n;
    for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++) cin >> M.mat[i][j];

    ll ans = 0;
    matrix res = power(M, k);
    for (ll i = 0; i < n; i++) 
    for (ll j = 0; j < n; j++)
    ans = (ans + res.mat[i][j]) % mod;
    cout << ans;
    return 0;
}