// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1024523;
int n, m, dp[2][505][505];
std::string a, b;
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    std::cin >> a >> b;
    dp[now][0][0] = 1;
    for (int i = 0; i != n + m; ++i)
    {
        std::swap(now, lst);
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = std::max(i - n, 0); j <= std::min(i, m); ++j)
            for (int k = std::max(i - n, 0); k <= std::min(i, m); ++k)
            {
                dp[lst][j][k] %= MOD;
                if (i - j != n && i - k != n && a[i - j] == a[i - k])
                    dp[now][j][k] += dp[lst][j][k];
                if (i - j != n && k != m && a[i - j] == b[k])
                    dp[now][j][k + 1] += dp[lst][j][k];
                if (j != m && i - k != n && b[j] == a[i - k])
                    dp[now][j + 1][k] += dp[lst][j][k];
                if (j != m && k != m && b[j] == b[k])
                    dp[now][j + 1][k + 1] += dp[lst][j][k];
            }
    }
    std::cout << dp[now][m][m] % MOD << std::endl;
    return 0;
}