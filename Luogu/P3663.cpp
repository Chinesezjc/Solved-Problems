// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int cnt, ans, n, k, r, fa[10005], siz[10005];
bool h[105][105], s[105][105];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> r;
    for (int i = 0; i != n; ++i)
        for (int j = 1; j != n; ++j)
            h[i][j] = true;
    for (int i = 1; i != n; ++i)
        for (int j = 0; j != n; ++j)
            s[i][j] = true;
    for (int i = 0, sx, sy, ex, ey; i != r; ++i)
    {
        std::cin >> sx >> sy >> ex >> ey;
        (sx != ex ? s : h)[std::max(sx, ex) - 1][std::max(sy, ey) - 1] = false;
    }
    for (int i = 0; i != n * n; ++i)
        fa[i] = i;
    for (int i = 0; i != n; ++i)
        for (int j = 1; j != n; ++j)
            if (h[i][j])
                fa[find(i * n + j)] = find(i * n + j - 1);
    for (int i = 1; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (s[i][j])
                fa[find(i * n + j)] = find(i * n + j - n);
    for (int i = 0, x, y; i != k; ++i)
    {
        std::cin >> x >> y;
        ++siz[find(--x * n + --y)];
    }
    for (int i = 0; i != n * n; ++i)
    {
        ans += siz[i] * cnt;
        cnt += siz[i];
    }
    std::cout << ans << std::endl;
    return 0;
}