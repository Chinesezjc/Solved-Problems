// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, t, ans;
std::pair<int, int> p[25005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i].first >> p[i].second, ++p[i].second;
    std::sort(p + 1, p + 1 + n);
    int i = 1, max = 1;
    while (max <= t)
    {
        int old = max;
        while (i <= n && p[i].first <= old)
            max = std::max(max, p[i++].second);
        if (old == max)
            return std::cout << -1 << std::endl, 0;
        ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}