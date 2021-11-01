// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, d[105], x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        std::cin >> d[i], d[i] += d[i - 1];
    std::cout << std::upper_bound(d, d + 1 + n, x) - d << std::endl;
    return 0;
}