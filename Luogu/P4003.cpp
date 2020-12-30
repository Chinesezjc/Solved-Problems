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
const int pop_count[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
int n, m, tot, cnt, Beg, End, head[10005], dis[10005], cur[10005], Max_flow, Min_cost;
int IN, OUT;
#define add_inside(A, B, C)                   \
    if ((i + j) & 1)                          \
        add_flow(a[i][j].A, a[i][j].B, 1, C); \
    else                                      \
        add_flow(a[i][j].B, a[i][j].A, 1, C);
bool in[10005];
struct node
{
    int l, r, d, u, m, v;
} a[2005][2005];
struct edge
{
    int n, t, v, c;
} e[30005];
void add_edge(int F, int T, int V, int C)
{
    e[cnt] = {head[F], T, V, C};
    head[F] = cnt++;
}
void add_flow(int F, int T, int V, int C)
{
#ifdef debug
    cout << F << ' ' << T << ' ' << V << ',' << C << endl;
#endif
    add_edge(F, T, V, +C);
    add_edge(T, F, 0, -C);
}
bool spfa()
{
    fill(dis, dis + tot, INF);
    dis[Beg] = 0;
    queue<int> que({Beg});
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && dis[now] + e[i].c < dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + e[i].c;
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
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
        for (int j = 1; j <= m; ++j)
        {
            a[i][j].l = tot++;
            a[i][j].r = tot++;
            a[i][j].d = tot++;
            a[i][j].u = tot++;
            a[i][j].m = tot++;
            cin >> a[i][j].v;
        }
    }
    Beg = tot++;
    End = tot++;
    fill(head, head + tot, -1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) & 1)
            {
                add_flow(Beg, a[i][j].m, pop_count[a[i][j].v], 0);
                IN += pop_count[a[i][j].v];
                if (i > 1)
                {
                    add_flow(a[i][j].u, a[i - 1][j].d, 1, 0);
                }
                if (j > 1)
                {
                    add_flow(a[i][j].l, a[i][j - 1].r, 1, 0);
                }
                if (i < n)
                {
                    add_flow(a[i][j].d, a[i + 1][j].u, 1, 0);
                }
                if (j < m)
                {
                    add_flow(a[i][j].r, a[i][j + 1].l, 1, 0);
                }
            }
            else
            {
                OUT += pop_count[a[i][j].v];
                add_flow(a[i][j].m, End, pop_count[a[i][j].v], 0);
            }
            switch (a[i][j].v)
            {
            case 0b0000:
                break;
            case 0b0001:
                add_inside(m, u, 0);
                add_inside(u, r, 1);
                add_inside(u, d, 2);
                add_inside(u, l, 1);
                break;
            case 0b0010:
                add_inside(m, r, 0);
                add_inside(r, d, 1);
                add_inside(r, l, 2);
                add_inside(r, u, 1);
                break;
            case 0b0011:
                add_inside(m, u, 0);
                add_inside(m, r, 0);
                add_inside(u, d, 1);
                add_inside(r, l, 1);
                break;
            case 0b0100:
                add_inside(m, d, 0);
                add_inside(d, l, 1);
                add_inside(d, u, 2);
                add_inside(d, r, 1);
                break;
            case 0b0101:
                add_inside(m, u, 0);
                add_inside(m, d, 0);
                break;
            case 0b0110:
                add_inside(m, r, 0);
                add_inside(m, d, 0);
                add_inside(r, l, 1);
                add_inside(d, u, 1);
                break;
            case 0b0111:
                add_inside(m, u, 0);
                add_inside(m, r, 0);
                add_inside(m, d, 0);
                add_inside(u, l, 1);
                add_inside(r, l, 2);
                add_inside(d, l, 1);
                break;
            case 0b1000:
                add_inside(m, l, 0);
                add_inside(l, u, 1);
                add_inside(l, r, 2);
                add_inside(l, d, 1);
                break;
            case 0b1001:
                add_inside(m, l, 0);
                add_inside(m, u, 0);
                add_inside(l, r, 1);
                add_inside(u, d, 1);
                break;
            case 0b1010:
                add_inside(m, r, 0);
                add_inside(m, l, 0);
                break;
            case 0b1011:
                add_inside(m, l, 0);
                add_inside(m, u, 0);
                add_inside(m, r, 0);
                add_inside(l, d, 1);
                add_inside(u, d, 2);
                add_inside(r, d, 1);
                break;
            case 0b1100:
                add_inside(m, d, 0);
                add_inside(m, l, 0);
                add_inside(d, u, 1);
                add_inside(l, r, 1);
                break;
            case 0b1101:
                add_inside(m, d, 0);
                add_inside(m, l, 0);
                add_inside(m, u, 0);
                add_inside(d, r, 1);
                add_inside(l, r, 2);
                add_inside(u, r, 1);
                break;
            case 0b1110:
                add_inside(m, r, 0);
                add_inside(m, d, 0);
                add_inside(m, l, 0);
                add_inside(r, u, 1);
                add_inside(d, u, 2);
                add_inside(l, u, 1);
                break;
            case 0b1111:
                add_inside(m, u, 0);
                add_inside(m, r, 0);
                add_inside(m, d, 0);
                add_inside(m, l, 0);
                break;
            }
        }
    }
    if (IN != OUT)
    {
        cout << -1 << endl;
        return 0;
    }
    while (spfa())
    {
        copy(head, head + tot, cur);
        Max_flow += dfs();
#ifdef debug
        cout << Max_flow << endl;
#endif
    }
    cout << (Max_flow != IN ? -1 : Min_cost) << endl;
    return 0;
}