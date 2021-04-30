//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
int n, m, w, S, T, SS, TT, head[120], ecnt, t[60], dis[120],
    c[60], ncnt, in[60], out[60], extracost, d[120], COST, FLOW, cur[120];
bool vis[120];
std::vector<int> to[60], from[60];
struct edge
{
    int n, t, c, v;
} e[1505];
void add_edge(int A, int B, int C, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].c = C;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int C, int V)
{
    if (C <= 0)
    {
        add_edge(A, B, +C, V);
        add_edge(B, A, -C, 0);
    }
    else
    {
        d[A] -= V;
        d[B] += V;
        extracost += C * V;
        add_edge(A, B, +C, 0);
        add_edge(B, A, -C, V);
    }
}
bool spfa(int beg, int end)
{
    std::queue<int> que;
    que.push(beg);
    std::fill(dis, dis + ncnt, -INF);
    dis[beg] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        // std::cout << now << ' ' << dis[now] << std::endl;
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && dis[e[i].t] < dis[now] + e[i].c)
            {
                dis[e[i].t] = dis[now] + e[i].c;
                que.push(e[i].t);
            }
    }
    return dis[end] != -INF;
}
int dfs(int now, int end, int flow = INF)
{
    if (now == end || !flow)
        return flow;
    vis[now] = true;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
    {
        if (e[i].v && !vis[e[i].t] && dis[e[i].t] == dis[now] + e[i].c)
        {
            int tmp = dfs(e[i].t, end, std::min(e[i].v, flow));
            if (!tmp)
                dis[e[i].t] = -INF;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            COST += tmp * e[i].c;
            if (!flow)
                break;
        }
    }
    vis[now] = false;
    return res;
}
void Dinic(int beg, int end)
{
    while (spfa(beg, end))
    {
        std::copy(head, head + ncnt, cur);
        FLOW += dfs(beg, end);
    }
}
int work(int now)
{
    ecnt = 0;
    extracost = 0;
    memset(head, -1, sizeof(head));
    memset(d, 0, sizeof(d));
    add_flow(T, S, 0, INF);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j != (int)to[i].size(); ++j)
            add_flow(out[i], in[to[i][j]], 0, INF);
        add_flow(in[i], out[i], t[i], c[i]);
        add_flow(in[i], out[i], 0, INF);
        if (from[i].empty())
            add_flow(S, in[i], 0, INF);
        if (to[i].empty())
            add_flow(out[i], T, -now, INF);
    }
    for (int i = 0; i != ncnt; ++i)
    {
        if (d[i] > 0)
            add_flow(SS, i, 0, +d[i]);
        if (d[i] < 0)
            add_flow(i, TT, 0, -d[i]);
    }
    COST = extracost;
    FLOW = 0;
#ifdef debug
    for (int i = 0; i != ncnt; ++i)
        for (int j = head[i]; ~j; j = e[j].n)
            if (e[j].v)
                std::cout << i << ' ' << e[j].t << ' ' << e[j].c << ',' << e[j].v << std::endl;
#endif
    Dinic(SS, TT);
#ifdef debug
    std::cout << FLOW << ' ' << COST << std::endl;
#endif
    return COST;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> w;
    S = ncnt++;
    T = ncnt++;
    SS = ncnt++;
    TT = ncnt++;
    for (int i = 1; i <= n; ++i)
        std::cin >> t[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = 1; i <= n; ++i)
        in[i] = ncnt++;
    for (int i = 1; i <= n; ++i)
        out[i] = ncnt++;
    for (int i = 1; i <= m; ++i)
    {
        static int A, B;
        std::cin >> A >> B;
        to[A].push_back(B);
        from[B].push_back(A);
    }
    int l = 0, r = 55000;
    while (l != r)
    {
        // std::cout << "     " << l << ' ' << r << std::endl;
        int mid = (l + r) >> 1;
        if (work(mid) <= w)
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << std::endl;
    return 0;
}