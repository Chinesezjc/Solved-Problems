// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int to[10], n, m, st, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0, k; i != m; ++i)
    {
        std::cin >> k;
        for (int j = 0, l; j != k; ++j)
            std::cin >> l, to[--l] |= 1 << i;
    }
    for (int i = 0, x; i != m; ++i)
        std::cin >> x, st |= (x & 1) << i;
    for (int i = 0; i != 1 << n; ++i)
    {
        int now = st;
        for (int j = 0; j != n; ++j)
            if (i >> j & 1)
                now ^= to[j];
        ans += now == 0;
    }
    std::cout << ans << std::endl;
    return 0;
}