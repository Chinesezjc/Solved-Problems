// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
int n, m, a[2005], b[2005];
typedef atcoder::modint1000000007 mint;
mint dp[2005][2005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
        std::cin >> b[i];
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            if (i)
                dp[i][j] += dp[i - 1][j];
            if (j)
                dp[i][j] += dp[i][j - 1];
            if (i && j && a[i] != b[j])
                dp[i][j] -= dp[i - 1][j - 1];
        }
    std::cout << dp[n][m].val() << std::endl;
    return 0;
}