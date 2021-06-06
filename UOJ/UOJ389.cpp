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
#include <cassert>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, cnt, head[20005], S, T, x[20005], y[20005], dis[20005],
    h[20005], del[20005], cur[20005], vis[20005], cost, flow, ans, fa[20005];
bool has[20005];
double w[20005];
struct edge
{
    int n, t, v, c;
} e[80005];
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
void add_edge(int A, int B, int F, int C)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].v = F;
    e[cnt].c = C;
    head[A] = cnt++;
}
void add_flow(int A, int B, int F, int C)
{
    add_edge(A, B, F, +C);
    add_edge(B, A, 0, -C);
}
struct priority_queue
{
    int Min;
    std::vector<int> s[100005];
    priority_queue() : Min(100005) {}
    void push(int pos, int val)
    {
        Min = std::min(Min, pos);
        s[pos].push_back(val);
    }
    void pop()
    {
        while (Min != 100005 && s[Min].empty())
            ++Min;
        s[Min].pop_back();
    }
    void clear()
    {
        while (Min != 100005)
            s[Min++].clear();
    }
    bool empty()
    {
        while (Min != 100005 && s[Min].empty())
            ++Min;
        return Min == 100005;
    }
    int top()
    {
        while (Min != 100005 && s[Min].empty())
            ++Min;
        return s[Min].back();
    }
} que;
bool Dijkstra()
{
    que.clear();
    std::copy(dis, dis + 2 + n, h);
    std::fill(dis, dis + 2 + n, INF);
    std::fill(vis, vis + 2 + n, false);
    que.push(dis[S] = 0, S);
    while (!que.empty())
    {
        int now = que.top();
        que.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && dis[e[i].t] > dis[now] + e[i].c + h[now] - h[e[i].t])
                que.push(dis[e[i].t] = dis[now] + e[i].c + h[now] - h[e[i].t], e[i].t);
    }
    // std::cout << "end " << cost << ' ' << flow << std::endl;
    for (int i = S; i <= T; ++i)
        dis[i] += h[i];
    return vis[T];
}
int dfs(int now = S, int Flow = INF)
{
    if (now == T || !Flow)
        return Flow;
    vis[now] = true;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && !vis[e[i].t] && dis[e[i].t] == dis[now] + e[i].c)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, Flow));
            if (!tmp)
                vis[e[i].t] = true;
            cost += tmp * e[i].c;
            res += tmp;
            Flow -= tmp;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            if (!Flow)
                break;
        }
    vis[now] = false;
    return res;
}
void Dinic()
{
    while (Dijkstra())
    {
        std::fill(vis, vis + n + 2, false);
        std::copy(head, head + n + 2, cur);
        flow += dfs();
    }
}
signed main()
{
    // freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> x[i] >> y[i];
        w[i] = atan2(x[i], y[i]);
        fa[i] = i;
    }
    S = 0;
    T = n + 1;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        if (w[x] < w[y])
            std::swap(x, y);
        ++del[x];
        --del[y];
        has[x] = has[y] = true;
        bool flag = w[x] - w[y] > PI;
        ans += flag;
        add_flow(x, y, 1, flag);
        fa[find(x)] = find(y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (has[i] && (find(i) != find(1) || del[i] % 2))
            return std::cout << -1 << std::endl, 0;
        if (del[i] > 0)
            add_flow(S, i, +del[i] / 2, 0);
        if (del[i] < 0)
            add_flow(i, T, -del[i] / 2, 0);
    }
    Dinic();
    // std::cout << ans << std::endl;
    std::cout << ans - cost * 2 << std::endl;
    return 0;
}