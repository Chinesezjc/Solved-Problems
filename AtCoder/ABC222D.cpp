// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint998244353 mint;
int n, a[3005], b[3005];
mint dp[3005][3005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    std::fill(dp[0], dp[0] + 3005, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = a[i]; j <= b[i]; ++j)
        {
            dp[i][j] = (j ? dp[i][j - 1] : 0) + dp[i - 1][j];
        }
        std::fill(dp[i] + b[i] + 1, dp[i] + 3005, dp[i][b[i]]);
    }
    std::cout << dp[n][3000].val() << std::endl;
    return 0;
}