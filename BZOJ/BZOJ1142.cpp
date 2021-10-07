// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, a[1005][1005], b[1005][1005];
std::vector<std::vector<int>> la, lb, ca, cb;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> a[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> b[i][j];
        for (int i = 1; i <= n; ++i)
        {
            la.push_back({});
            for (int j = 1; j <= m; ++j)
                la.back().push_back(a[i][j]);
            std::sort(la.back().begin(), la.back().end());
        }
        std::sort(la.begin(), la.end());
        for (int i = 1; i <= m; ++i)
        {
            ca.push_back({});
            for (int j = 1; j <= n; ++j)
                ca.back().push_back(a[j][i]);
            std::sort(ca.back().begin(), ca.back().end());
        }
        std::sort(ca.begin(), ca.end());
        for (int i = 1; i <= n; ++i)
        {
            lb.push_back({});
            for (int j = 1; j <= m; ++j)
                lb.back().push_back(b[i][j]);
            std::sort(lb.back().begin(), lb.back().end());
        }
        std::sort(lb.begin(), lb.end());
        for (int i = 1; i <= m; ++i)
        {
            cb.push_back({});
            for (int j = 1; j <= n; ++j)
                cb.back().push_back(b[j][i]);
            std::sort(cb.back().begin(), cb.back().end());
        }
        std::sort(cb.begin(), cb.end());
        std::cout << (la == lb && ca == cb ? "TAK" : "NIE") << std::endl;
        la.clear();
        ca.clear();
        lb.clear();
        cb.clear();
    }
    return 0;
}