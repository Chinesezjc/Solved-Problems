// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int w, h, x, y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> w >> h >> x >> y;
    std::cout << std::fixed << std::setprecision(2) << (1ll * w * h) / 2.0 << ' ' << (x * 2 == w && y * 2 == h) << std::endl;
    return 0;
}