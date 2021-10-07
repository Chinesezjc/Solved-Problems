// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[200005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    ans = a[1];
    for (int i = 2; i <= n; ++i)
        ans = std::__gcd(ans, a[i]);
    for (int i = 1; i <= n; ++i)
        if (a[i] >= k && (a[i] - k) % ans == 0)
            return std::cout << "POSSIBLE" << std::endl, 0;
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}