// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int fa[100005], n, m, ans;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    ans = n;
    for (int i = 1, x, y, z; i <= m; ++i)
    {
        std::cin >> x >> y >> z;
        if (find(x) != find(y))
        {
            --ans;
            fa[find(x)] = find(y);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}