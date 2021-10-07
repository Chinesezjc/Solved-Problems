// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint998244353 mint;
typedef atcoder::static_modint<10> Int;
int n;
Int a[100005];
mint dp[100005][10];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0, x; i != n; ++i)
        std::cin >> x, a[i] = x;
    dp[1][a[0].val()] = 1;
    for (int i = 1; i != n; ++i)
        for (int j = 0; j != 10; ++j)
        {
            dp[i + 1][(j + a[i]).val()] += dp[i][j];
            dp[i + 1][(j * a[i]).val()] += dp[i][j];
        }
    for (int i = 0; i != 10; ++i)
        std::cout << dp[n][i].val() << std::endl;
    return 0;
}