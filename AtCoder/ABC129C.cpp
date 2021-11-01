// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
int n, m;
bool bad[100005];
typedef atcoder::modint1000000007 mint;
mint dp[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, x; i <= m; ++i)
        std::cin >> x, bad[x] = true;
    dp[0] = 1;
    dp[1] = !bad[1];
    for (int i = 2; i <= n; ++i)
        if (!bad[i])
            dp[i] = dp[i - 1] + dp[i - 2];
    std::cout << dp[n].val() << std::endl;
    return 0;
}