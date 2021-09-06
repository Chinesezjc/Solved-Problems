// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, a[200005], sum[200005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        sum[i] = (sum[i - 1] * 2ll + a[i]) % MOD;
    for (int i = 1; i <= n; ++i)
        ans = (ans + 1ll * sum[i - 1] * a[i] + 1ll * a[i] * a[i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}