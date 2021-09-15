// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
const int N = 5000000;
int f[N + 5], fact[N + 5], inv[N + 5], pow2[N + 5];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B /= 2;
        A = 1ll * A * A % MOD;
    }
    return res;
}
int solve(int n, int k) { return 1ll * f[n - k] * pow2[k] % MOD * fact[n] % MOD * fact[n] % MOD * inv[k] % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    inv[N] = power(fact[N], MOD - 2);
    for (int i = N; i; --i)
        inv[i - 1] = 1ll * inv[i] * i % MOD;
    pow2[0] = 1;
    for (int i = 1; i <= N; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    f[0] = 1;
    f[1] = 0;
    for (int i = 2; i <= N; ++i)
        f[i] = (4ll * (i - 1) * f[i - 1] + 8ll * f[i - 2]) % MOD * inv[i] % MOD * fact[i - 1] % MOD;
    int T, n, k;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        std::cout << solve(n, k) << std::endl;
    }
    return 0;
}