// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
const int n = 10, m = 20, q = 10;
std::set<std::pair<int, int>> s;
int fa[n + 1];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << ' ' << q << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << Rand() % 10 + 1 << " \n"[i == n], fa[i] = i;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        do
            x = Rand() % n + 1, y = Rand() % n + 1;
        while (x == y || s.count({x, y}) || s.count({y, x}) || find(x) == find(y));
        s.insert({x, y});
        fa[find(x)] = find(y);
        std::cout << x << ' ' << y << ' ' << Rand() % 10 + 1 << std::endl;
    }
    for (int i = n; i <= m; ++i)
    {
        int x, y;
        do
            x = Rand() % n + 1, y = Rand() % n + 1;
        while (x == y || s.count({x, y}) || s.count({y, x}));
        s.insert({x, y});
        std::cout << x << ' ' << y << ' ' << Rand() % 10 + 1 << std::endl;
    }
    for (int i = 1; i <= q; ++i)
        std::cout << Rand() % n + 1 << ' ' << Rand() % 10 + 1 << std::endl;
    return 0;
}