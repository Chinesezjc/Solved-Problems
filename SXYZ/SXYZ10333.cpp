// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, x[100005], y[100005], z[100005], v[100005], cnt, ans[100005], dfn[600005], low[600005], tim, in[600005], CNT,
    vis[600005];
std::vector<int> g[100005], to[600005], name[100005][2], TO[600005];
std::stack<int> sta;
void new_node(int &x) { x = cnt++; }
void add_edge(int A, int B) { to[A].push_back(B); }
void Tarjan(int now)
{
    sta.push(now);
    vis[now] = true;
    dfn[now] = low[now] = ++tim;
    for (auto i : to[now])
    {
        if (!dfn[i])
        {
            Tarjan(i);
            low[now] = std::min(low[now], low[i]);
        }
        else if (vis[i])
            low[now] = std::min(low[now], low[i]);
    }
    if (dfn[now] == low[now])
    {
        while (sta.top() != now)
        {
            vis[sta.top()] = false;
            in[sta.top()] = CNT;
            sta.pop();
        }
        vis[now] = false;
        in[now] = CNT++;
        sta.pop();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x[i] >> y[i] >> z[i] >> v[i];
        g[x[i]].push_back(v[i]);
        g[y[i]].push_back(v[i]);
        g[z[i]].push_back(v[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (g[i].empty())
        {
            ans[i] = 1;
            continue;
        }
        std::sort(g[i].begin(), g[i].end());
        g[i].erase(std::unique(g[i].begin(), g[i].end()), g[i].end());
        name[i][0].resize(g[i].size());
        name[i][1].resize(g[i].size());
        std::for_each(name[i][0].begin(), name[i][0].end(), new_node);
        std::for_each(name[i][1].begin(), name[i][1].end(), new_node);
        for (std::size_t j = 1; j != g[i].size(); ++j)
            add_edge(name[i][0][j - 1], name[i][0][j]), add_edge(name[i][1][j], name[i][1][j - 1]);
    }
    for (int i = 1, a, b, c; i <= m; ++i)
    {
        a = std::lower_bound(g[x[i]].begin(), g[x[i]].end(), v[i]) - g[x[i]].begin();
        b = std::lower_bound(g[y[i]].begin(), g[y[i]].end(), v[i]) - g[y[i]].begin();
        c = std::lower_bound(g[z[i]].begin(), g[z[i]].end(), v[i]) - g[z[i]].begin();
        // std::cout << a << ' ' << b << ' ' << c << std::endl;
        // if (i == 1)
        // {
        // }
        // if (i == 2)
        // {
        // }
        if (a)
        {
            if (b)
                add_edge(name[x[i]][0][a - 1], name[y[i]][1][b - 1]);
            if (c)
                add_edge(name[x[i]][0][a - 1], name[z[i]][1][c - 1]);
        }
        add_edge(name[x[i]][1][a], name[y[i]][0][b]);
        add_edge(name[x[i]][1][a], name[z[i]][0][c]);
        if (b)
        {
            if (a)
                add_edge(name[y[i]][0][b - 1], name[x[i]][1][a - 1]);
            if (c)
                add_edge(name[y[i]][0][b - 1], name[z[i]][1][c - 1]);
        }
        add_edge(name[y[i]][1][b], name[x[i]][0][a]);
        add_edge(name[y[i]][1][b], name[z[i]][0][c]);
        if (c)
        {
            if (a)
                add_edge(name[z[i]][0][c - 1], name[x[i]][1][a - 1]);
            if (b)
                add_edge(name[z[i]][0][c - 1], name[y[i]][1][b - 1]);
        }
        add_edge(name[z[i]][1][c], name[x[i]][0][a]);
        add_edge(name[z[i]][1][c], name[y[i]][0][b]);
    }
    // for (int i = 0; i != cnt; ++i)
    //     for (auto j : to[i])
    //         std::cout << i << ' ' << j << std::endl;
    for (int i = 0; i != cnt; ++i)
    {
        if (!dfn[i])
            Tarjan(i);
        for (auto j : to[i])
            if (in[j] != in[i])
                TO[in[i]].push_back(in[j]);
    }
    // for (int i = 0; i != cnt; ++i)
    //     std::cout << i << ' ' << in[i] << "'" << std::endl;
    for (int i = 1; i <= n; ++i)
        for (std::size_t j = 0; j != g[i].size(); ++j)
            if (in[name[i][0][j]] == in[name[i][1][j]])
                return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl;
    for (int i = 1; i <= n; ++i)
        if (!g[i].empty())
        {
            ans[i] = g[i].back();
            for (std::size_t j = 0; j != g[i].size(); ++j)
                if (in[name[i][0][j]] < in[name[i][1][j]])
                {
                    ans[i] = g[i][j];
                    break;
                }
        }
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}