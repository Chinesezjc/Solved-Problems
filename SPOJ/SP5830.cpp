// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int T, fact[20005], ifact[20005], n, k, a[25], dp[2][20005];
bool now = true, lst = false;
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
int C(int n, int m) { return 0 <= m && m <= n ? 1ll * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (long long i = 1; i <= 20000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[20000] = power(fact[20000], MOD - 2);
    for (long long i = 20000; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= k; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= k; ++i)
            a[i] = a[i + 1] - a[i];
        ++a[1];
        dp[now][n] = 1;
        std::fill(dp[now], dp[now] + n, 0);
        for (int i = 1; i < k; n -= a[i++])
        {
            std::swap(now, lst);
            std::fill(dp[now], dp[now] + n - a[i] + 1, 0);
            for (int j = 0; j <= n - a[i]; ++j)
                for (int l = 0; l <= n; ++l)
                    dp[now][j] = (dp[now][j] + 1ll * dp[lst][l] * C(l - n + a[i] + j - 1, a[i] - 1)) % MOD;
        }
        std::cout << dp[now][0] << std::endl;
    }
    return 0;
}