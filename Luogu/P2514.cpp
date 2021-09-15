// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int m, b, n, a[50005], h[55], C[50005][55], ans1, ans2;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> b >> h[0] >> n;
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> h[i];
    for (int i = 0; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> C[j][i];
    ans1 = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int v = h[0] + h[i], l = b;
        std::priority_queue<std::pair<int, int>> que;
        for (int j = 1; j <= m; ++j)
            que.push({C[j][i] - C[j][0], a[j]}), v += C[j][i] * a[j];
        while (l)
        {
            std::pair<int, int> now = que.top();
            que.pop();
            v -= std::min(l, now.second) * now.first;
            l -= std::min(l, now.second);
        }
        if (ans1 > v)
            ans1 = v, ans2 = i;
    }
    std::cout << ans2 << std::endl
              << ans1 << std::endl;
    return 0;
}