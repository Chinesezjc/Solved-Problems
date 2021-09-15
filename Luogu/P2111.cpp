// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::bitset<10000> tmp;
int n, a, q, x;
double ans, dp[55][55];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> a >> q >> tmp;
    x = tmp.count();
    if (n > 50)
        return std::cout << "1.000" << std::endl, 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        double ac = (i <= x ? a : 100 - a) / 100.0, wa = 1 - ac;
        dp[i][0] = dp[i - 1][0] * wa;
        for (int j = 1; j <= i; ++j)
            dp[i][j] = dp[i - 1][j] * wa + dp[i - 1][j - 1] * ac;
    }
    for (int i = q; i <= n; ++i)
        ans += dp[n][i];
    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;
    return 0;
}