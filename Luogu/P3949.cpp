// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::cin >> q;
    for (int i = 0; i != q; ++i)
    {
        long long x;
        std::cin >> x;
        std::cout << (__builtin_popcountll(x - 1) & 1 ? 'Z' : 'X') << std::endl;
    }
    return 0;
}