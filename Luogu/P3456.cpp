// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[1005][1005], min, max, MAX, MIN;
bool vis[1005][1005];
const int xx[] = {0, 1, 0, -1, 1, 1, -1, -1}, yy[] = {1, 0, -1, 0, 1, -1, 1, -1};
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i != 8; ++i)
    {
        int tx = x + xx[i], ty = y + yy[i];
        if (std::min(tx, ty) < 1 || std::max(tx, ty) > n)
            continue;
        min = std::min(min, a[tx][ty]);
        max = std::max(max, a[tx][ty]);
        if (!vis[tx][ty] && a[tx][ty] == a[x][y])
            dfs(tx, ty);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!vis[i][j])
            {
                max = min = a[i][j];
                dfs(i, j);
                MAX += max == a[i][j];
                MIN += min == a[i][j];
            }
    std::cout << MAX << ' ' << MIN << std::endl;
    return 0;
}