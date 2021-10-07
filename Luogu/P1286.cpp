// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, a[50], b[10];
bool vis[50];
bool check()
{
    for (int i = 0; i != n; ++i)
        if (a[i] < 0)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    while (std::cin >> n)
    {
        m = n * (n - 1) / 2;
        for (int i = 0; i != m; ++i)
            std::cin >> a[i];
        std::sort(a, a + m);
        for (int i = 2; i != m; ++i)
        {
            std::fill(vis, vis + m + 1, false);
            if ((a[0] + a[1] + a[i]) & 1)
                continue;
            b[0] = (a[0] + a[1] + a[i]) / 2 - a[i];
            b[1] = a[0] - b[0];
            b[2] = a[1] - b[0];
            vis[0] = true;
            vis[1] = true;
            vis[i] = true;
            int cnt = 3;
            for (int j = 0; j != m && cnt != n; ++j)
                if (!vis[j])
                {
                    b[cnt] = a[j] - b[0];
                    vis[j] = true;
                    for (int k = 1; k != cnt; ++k)
                        for (int l = 0; l <= m; ++l)
                            if (l == m || (b[k] + b[cnt] == a[l] && !vis[l]))
                            {
                                vis[l] = true;
                                break;
                            }
                    ++cnt;
                }
            if (vis[m] || std::count(vis, vis + m, false) || cnt != n || !check())
                continue;
            for (int j = 0; j != n; ++j)
                std::cout << b[j] << " \n"[j + 1 == n];
            goto nextcase;
        }
        std::cout << "Impossible" << std::endl;
    nextcase:;
    }
    return 0;
}