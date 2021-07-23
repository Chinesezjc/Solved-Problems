// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m, v[100005], depth[100005], fa[20][100005], f[2][2][20][100005], g[2][100005];
std::string type;
std::vector<int> son[100005];
void dfs(int now)
{
    g[1][now] = v[now];
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[0][now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        g[0][now] += g[1][son[now][i]];
        g[1][now] += std::min(g[0][son[now][i]], g[1][son[now][i]]);
    }
}
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
    {
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
        f[0][0][i][now] = std::min(f[0][0][i - 1][now] + f[0][0][i - 1][fa[i - 1][now]],
                                   f[0][1][i - 1][now] + f[1][0][i - 1][fa[i - 1][now]]);
        f[0][1][i][now] = std::min(f[0][0][i - 1][now] + f[0][1][i - 1][fa[i - 1][now]],
                                   f[0][1][i - 1][now] + f[1][1][i - 1][fa[i - 1][now]]);
        f[1][0][i][now] = std::min(f[1][0][i - 1][now] + f[0][0][i - 1][fa[i - 1][now]],
                                   f[1][1][i - 1][now] + f[1][0][i - 1][fa[i - 1][now]]);
        f[1][1][i][now] = std::min(f[1][0][i - 1][now] + f[0][1][i - 1][fa[i - 1][now]],
                                   f[1][1][i - 1][now] + f[1][1][i - 1][fa[i - 1][now]]);
    }
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        f[0][0][0][son[now][i]] = INF;
        f[1][0][0][son[now][i]] = g[0][now] - g[0][son[now][i]];
        f[0][1][0][son[now][i]] = g[1][now] - std::min(g[0][son[now][i]], g[1][son[now][i]]);
        f[1][1][0][son[now][i]] = g[1][now] - std::min(g[0][son[now][i]], g[1][son[now][i]]);
        init(son[now][i]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> type;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1);
    init(1);
    for (int i = 1; i <= m; ++i)
    {
    }
    return 0;
}