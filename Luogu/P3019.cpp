// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, depth[1005], fa[1005];
std::vector<int> son[1005];
void init(int now)
{
    for (auto i : son[now])
        depth[i] = depth[now] + 1, init(i);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[i], son[fa[i]].push_back(i);
    init(1);
    for (int i = 1, x, y; i <= m; ++i)
    {
        std::cin >> x >> y;
        while (depth[x] > depth[y])
            x = fa[x];
        while (depth[x] < depth[y])
            y = fa[y];
        while (x != y)
            x = fa[x], y = fa[y];
        std::cout << x << std::endl;
    }
    return 0;
}