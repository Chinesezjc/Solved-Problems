// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int ans, n, m, a[45][45];
const std::pair<int, int> d[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void work(int x, int y)
{
    ans += a[x][y];
    a[x][y] = 0;
    if (x == n && y == m)
        return;
    auto fun = [&](const std::pair<int, int> &t)
    { return a[x + t.first][y + t.second]; };
    int t = std::max_element(d, d + 4, [&](const std::pair<int, int> &X, const std::pair<int, int> &Y)
                             { return fun(X) < fun(Y); }) -
            d;
    work(x + d[t].first, y + d[t].second);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j];
    work(1, 1);
    std::cout << ans << std::endl;
    return 0;
}