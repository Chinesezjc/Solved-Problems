// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const int MOD = 1000000007;
int T, n, m, ans, dp[3005][3005], fact[3005];
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = dp[0][0] = 1;
    for (int i = 1; i <= 3000; ++i)
        for (int j = 1; j <= 3000; ++j)
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % MOD;
    for (int i = 1; i <= 3000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans = (ans + dp[n][i] * dp[m][i - 1] % MOD * fact[i] % MOD * fact[i - 1]) % MOD;
            ans = (ans + dp[n][i] * dp[m][i] * 2 % MOD * fact[i] % MOD * fact[i]) % MOD;
            ans = (ans + dp[n][i] * dp[m][i + 1] % MOD * fact[i] % MOD * fact[i + 1]) % MOD;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}