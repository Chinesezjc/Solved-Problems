// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long n, a[100005], b[100005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x; i <= n; ++i)
        std::cin >> a[i] >> x, a[i] -= x, b[i] = b[i - 1] + a[i];
    std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i)
        ans += std::abs(b[i] - b[(n + 1) / 2]);
    std::cout << ans << std::endl;
    return 0;
}