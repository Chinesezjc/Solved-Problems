// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
signed main()
{
    std::ios::sync_with_stdio(false);
    // std::cin >> n;
    std::cout << std::fixed << std::setprecision(200);
    float x = 1.0f / (1llu << 32) / (1llu << 32) / (1llu << 32) / (1llu << 32) / (1llu << 23);
    double y = 1.0f / (1llu << 32) / (1llu << 32) / (1llu << 32) / (1llu << 32) / (1llu << 23) * (1llu << 32);
    std::cout << x << std::endl
              << y << std::endl;
    x *= (1llu << 32);
    y *= (1llu << 32);
    std::cout << x << std::endl
              << y << std::endl;
    return 0;
}