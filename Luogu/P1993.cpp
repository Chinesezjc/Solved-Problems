// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<std::pair<int, int>> to[5005];
int dis[5005], n, m, tim[5005], in[5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int opt, a, b, c;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> a >> b >> c;
            to[a].push_back({b, -c});
            break;

        case 2:
            std::cin >> a >> b >> c;
            to[b].push_back({a, +c});
            break;

        case 3:
            std::cin >> a >> b;
            to[a].push_back({b, 0});
            to[b].push_back({a, 0});
            break;
        }
    }
    std::fill(dis + 1, dis + 1 + n, 0);
    std::stack<int> que;
    for (int i = 1; i <= n; ++i)
        que.push(i);
    while (!que.empty())
    {
        int now = que.top();
        que.pop();
        in[now] = false;
        for (auto i : to[now])
            if (dis[i.first] > dis[now] + i.second)
            {
                dis[i.first] = dis[now] + i.second;
                if (!in[i.first])
                {
                    in[i.first] = true;
                    ++tim[i.first];
                    if (tim[i.first] > n)
                        return std::cout << "No" << std::endl, 0;
                    que.push(i.first);
                }
            }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}