// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long pow10[20], p[20], n, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    pow10[0] = 1;
    for (int i = 1; i <= 18; ++i)
        pow10[i] = pow10[i - 1] * 10;
    for (int i = 1; i <= 18; ++i)
        p[i] = p[i - 1] + pow10[i - 1];
    std::cin >> n;
    ++n;
    for (int i = 1; p[i] < n; ++i)
        for (int j = 0; p[i] * pow10[j] < n; ++j)
            ans += (std::min(n, p[i] * pow10[j] + pow10[j]) - (p[i] * pow10[j]));
    std::cout << ans << std::endl;
    return 0;
}