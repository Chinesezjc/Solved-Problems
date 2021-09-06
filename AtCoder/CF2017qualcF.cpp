// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint1000000007 mint;
int n, a[405], b[405], pa[405], pb[405], f[405][405];
mint dp[405][405], suf[405][405];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], pa[--a[i]] = i;
    for (int i = 0; i != n; ++i)
        std::cin >> b[i], pb[--b[i]] = i;
    for (int i = n; i--;)
        for (int j = n; j--;)
            f[i][j] = f[i][j + 1] + (i <= pa[b[j]]);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            suf[i][j] = 1;
    for (int i = 1; i <= n / 3; ++i)
    {
        for (int j = 0; j != n; ++j)
            for (int k = 0; k != n; ++k)
                if (pa[b[k]] > j && pb[a[j]] > k)
                    dp[j][k] = suf[j + 1][k + 1] * std::max(f[j + 1][k + 1] - (i - 1) * 3, 0);
        memset(suf, 0, sizeof(suf));
        for (int j = n; j--;)
            for (int k = n; k--;)
                suf[j][k] = suf[j + 1][k] + suf[j][k + 1] - suf[j + 1][k + 1] + dp[j][k];
    }
    mint ans = suf[0][0];
    for (int i = 1; i <= n; ++i)
        if (i % 3)
            ans *= i;
    std::cout << ans.val() << std::endl;
    return 0;
}