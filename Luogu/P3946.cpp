// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, s, t, g, q, dis[100005], l[100005];
std::priority_queue<std::pair<int, int>> que;
std::vector<std::pair<int, int>> to[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s >> t >> g >> q;
    for (int i = 1, x, y; i <= n; ++i)
    {
        std::cin >> x >> y;
        l[i] = q ? (y - x) / q : g;
    }
    for (int i = 1, x, y, z; i <= m; ++i)
    {
        std::cin >> x >> y >> z;
        to[x].push_back({z, y});
        to[y].push_back({z, x});
    }
    std::fill(dis + 1, dis + 1 + n, g + 1);
    que.push({-(dis[s] = 0), s});
    while (!que.empty())
    {
        std::pair<int, int> now = que.top();
        que.pop();
        if (now.first + dis[now.second] || dis[now.second] > l[now.second])
            continue;
        for (auto i : to[now.second])
            if (dis[i.second] > dis[now.second] + i.first)
                que.push({-(dis[i.second] = dis[now.second] + i.first), i.second});
    }
    if (dis[t] > g)
        std::cout << "wtnap wa kotori no oyatsu desu!" << std::endl;
    else
        std::cout << dis[t] << std::endl;
    return 0;
}