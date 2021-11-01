// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, fa[200005], siz[200005];
long long ans;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= 200000; ++i)
        fa[i] = i;
    for (int i = 1, x, y; i <= n; ++i)
    {
        std::cin >> x >> y;
        fa[find(x)] = find(y + 100000);
    }
    ans = -n;
    for (int i = 1; i <= 100000; ++i)
        ++siz[find(i)];
    for (int i = 1; i <= 100000; ++i)
        ans += siz[find(i + 100000)];
    std::cout << ans << std::endl;
    return 0;
}