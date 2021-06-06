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
struct edge
{
    int n, t, v;
} e[100005];
int iid[205], oid[205], n, m, ecnt, ncnt, head[405], S, T, dis[405], cur[405];
void add_edge(int A, int B, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int V)
{
    add_edge(A, B, V);
    add_edge(B, A, 0);
}
bool bfs()
{
    std::fill(dis, dis + ncnt, -1);
    dis[S] = 0;
    std::queue<int> que;
    que.push(S);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(flow, e[i].v));
            if (!tmp)
                dis[e[i].t] = INF;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            res += tmp;
            flow -= tmp;
            if (!flow)
                break;
        }
    return res;
}
int Dinic()
{
    int res = 0;
    while (bfs())
    {
        std::copy(head, head + ncnt, cur);
        res += dfs();
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> S >> T;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; ++i)
    {
        static int v;
        iid[i] = ncnt++;
        oid[i] = ncnt++;
        std::cin >> v;
        add_flow(iid[i], oid[i], v);
    }
    S = iid[S];
    T = oid[T];
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        add_flow(oid[x], iid[y], INF);
        add_flow(oid[y], iid[x], INF);
    }
    Dinic();
    for (int i = 1; i <= n; ++i)
        if (~dis[iid[i]] && !~dis[oid[i]])
            std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}