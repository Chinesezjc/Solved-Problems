// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct edge
{
    int x, y, v;
};
std::vector<edge> edges;
int n, fa[105], ans;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1, x; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            std::cin >> x;
            if (j < i)
                edges.push_back({i, j, x});
        }
    std::sort(edges.begin(), edges.end(), [&](const edge &A, const edge &B)
              { return A.v < B.v; });
    for (auto i : edges)
        if (find(i.x) != find(i.y))
            fa[find(i.x)] = find(i.y), ans += i.v;
    std::cout << ans << std::endl;
    return 0;
}