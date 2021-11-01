// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[100005], app[100005], cnt;
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    --n;
    for (int i = 0; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        std::vector<int> A, B;
        long long now = 0;
        for (int j = 0; i * j <= n; ++j)
        {
            A.push_back(i * j);
            B.push_back(n - i * j);
            cnt += ++app[A.back()] == 2;
            cnt += ++app[B.back()] == 2;
            now += a[A.back()] + a[B.back()];
        }
        while (!A.empty() && !B.empty())
        {
            cnt -= app[A.back()]-- == 2;
            cnt -= app[B.back()]-- == 2;
            now -= a[A.back()] + a[B.back()];
            if (!cnt)
                ans = std::max(ans, now);
            A.pop_back();
            B.pop_back();
        }
    }
    std::cout << ans << std::endl;
    return 0;
}