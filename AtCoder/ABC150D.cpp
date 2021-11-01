// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
long long lcm = 1, a[100005];
bool good[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> a[i];
        a[i] >>= 1;
        lcm = lcm / std::__gcd(lcm, a[i]) * a[i];
        if (lcm > m)
            std::cout << 0 << std::endl, exit(0);
    }
    for (int i = 0; i != n; ++i)
        if (lcm % (a[i] << 1) == 0)
            std::cout << 0 << std::endl, exit(0);
    std::cout << 1 + (m - lcm) / (lcm * 2) << std::endl;
    return 0;
}