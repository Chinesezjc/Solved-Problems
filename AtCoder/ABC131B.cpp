// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, ans, v = INT_MAX;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    ans = (k + k + n - 1) * n / 2;
    for (int i = 0; i != n; ++i)
        if (std::abs(v) > std::abs(k + i))
            v = k + i;
    std::cout << ans - v << std::endl;
    return 0;
}