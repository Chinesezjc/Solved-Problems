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
const int INF = 0x3fffffffffffffff;
int n, m, s, t, head[10005], ecnt, dfn[10005], low[10005], cur[10005], dis[10005], tim, fa[10005];
bool l[10005], ins[10005];
std::vector<std::pair<int, int>> ans;
std::vector<int> to[10005];
struct edge
{
    int n, t, flow;
} e[500005];
void add_edge(int A, int B, int FLOW)
{
    e[ecnt] = {head[A], B, FLOW};
    head[A] = ecnt++;
}
void add_flow(int A, int B, int FLOW)
{
    add_edge(A, B, FLOW);
    add_edge(B, A, 0);
}
bool bfs(int beg, int end)
{
    std::fill(dis, dis + n + 2, -1);
    dis[beg] = 0;
    std::queue<int> que;
    que.push(beg);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].flow && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == end)
                    return true;
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int now, int end, int flow = INF)
{
    if (now == end)
        return flow;
    int res = 0, &i = cur[now];
    while (~i)
    {
        if (e[i].flow && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, end, std::min(e[i].flow, flow));
            e[i].flow -= tmp;
            e[i ^ 1].flow += tmp;
            res += tmp;
            flow -= tmp;
            if (!flow)
                return res;
        }
        i = e[i].n;
    }
    return res;
}
int Dinic(int beg, int end)
{
    int res = 0;
    while (bfs(beg, end))
    {
        std::copy(head, head + n + 2, cur);
        res += dfs(beg, end);
    }
    return res;
}
void Tarjan(int now)
{
    static std::stack<int> sta;
    sta.push(now);
    ins[now] = true;
    dfn[now] = low[now] = ++tim;
    for (int i = head[now]; ~i; i = e[i].n)
    {
        if (e[i].flow)
        {
            if (!dfn[e[i].t])
            {
                Tarjan(e[i].t);
                low[now] = std::min(low[now], low[e[i].t]);
            }
            else if (ins[e[i].t])
            {
                low[now] = std::min(low[now], low[e[i].t]);
            }
        }
    }
    if (dfn[now] == low[now])
    {
        while (sta.top() != now)
        {
            fa[sta.top()] = now;
            ins[sta.top()] = false;
            sta.pop();
        }
        fa[now] = now;
        ins[now] = false;
        sta.pop();
    }
}
void init(int now)
{
    for (int i = 0; i < to[now].size(); ++i)
    {
        if (!ins[to[now][i]])
        {
            ins[to[now][i]] = true;
            l[to[now][i]] = !l[now];
            init(to[now][i]);
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    memset(head, -1, sizeof(head));
    s = 0;
    t = n + 1;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!ins[i])
            init(i);
    for (int i = 1; i <= n; ++i)
        if (l[i])
            add_flow(i, t, 1);
        else
        {
            add_flow(s, i, 1);
            for (int j = 0; j < to[i].size(); ++j)
                add_flow(i, to[i][j], 1);
        }
    Dinic(s, t);
    for (int i = 0; i <= n + 1; ++i)
        if (!dfn[i])
            Tarjan(i);
    // for (int i = 0; i <= n + 1; ++i)
    // {
    //     for (int j = head[i]; ~j; j = e[j].n)
    //     {
    //         if (j % 2 == 0)
    //             std::cout << i << ' ' << e[j].t << ' ' << e[j].flow << std::endl;
    //     }
    // }
    for (int i = 1; i <= n; ++i)
        if (!l[i])
            for (int j = head[i]; ~j; j = e[j].n)
                if (l[e[j].t] && !e[j].flow && fa[i] != fa[e[j].t])
                    ans.push_back(std::make_pair(std::min(i, e[j].t), std::max(i, e[j].t)));
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
    return 0;
}