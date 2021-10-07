// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> son[5005];
int n, in[5005], depth[5005];
long long ans = LLONG_MAX;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> in[i];
        for (int j = 0, x; j != in[i]; ++j)
            std::cin >> x, son[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        std::fill(depth + 1, depth + 1 + n, n * n);
        std::queue<int> que;
        que.push(i);
        depth[i] = 1;
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (auto i : son[now])
                if (depth[i] > depth[now] + 1)
                    depth[i] = depth[now] + 1, que.push(i);
        }
        long long now = 0;
        for (int i = 1; i <= n; ++i)
            now += depth[i];
        ans = std::min(ans, now);
    }
    std::cout << ans << std::endl;
    return 0;
}