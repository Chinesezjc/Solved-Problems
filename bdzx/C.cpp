// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, fa[200005];
long long ans, b[200005], p[200005], w[200005];
std::vector<int> to[200005];
void dfs(int now)
{
    for (auto i : to[now])
    {
        if (fa[now] == i)
            continue;
        fa[i] = now;
        dfs(i);
        long long tmp = std::min(std::min(b[now], w[now]), std::min(b[i], w[i]));
        w[now] -= tmp;
        w[i] -= tmp;
        ans -= tmp;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1, x, y; i != n; ++i)
        {
            std::cin >> x >> y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i] >> p[i];
            ans += b[i];
            w[i] = b[i] * p[i];
        }
        dfs(1);
        std::cout << ans << std::endl;
        for (int i = 1; i <= n; ++i)
            to[i].clear();
    }
    return 0;
}