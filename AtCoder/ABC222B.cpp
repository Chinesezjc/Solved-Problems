// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, p, a[100005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> p;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ans += a[i] < p;
    std::cout << ans << std::endl;
    return 0;
}