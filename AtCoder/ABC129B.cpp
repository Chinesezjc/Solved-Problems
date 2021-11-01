// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, sum, a[105], ans = INT_MAX;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], sum += a[i];
    for (int i = 0, s = 0; i <= n; ++i)
    {
        s += a[i];
        ans = std::min(ans, std::abs(sum - s - s));
    }
    std::cout << ans << std::endl;
    return 0;
}