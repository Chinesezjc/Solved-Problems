// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n = 300;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << std::endl;
    for (int i = 0; i != n; ++i)
    {
        int l = 1, r = Rand() % 1000000000 + 1;
        if (l > r)
            std::swap(l, r);
        std::cout << l << ' ' << r << std::endl;
    }
    return 0;
}