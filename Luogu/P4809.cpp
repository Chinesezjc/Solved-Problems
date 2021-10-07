// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int Lines, Columns, n, m, p, q, Lfa[100005], Cfa[100005];
long long ans;
enum TYPE
{
    LINE,
    COLUMN
};
struct edge
{
    int v, x, y;
    TYPE t;
} e[200005];
int find(int *fa, int now) { return fa[now] == now ? now : fa[now] = find(fa, fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> p >> q;
    Lines = n;
    Columns = m;
    for (int i = 0; i != p; ++i)
    {
        std::cin >> e[i].x >> e[i].y >> e[i].v;
        e[i].t = COLUMN;
        ans += 1ll * n * e[i].v;
    }
    for (int i = p; i != p + q; ++i)
    {
        std::cin >> e[i].x >> e[i].y >> e[i].v;
        e[i].t = LINE;
        ans += 1ll * m * e[i].v;
    }
    for (int i = 1; i <= n; ++i)
        Lfa[i] = i;
    for (int i = 1; i <= m; ++i)
        Cfa[i] = i;
    std::sort(e, e + p + q, [&](const auto &A, const auto &B)
              { return A.v < B.v; });
    for (int i = 0; i != p + q; ++i)
    {
        if (e[i].t == LINE && find(Lfa, e[i].x) != find(Lfa, e[i].y))
        {
            ans -= 1ll * Columns * e[i].v;
            Lfa[find(Lfa, e[i].x)] = find(Lfa, e[i].y);
            --Lines;
        }
        if (e[i].t == COLUMN && find(Cfa, e[i].x) != find(Cfa, e[i].y))
        {
            ans -= 1ll * Lines * e[i].v;
            Cfa[find(Cfa, e[i].x)] = find(Cfa, e[i].y);
            --Columns;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}