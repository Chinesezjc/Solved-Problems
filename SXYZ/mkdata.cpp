// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 Rand(seed);
int n = 5, m = 5;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        int opt = Rand() % 2 + 1, l = Rand() % m + 1, r = Rand() % m + 1;
        if (l > r)
            std::swap(l, r);
        std::cout << opt << ' ' << l << ' ' << r << std::endl;
    }
    return 0;
}