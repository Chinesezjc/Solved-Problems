// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[500005], ans, dp[500005], cnt;
std::vector<int> mus;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    mus.push_back(0);
    mus.push_back(n + 1);
    a[n + 1] = INT_MAX;
    for (int i = 0, x; i != k; ++i)
        std::cin >> x, mus.push_back(x);
    std::sort(mus.begin(), mus.end());
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (std::size_t i = 1; i != mus.size(); ++i)
        if (a[mus[i - 1]] >= a[mus[i]])
            return std::cout << "impossible" << std::endl, 0;
    ans = k;
    for (std::size_t i = 1; i != mus.size(); ++i)
    {
        cnt = 0;
        for (int j = mus[i - 1] + 1; j != mus[i]; ++j)
            if (a[j] < a[mus[i]] && a[j] > a[mus[i - 1]])
            {
                if (dp[cnt] < a[j])
                    dp[++cnt] = a[j];
                else
                    dp[std::lower_bound(dp + 1, dp + 1 + cnt, a[j]) - dp] = a[j];
            }
        ans += cnt;
    }
    std::cout << ans << std::endl;
    return 0;
}