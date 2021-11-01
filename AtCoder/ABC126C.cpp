// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k;
double ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int tim = 0;
        double v = 1;
        while (i << tim < k)
            ++tim, v *= 0.5;
        ans += 1.0l / n * v;
    }
    std::cout << std::fixed << std::setprecision(20) << ans << std::endl;
    return 0;
}