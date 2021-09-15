// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long d(int x)
{
    int l = 1;
    long long res = 0;
    while (l <= x)
    {
        long long r = x / (x / l);
        res += x / l * (l + r) * (r - l + 1) / 2;
        l = r + 1;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int l, r;
    std::cin >> l >> r;
    std::cout << d(r) - d(l - 1) << std::endl;
    return 0;
}