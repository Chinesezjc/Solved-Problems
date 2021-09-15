// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> to[505];
int d[505], cnt[505], ans, n;
std::vector<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int p, m;
        std::cin >> p >> m;
        ++cnt[p];
        for (int j = 0, x; j != m; ++j)
            std::cin >> x, ++d[x], to[p].push_back(x);
    }
    for (int i = 0; i <= 500; ++i)
        if (!d[i])
            que.push_back(i);
    while (!que.empty())
    {
        int now = que.back();
        que.pop_back();
        ans += cnt[now];
        for (auto i : to[now])
            if (!--d[i])
                que.push_back(i);
    }
    std::cout << (ans == n ? "YES" : std::to_string(n - ans)) << std::endl;
    return 0;
}