// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const long long INF = LLONG_MAX >> 1;
const int MOD = 998244353;
int n, m, v, fact[3000005], ifact[3000005], a[505][505], ans = 1;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int INV(int x) { return power(x, MOD - 2); }
int C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> v;
    v -= n + m - 1;
    if (v < 0)
        return std::cout << 0 << std::endl, 0;
    fact[0] = 1;
    for (int i = 1; i <= 3000000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[3000000] = power(fact[3000000], MOD - 2);
    for (int i = 3000000; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    for (int i = 0; i != v; ++i)
        for (int j = 0; j != v; ++j)
            a[i][j] = C(n + m, n + i - j);
    // for (int i = 0; i != v; ++i, std::cout << std::endl)
    //     for (int j = 0; j != v; ++j)
    //         std::cout << a[i][j] << ' ';
    for (int i = 0; i != v; ++i)
        for (int j = i; ++j < v;)
        {
            int g = (MOD - a[j][i]) * INV(a[i][i]) % MOD;
            for (int k = i; k != v; ++k)
                a[j][k] = (a[j][k] + g * a[i][k]) % MOD;
        }
    for (int i = 0; i != v; ++i)
        ans = ans * a[i][i] % MOD;
    std::cout << ans << std::endl;
    return 0;
}