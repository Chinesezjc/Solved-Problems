// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k, a[1005], dp1[1005], dp2[1005], cnt;
bool app[25];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::fill(dp1 + 1, dp1 + 1 + n, INT_MAX);
    std::fill(dp2 + 1, dp2 + 1 + n, INT_MAX);
    for (int i = 1; i <= n; ++i)
    {
        std::fill(app + 1, app + 1 + m, false);
        cnt = 0;
        for (int j = i; j >= 1; --j)
        {
            if (!app[a[j]])
                app[a[j]] = true, ++cnt;
            if (cnt <= k)
            {
                dp1[i] = std::min(dp1[i], dp1[j - 1] + 1);
                dp2[i] = std::min(dp2[i], dp2[j - 1] + cnt);
            }
        }
    }
    std::cout << dp1[n] << std::endl
              << dp2[n] << std::endl;
    return 0;
}