// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
std::vector<int> a;
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    int T = 10000;
    while (T--)
    {
        n = Rand() % 10 + 1;
        std::cout << n << std::endl;
        a.clear();
        for (int i = 1; i <= n * 2; ++i)
            a.push_back(i);
        std::random_shuffle(a.begin(), a.end());
        for (int i = 0; i != (int)a.size(); ++i)
            std::cout << a[i] << " \n"[i + 1 == a.size()];
        std::random_shuffle(a.begin(), a.end());
        for (int i = 0; i != (int)a.size(); ++i)
            std::cout << a[i] << " \n"[i + 1 == a.size()];
    }
    return 0;
}