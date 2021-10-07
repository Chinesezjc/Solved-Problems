// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
signed main()
{
    std::ios::sync_with_stdio(false);
    double x = 0, y;
    for (long long i = 1;; ++i)
    {
        y = x + 1.0 / i;
        if (x == y)
            std::cout << std::fixed << std::setprecision(10) << y << std::endl, exit(0);
        else
            x = y;
    }
    return 0;
}