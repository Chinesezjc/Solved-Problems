// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
constexpr int MOD = 1000000007;
int n, k, dp[1 << 16], a[16], sum[1 << 16], ans;
void add(int &A, int B) { A = (A + B) % MOD; }
constexpr int power(int A, int B)
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
constexpr int inv1000 = power(1000, MOD - 2);
signed main()
{
    freopen("generator.in", "r", stdin);
    freopen("generator.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], sum[1 << i] = a[i];
    for (int i = 1; i != 1 << n; ++i)
        sum[i] = sum[i & (i - 1)] + sum[i & -i];
    dp[0] = 1;
    for (int i = 0; i != 1 << n; ++i)
        for (int j = 0; j != n; ++j)
            if (~i >> j & 1)
                add(dp[i | 1 << j], 1ll * dp[i] * a[j] % MOD * power(sum[((1 << n) - 1) ^ i], MOD - 2) % MOD);
    for (int i = 0; i != 1 << n; ++i)
        if (__builtin_popcount(i) == k && (i & 1))
            add(ans, dp[i]);
    std::cout << ans << std::endl;
    return 0;
}