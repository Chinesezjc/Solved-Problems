// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long sum[100005], k, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> sum[i], sum[i] += sum[i - 1];
    std::sort(sum, sum + n + 1);
    for (int i = 1; i <= n; ++i)
        if (sum[i] >= k)
            ans += std::upper_bound(sum, sum + i + 1, sum[i] - k) - sum;
    std::cout << ans << std::endl;
    return 0;
}