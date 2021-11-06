// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int xx[] = {0, 1, 0, -1};
const int yy[] = {1, 0, -1, 0};
const char cc[] = {'R', 'D', 'L', 'U'};
const int n = 2000, m = 2000;
char c[2005][2005];
void dfs(int x, int y, int s)
{
    if (c[x + xx[s]][y + yy[s]] == '?')
    {
        c[x][y] = cc[s];
        dfs(x + xx[s], y + yy[s], s);
    }
    else
    {
        s = (s + 1) % 4;
        c[x][y] = cc[s];
        if (c[x + xx[s]][y + yy[s]] == '?')
            dfs(x + xx[s], y + yy[s], s);
    }
}
signed main()
{
    freopen("data.in", "w", stdout);
    std::ios::sync_with_stdio(false);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            c[i][j] = '?';
    dfs(1, 1, 0);
    std::cout << 1 << std::endl;
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= n; ++i, std::cout << std::endl)
        for (int j = 1; j <= m; ++j)
            std::cout << c[i][j];
    return 0;
}