// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m, x[10005], y[10005], v[10005], k[105], siz[10005];
std::vector<int> to[10005], cha;
bool vis[10005], app[10000005], ans[105];
void init_siz(int now, int from)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        int nxt = x[i] ^ y[i] ^ now;
        if (i == from || vis[nxt])
            continue;
        init_siz(nxt, i);
        siz[now] += siz[nxt];
    }
}
int find_root(int now, int from, int tot)
{
    int max = 0;
    for (auto i : to[now])
    {
        int nxt = x[i] ^ y[i] ^ now;
        if (i == from || vis[nxt])
            continue;
        int res = find_root(nxt, i, tot);
        if (res)
            return res;
        max = std::max(max, siz[nxt]);
    }
    return std::max(max, tot - siz[now]) <= tot / 2 ? now : 0;
}
template <class F>
void dfs(int now, int from, int depth, F fun)
{
    if (depth >= 10000000)
        return;
    fun(depth);
    for (auto i : to[now])
    {
        int nxt = x[i] ^ y[i] ^ now;
        if (i == from || vis[nxt])
            continue;
        dfs(nxt, i, depth + v[i], fun);
    }
}
void work(int now)
{
    init_siz(now, 0);
    int root = find_root(now, 0, siz[now]);
    vis[root] = true;
    for (auto i : to[root])
        if (!vis[x[i] ^ y[i] ^ root])
        {
            dfs(x[i] ^ y[i] ^ root, i, v[i], [&](const int &depth)
                {
                    for (int i = 0; i != m; ++i)
                        if (depth <= k[i] && app[k[i] - depth])
                            ans[i] = true;
                });
            dfs(x[i] ^ y[i] ^ root, i, v[i], [&](const int &depth)
                {
                    if (!app[depth])
                        app[depth] = true, cha.push_back(depth);
                });
        }
    while (!cha.empty())
    {
        app[cha.back()] = false;
        cha.pop_back();
    }
    for (auto i : to[root])
        if (!vis[x[i] ^ y[i] ^ root])
            work(x[i] ^ y[i] ^ root);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i != n; ++i)
    {
        std::cin >> x[i] >> y[i] >> v[i];
        to[x[i]].push_back(i);
        to[y[i]].push_back(i);
    }
    for (int i = 0; i != m; ++i)
        std::cin >> k[i];
    app[0] = true;
    work(1);
    for (int i = 0; i != m; ++i)
        std::cout << (ans[i] ? "AYE" : "NAY") << std::endl;
    return 0;
}