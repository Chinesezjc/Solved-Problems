// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, fa[10005], v[10005], ans;
struct edge
{
    int x, y, v;
    friend bool operator<(const edge &A, const edge &B) { return A.v < B.v; }
} e[100005];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i], fa[i] = i;
    ans = *std::min_element(v + 1, v + 1 + n);
    for (int i = 1; i <= m; ++i)
        std::cin >> e[i].x >> e[i].y >> e[i].v, e[i].v = e[i].v * 2 + v[e[i].x] + v[e[i].y];
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; ++i)
        if (find(e[i].x) != find(e[i].y))
            fa[find(e[i].x)] = find(e[i].y), ans += e[i].v;
    std::cout << ans << std::endl;
    return 0;
}