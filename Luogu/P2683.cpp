// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, dis[105][105];
int F(int x) { return x == 1000000000 ? -1 : x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            dis[i][j] = dis[j][i] = 1000000000;
    for (int i = 1, opt, u, v, c; i <= m; ++i)
    {
        std::cin >> opt;
        switch (opt)
        {
        case 0:
            std::cin >> u >> v;
            std::cout << F(dis[u][v]) << std::endl;
            break;
        case 1:
            std::cin >> u >> v >> c;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    dis[i][j] = std::min({dis[i][j], dis[i][u] + c + dis[v][j], dis[i][v] + c + dis[u][j]});
            break;
        }
    }
    return 0;
}