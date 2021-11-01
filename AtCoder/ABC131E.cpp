// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, ans;
bool con[105][105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    if (k > (n - 1) * (n - 2) / 2)
        return std::cout << "-1" << std::endl, 0;
    k = (n - 1) * (n - 2) / 2 - k;
    for (int i = 1; i < n; ++i)
    {
        con[i][n] = true;
        for (int j = i + 1; j < n; ++j)
            if (k)
                con[i][j] = true, --k;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (con[i][j])
                ++ans;
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (con[i][j])
                std::cout << i << ' ' << j << std::endl;
    return 0;
}