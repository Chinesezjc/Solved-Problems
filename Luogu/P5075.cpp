// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned dp[2][10005], f[10005], m, p, a, o, s, u, ans;
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> p >> a >> o >> s >> u;
    f[0] = 1;
    for (unsigned i = 1; i <= m; ++i)
        f[i] = (o * i * i + s * i + u) % p;
    dp[now][0] = 1;
    for (unsigned i = 1; i <= std::min(a, m); ++i)
    {
        std::swap(now, lst);
        for (unsigned j = i - 1,
                      A = dp[lst][j],
                      B = dp[lst][j] * j % p,
                      C = dp[lst][j] * j % p * j % p;
             ++j <= m; A = (A + dp[lst][j]) % p,
                      B = (B + dp[lst][j] * j) % p,
                      C = (C + dp[lst][j] * j % p * j % p) % p)
            dp[now][j] = (A * (o * j * j % p + s * j + u) +
                          B * ((p - 2) * o * j + (p - 1) * s) +
                          C * o) %
                         p;
        ans = (ans + dp[now][m]) % p;
    }
    std::cout << ans << std::endl;
    return 0;
}