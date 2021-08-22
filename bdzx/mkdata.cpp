// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
const int MOD = 1000000007;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << 1000 << std::endl;
    for (int i = 1; i <= 1000; ++i)
    {
        std::cout << 10 << ' ' << Rand() % MOD << std::endl;
        for (int j = 0; j != 10; ++j)
            std::cout << char(Rand() & 1 ? '+' : '*') << ' ' << Rand() % MOD << std::endl;
    }
    return 0;
}