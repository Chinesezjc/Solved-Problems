// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::cin >> ans;
    for (int i = 2, x; i <= n; ++i)
        std::cin >> x, ans = std::__gcd(ans, x);
    std::cout << std::abs(ans) << std::endl;
    return 0;
}