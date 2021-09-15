// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
double dp[10005], p, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> p;
    dp[0] = 1;
    for (int i = 1; i <= 10000; ++i)
        dp[i] = dp[i - 1] * (1 - std::min(p * i, 1.0));
    for (int i = 1; i <= 10000; ++i)
        ans += i * dp[i - 1] * std::min(p * i, 1.0);
    std::cout << std::fixed << std::setprecision(6) << 1.0 / ans << std::endl;
    return 0;
}