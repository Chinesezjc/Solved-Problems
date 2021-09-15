// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long pre[1000005], suf[1000005], a[1000005], ans = LLONG_MIN;
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    pre[0] = LLONG_MIN;
    suf[n + 1] = LLONG_MIN;
    for (int i = 1; i <= n; ++i)
        pre[i] = std::max(pre[i - 1], 0ll) + a[i];
    for (int i = 1; i <= n; ++i)
        pre[i] = std::max(pre[i - 1], pre[i]);
    for (int i = n; i; --i)
        suf[i] = std::max(suf[i + 1], 0ll) + a[i];
    for (int i = n; i; --i)
        suf[i] = std::max(suf[i + 1], suf[i]);
    for (int i = 2; i < n; ++i)
        ans = std::max(ans, pre[i - 1] + suf[i + 1]);
    std::cout << ans << std::endl;
    return 0;
}