// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, x, y, v;
long long dis[100005];
std::vector<std::pair<int, int>> to[100005];
void dfs(int now, int fa)
{
    for (auto i : to[now])
    {
        if (i.first == fa)
            continue;
        dis[i.first] = dis[now] + i.second;
        dfs(i.first, now);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
        std::cin >> x >> y >> v, to[x].push_back({y, v}), to[y].push_back({x, v});
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        std::cout << (dis[i] & 1) << std::endl;
    return 0;
}