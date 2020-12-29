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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, a[55][55], cnt = 1, tim, head[5005], id_row[55], id_column[55], s, t, dis[5005], flow[5005], ans;
bool in[5005];
queue<int> que;
struct edge
{
    int n, t, cap, cost;
} e[50005];
struct from
{
    int n, e;
} from[5005];
struct Map
{
    char a[55][55];
    int v;
    char *operator[](const int TMP)
    {
        return a[TMP];
    }
} g[5005];
void add(int F, int T, int CAP, int COST)
{
    e[++cnt] = {head[F], T, CAP, COST};
    head[F] = cnt;
}
bool spfa()
{
    in[s] = true;
    que.push(s);
    fill(dis + 1, dis + 1 + tim, -INF);
    dis[s] = 0;
    flow[s] = INF;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        // cout << now << endl;
        for (int i = head[now]; i; i = e[i].n)
        {
            if (e[i].cap && e[i].cost + dis[now] > dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + e[i].cost;
                flow[e[i].t] = min(flow[now], e[i].cap);
                from[e[i].t] = {now, i};
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
        }
    }
    return dis[t] != -INF;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    s = ++tim;
    t = ++tim;
    //3~n+2->id_row
    for (int i = 1; i <= n; ++i)
    {
        id_row[i] = ++tim;
        add(s, id_row[i], k, 0);
        add(id_row[i], s, 0, 0);
    }
    //3+n~2n+2->id_column
    for (int i = 1; i <= n; ++i)
    {
        id_column[i] = ++tim;
        add(id_column[i], t, k, 0);
        add(t, id_column[i], 0, 0);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            g[0][i][j] = '.';
            add(id_row[i], id_column[j], 1, +a[i][j]);
            add(id_column[j], id_row[i], 0, -a[i][j]);
        }
    }
    while (spfa())
    {
        int now = t;
        ans += flow[t];
        // cout << "                                            " << dis[t] << ' ' << flow[t] << endl;
        while (now != s)
        {
            e[from[now].e ^ 0].cap -= flow[t];
            e[from[now].e ^ 1].cap += flow[t];
            now = from[now].n;
            // cout << now << ' ' << from[now].n << ' ' << from[now].e << endl;
        }
        g[ans] = g[0];
        g[ans].v = g[ans - 1].v + dis[t] * flow[t];
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                g[ans][i][j] = '.';
            }
            for (int j = head[i + 2]; j; j = e[j].n)
            {
                if (e[j].t < 3 + n)
                {
                    continue;
                }
                if (e[j].cap == 0)
                {
                    g[ans][i][e[j].t - n - 2] = 'X';
                }
            }
        }
        // for (int i = 1; i <= tim; ++i)
        // {
        //     for (int j = head[i]; j; j = e[j].n)
        //     {
        //         cout << i << " to " << e[j].t << " has a edge with cap " << e[j].cap << " and cost " << e[j].cost << endl;
        //     }
        // }
    }
    int MAX = 0;
    for (int i = 1; i <= ans; ++i)
    {
        if (g[MAX].v < g[i].v)
        {
            MAX = i;
        }
    }
    cout << g[MAX].v << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << g[MAX][i][j];
        }
        cout << endl;
    }
    return 0;
}