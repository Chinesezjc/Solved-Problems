// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint998244353 mint;
int a, b, n, pre[5005], c[10005];
mint dp[5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b;
    n = a + b;
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = n, j = 0, k = 0, tot = 0; i; --i)
    {
        if (c[i] == 1)
            ++k, ++tot;
        else
            --k, ++j;
        k = std::min(k, 0);
        if (k >= 0)
            pre[j] = tot;
        else
            pre[j] = pre[j - 1] + 1;
    }
    dp[0] = 1;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (j < b)
                dp[j + 1] += dp[j];
            if (pre[j] < i)
                dp[j] = 0;
        }
    }
    std::cout << dp[b].val() << std::endl;
    return 0;
}