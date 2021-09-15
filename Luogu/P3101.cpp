// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, t, a[505][505], b[250005], c[250005], fa[250005], siz[250005];
long long ans;
std::list<int> l[250005];
struct node
{
    int s, e, v;
};
std::vector<node> e;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> t;
    if (t <= 1)
        return std::cout << 0 << std::endl, 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            std::cin >> a[i][j];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            std::cin >> b[i * m + j];
    for (int i = 0; i != n; ++i)
        for (int j = 1; j != m; ++j)
            e.push_back({i * m + (j - 1), i * m + j, std::abs(a[i][j] - a[i][j - 1])});
    for (int i = 1; i != n; ++i)
        for (int j = 0; j != m; ++j)
            e.push_back({(i - 1) * m + j, i * m + j, std::abs(a[i][j] - a[i - 1][j])});
    std::sort(e.begin(), e.end(), [](const node &A, const node &B)
              { return A.v < B.v; });
    std::iota(fa, fa + n * m, 0);
    std::fill(siz, siz + n * m, 1);
    for (int i = 0; i != n * m; ++i)
        l[i].push_back(i);
    for (auto i : e)
    {
        i.s = find(i.s);
        i.e = find(i.e);
        if (i.s != i.e)
        {
            fa[i.e] = i.s;
            siz[i.s] += siz[i.e];
            l[i.s].splice(l[i.s].end(), l[i.e]);
            if (siz[i.s] >= t)
            {
                for (auto j : l[i.s])
                    c[j] = i.v;
                l[i.s].clear();
            }
        }
    }
    for (int i = 0; i != n * m; ++i)
        ans += b[i] * c[i];
    std::cout << ans << std::endl;
    return 0;
}