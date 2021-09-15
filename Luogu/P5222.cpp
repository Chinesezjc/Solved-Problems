// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, t, q, head[100505], S, T, ncnt, ecnt, x[1005], y[1005], id[55][2005], ans[55], dis[100505], from[100505], c;
bool in[100505];
std::vector<int> app;
struct node
{
    int n, t, c, f;
} e[600505];
void add_edge(int A, int B, int C, int F)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].c = C;
    e[ecnt].f = F;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int C, int F)
{
    add_edge(A, B, +C, F);
    add_edge(B, A, -C, 0);
}
bool spfa()
{
    std::queue<int> que({S});
    std::fill(dis, dis + ncnt, 1000000000);
    dis[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].f && dis[e[i].t] > dis[now] + e[i].c)
            {
                dis[e[i].t] = dis[now] + e[i].c;
                from[e[i].t] = i;
                if (!in[e[i].t])
                    que.push(e[i].t), in[e[i].t] = true;
            }
    }
    return dis[T] != 1000000000;
}
void work()
{
    for (int i = T; i != S; i = e[from[i] ^ 1].t)
    {
        --e[from[i]].f;
        ++e[from[i] ^ 1].f;
        c += e[from[i]].c;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> t >> q;
    app.push_back(0);
    app.push_back(m - 1);
    for (int i = 0; i != t; ++i)
    {
        std::cin >> x[i] >> y[i];
        --x[i];
        --y[i];
        app.push_back(y[i]);
        if (y[i])
            app.push_back(y[i] - 1);
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    for (int i = 0; i != t; ++i)
    {
        y[i] = std::lower_bound(app.begin(), app.end(), y[i]) - app.begin();
        id[x[i]][y[i]] = -1;
    }
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != int(app.size()); ++j)
            if (~id[i][j])
                id[i][j] = ncnt++;
    S = ncnt++;
    T = ncnt++;
    std::fill(head, head + ncnt, -1);
    for (int i = 0; i != n; ++i)
    {
        if (~id[i][0])
            add_flow(S, id[i][0], 0, 1);
        for (int j = 1; j != int(app.size()); ++j)
            if (~id[i][j - 1] && ~id[i][j])
                add_flow(id[i][j - 1], id[i][j], 0, 1);
        if (~id[i][app.size() - 1])
            add_flow(id[i][app.size() - 1], T, 0, 1);
    }
    for (int i = 1; i != n; ++i)
        for (int j = 0; j != int(app.size()); ++j)
            if (~id[i - 1][j] && ~id[i][j])
                add_flow(id[i - 1][j], id[i][j], 1, 1), add_flow(id[i][j], id[i - 1][j], 1, 1);
    std::fill(ans + 1, ans + 1 + n, 1000000000);
    for (int i = 1; i <= n && spfa(); ++i)
    {
        work();
        ans[i] = c;
    }
    for (int i = 0, x; i != q; ++i)
    {
        std::cin >> x;
        std::cout << std::upper_bound(ans, ans + n + 1, x) - ans - 1 << std::endl;
    }
    return 0;
}