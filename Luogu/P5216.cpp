// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, a[100005], app[100005], ans, fact[100005], ifact[100005];
int C(int n, int m) { return 0 <= m && m <= n ? 1ll * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (long long i = 1; i <= 100000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[100000] = power(fact[100000], MOD - 2);
    for (long long i = 100000; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    std::cin >> n;
    for (int i = 1, x; i <= n; ++i)
        std::cin >> x, ++a[x];
    for (int i = 1; i <= 100000; ++i)
        for (int j = 1; i * j <= 100000; ++j)
            app[i * j] += a[i];
    for (int i = 1; i <= 100000; ++i)
        if (a[i])
            ans = (ans +
                   1ll * i * C(n, app[i]) % MOD * a[i] % MOD * fact[app[i] - 1] % MOD * fact[n - app[i]] % MOD) %
                  MOD;
    std::cout << ans << std::endl;
    return 0;
}