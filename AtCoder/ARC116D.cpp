// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, m, dp[20][5005], C[5005][5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    C[0][0] = 1;
    for (int i = 1; i <= 5000; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    std::cin >> n >> m;
    dp[13][m] = 1;
    for (int i = 12; i >= 0; --i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k << i <= j; k += 2)
                dp[i][j - (k << i)] = (dp[i][j - (k << i)] + 1ll * dp[i + 1][j] * C[n][k]) % MOD;
    std::cout << dp[0][0] << std::endl;
    return 0;
}