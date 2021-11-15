// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 Rand(seed);
int T, n = Rand() % 2 + 3, d[1005];
std::set<std::pair<int, int>> s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << 1 << std::endl;
    while (std::count(d + 1, d + 1 + n, 0) || std::count(d + 1, d + 1 + n, 1))
    {
        int A = Rand() % n + 1, B = Rand() % n + 1;
        if (A > B)
            std::swap(A, B);
        if (s.count({A, B}) || A == B)
            continue;
        ++d[A];
        ++d[B];
        s.insert({A, B});
    }
    std::cout << n << ' ' << s.size() << std::endl;
    for (int i = 2; i <= n; ++i)
        std::cout << Rand() % 1000000000 + 1 << " \n"[i == n];
    for (int i = 2; i <= n; ++i)
        std::cout << Rand() % 1000000000 + 1 << " \n"[i == n];
    for (auto i : s)
        std::cout << i.first << ' ' << i.second << std::endl;
    return 0;
}