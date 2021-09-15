//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[100005], s, S, T, cnt, head[100005], cur[100005], dis[100005], cost;
bool in[100005];
struct edge
{
    int n, t, c, f;
} e[1000005];
void add_edge(int A, int B, int C, int F)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].c = C;
    e[cnt].f = F;
    head[A] = cnt++;
}
void add_flow(int A, int B, int C, int F)
{
    add_edge(A, B, +C, F);
    add_edge(B, A, -C, 0);
}
bool spfa()
{
    std::fill(dis, dis + n + 2, INF);
    std::queue<int> que;
    que.push(S);
    dis[S] = 0;
    in[S] = true;
    while (!que.empty())
    {
        int now = que.front();
        in[now] = false;
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].f && dis[e[i].t] > dis[now] + e[i].c)
            {
                if (!in[e[i].t])
                    que.push(e[i].t), in[e[i].t] = true;
                dis[e[i].t] = dis[now] + e[i].c;
            }
    }
    return dis[T] != INF;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T || !flow)
        return flow;
    in[now] = true;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (!in[e[i].t] && e[i].f && dis[e[i].t] == dis[now] + e[i].c)
        {
            int tmp = dfs(e[i].t, std::min(flow, e[i].f));
            if (!tmp)
                dis[e[i].t] = INF;
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            res += tmp;
            flow -= tmp;
            cost += tmp * e[i].c;
            if (!flow)
                break;
        }
    in[now] = false;
    return res;
}
void Dinic()
{
    while (spfa())
    {
        std::copy(head, head + n + 2, cur);
        dfs();
    }
}
signed main()
{
    memset(head, -1, sizeof(head));
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> a[i] >> s;
        a[i] -= s;
    }
    S = n;
    T = n + 1;
    for (int i = 0; i != n; ++i)
        if (a[i] > 0)
            add_flow(S, i, 0, +a[i]);
        else
            add_flow(i, T, 0, -a[i]);
    for (int i = 0; i != n; ++i)
        add_flow(i, (i + 1) % n, 1, INF), add_flow((i + 1) % n, i, 1, INF);
    Dinic();
    std::cout << cost << std::endl;
    return 0;
}