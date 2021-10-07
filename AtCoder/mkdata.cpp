// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n = 40, m = 100;
std::set<std::pair<int, int>> s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 0; i != m; ++i)
    {
        int x, y;
        do
            x = Rand() % n + 1, y = Rand() % n + 1;
        while (s.count({x, y}) || x == y);
        std::cout << x << ' ' << y << std::endl;
        s.insert({x, y});
        s.insert({y, x});
    }
    return 0;
}