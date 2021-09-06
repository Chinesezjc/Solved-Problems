// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int dp[305], n, k;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    dp[0] = 1;
    for (int i = 1, x; i <= n; ++i)
    {
        std::cin >> x;
        for (int j = k; j; --j)
            dp[j] = (dp[j] + 1ll * dp[j - 1] * x) % MOD;
    }
    std::cout << dp[k] << std::endl;
    return 0;
}