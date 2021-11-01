// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, sum[1 << 18 | 1];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    if (k >= 1 << n)
        return std::cout << -1 << std::endl, 0;
    if (n == 1)
    {
        if (k == 0)
            std::cout << "1 1 0 0" << std::endl;
        else
            std::cout << -1 << std::endl;
        return 0;
    }
    for (int i = 0; i != 1 << n; ++i)
        if (i != k)
            std::cout << i << ' ';
    std::cout << k << ' ';
    for (int i = 1 << n; i--;)
        if (i != k)
            std::cout << i << ' ';
    std::cout << k << std::endl;
    return 0;
}