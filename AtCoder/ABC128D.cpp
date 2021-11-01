// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[55], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 0; i <= std::min(n, k); ++i)
        for (int j = 0; i + j <= std::min(n, k); ++j)
        {
            int left = k - i - j, now = 0;
            std::priority_queue<int> que;
            for (int k = 1; k <= i; ++k)
                que.push(-a[k]), now += a[k];
            for (int k = 1; k <= j; ++k)
                que.push(-a[n - k + 1]), now += a[n - k + 1];
            while (left-- && !que.empty() && que.top() > 0)
                now += que.top(), que.pop();
            ans = std::max(ans, now);
        }
    std::cout << ans << std::endl;
    return 0;
}