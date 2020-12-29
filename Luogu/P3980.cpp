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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[1005], cnt, tot, Beg, End, head[1005], cur[1005], Max_flow, Min_cost, dis[1005];
bool in[1005];
struct way
{
    int start, end, cost;
} b[10005];
struct edge
{
    int n, t, v, c;
} e[25005];
void add_edge(int F, int T, int V, int C)
{
    e[cnt] = {head[F], T, V, C};
    head[F] = cnt++;
}
void add_flow(int F, int T, int V, int C)
{
    add_edge(F, T, V, +C);
    add_edge(T, F, 0, -C);
}
bool spfa()
{
    fill(dis, dis + n + 2, INF);
    dis[Beg] = 0;
    in[Beg] = true;
    queue<int> que({Beg});
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && dis[e[i].t] > dis[now] + e[i].c)
            {
                dis[e[i].t] = dis[now] + e[i].c;
                if (!in[e[i].t])
                {
                    que.push(e[i].t);
                    in[e[i].t] = true;
                }
            }
        }
    }
    if (dis[End] != INF)
    {
        return true;
    }
    return false;
}
int dfs(int now = Beg, int flow = INF)
{
    if (now == End)
    {
        return flow;
    }
    in[now] = true;
    int res = 0;
    while (~cur[now] && flow)
    {
        if (!in[e[cur[now]].t] && dis[now] + e[cur[now]].c == dis[e[cur[now]].t])
        {
            int v = dfs(e[cur[now]].t, min(flow, e[cur[now]].v));
            Min_cost += v * e[cur[now]].c;
            e[cur[now]].v -= v;
            e[cur[now] ^ 1].v += v;
            res += v;
            flow -= v;
        }
        if (flow)
        {
            cur[now] = e[cur[now]].n;
        }
    }
    in[now] = false;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i].start >> b[i].end >> b[i].cost;
    }
    Beg = 0;
    End = n + 1;
    fill(head, head + n + 2, -1);
    add_flow(Beg, 1, INF, 0);
    for (int i = 1; i <= n; ++i)
    {
        add_flow(i, i + 1, INF - a[i], 0);
    }
    for (int i = 1; i <= m; ++i)
    {
        add_flow(b[i].start, b[i].end + 1, INF, b[i].cost);
    }
    while (spfa())
    {
        copy(head, head + n + 2, cur);
        Max_flow += dfs();
    }
    cout << Min_cost << endl;
    return 0;
}