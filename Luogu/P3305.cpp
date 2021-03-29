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
int n, m, cnt, head[105], dis[105], cur[105];
double p, l, r, mid = INF;
struct edge
{
    int t, n;
    double v, c;
} e[2005];
void add_edge(int A, int B, double V)
{
    e[cnt] = {B, head[A], V, V};
    head[A] = cnt++;
}
void add_flow(int A, int B, int V)
{
    add_edge(A, B, V);
    add_edge(B, A, 0);
}
bool bfs()
{
    std::queue<int> que;
    que.push(1);
    std::fill(dis + 1, dis + 1 + n, -1);
    std::copy(head + 1, head + 1 + n, cur + 1);
    dis[1] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v > eps && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                que.push(e[i].t);
                if (e[i].t == n)
                    return true;
            }
    }
    return false;
}
double dfs(int now = 1, double flow = INF)
{
    if (now == n)
        return flow;
    double res = 0;
    while (~cur[now] && flow > eps)
    {
        if (e[cur[now]].v > eps && dis[now] + 1 == dis[e[cur[now]].t])
        {
            double s = dfs(e[cur[now]].t, std::min(flow, e[cur[now]].v));
            e[cur[now]].v -= s;
            e[cur[now] ^ 1].v += s;
            flow -= s;
            res += s;
        }
        cur[now] = e[cur[now]].n;
    }
    return res;
}
double dinic()
{
    double res = 0;
    for (int i = 0; i < cnt; ++i)
        e[i].v = std::min(mid, e[i].c);
    while (bfs())
        res += dfs();
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed;
    std::cin >> n >> m >> p;
    std::fill(head + 1, head + 1 + n, -1);
    for (int i = 1; i <= m; ++i)
    {
        static int f, t, v;
        std::cin >> f >> t >> v;
        add_flow(f, t, v);
    }
    double ans = dinic();
    std::cout << std::setprecision(0) << round(ans) << std::endl;
    r = ans;
    while (r - l > eps)
    {
        mid = (l + r) / 2;
        if (ans - dinic() < eps)
            r = mid;
        else
            l = mid;
    }
    std::cout << std::setprecision(4) << l * p << std::endl;
    return 0;
}