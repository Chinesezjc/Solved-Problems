// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int T, n, k, dp[105][105], way[105], fact[105], inv[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (long long i = 1; i <= 100; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv[1] = 1;
    for (long long i = 2; i <= 100; ++i)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    dp[1][0] = 1;
    for (int i = 2; i <= 100; ++i)
        for (int j = 0; j <= 100; ++j)
            for (int k = 0, l = 1; i * k <= j; l = 1ll * l * inv[i] % MOD * inv[++k] % MOD)
                dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j - i * k] * l) % MOD;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        std::cout << 1ll * dp[k][n] * fact[n] % MOD << std::endl;
    }
    return 0;
}