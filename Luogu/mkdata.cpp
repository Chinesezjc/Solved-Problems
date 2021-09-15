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
int n = 5, m = 7, fa[55];
std::set<std::pair<int, int>> set;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        do
            a = Rand() % n + 1, b = Rand() % n + 1;
        while (find(a) == find(b));
        fa[find(a)] = find(b);
        set.insert({a, b});
        set.insert({b, a});
        std::cout << a << ' ' << b << std::endl;
    }
    for (int i = n; i <= m; ++i)
    {
        int a, b;
        do
            a = Rand() % n + 1, b = Rand() % n + 1;
        while (set.count({a, b}) || a == b);
        set.insert({a, b});
        set.insert({b, a});
        std::cout << a << ' ' << b << std::endl;
    }
    return 0;
}