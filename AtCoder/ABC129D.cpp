// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int l[2005][2005], r[2005][2005], u[2005][2005], d[2005][2005], n, m, ans;
bool good[2005][2005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            static char c;
            std::cin >> c;
            good[i][j] = c == '.';
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (good[i][j])
                u[i][j] = u[i - 1][j] + 1,
                l[i][j] = l[i][j - 1] + 1;
    for (int i = n; i; --i)
        for (int j = m; j; --j)
            if (good[i][j])
                d[i][j] = d[i + 1][j] + 1,
                r[i][j] = r[i][j + 1] + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (good[i][j])
                ans = std::max(ans, l[i][j] + u[i][j] + r[i][j] + d[i][j] - 3);
    std::cout << ans << std::endl;
    return 0;
}