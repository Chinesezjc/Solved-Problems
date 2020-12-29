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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, id[55][55], cnt, tim, head[6005], s, t, tot = 1, dis[6005], ans, cost, NOW[6005];
bool in[6005];
queue<int> que;
struct node
{
    int x, y;
    bool can[55][55];
    node(int X = 0, int Y = 0)
    {
        x = X;
        y = Y;
        memset(can, false, sizeof can);
    }
} g[105];
struct edge
{
    int cost, cap, nxt, to;
} e[500005];
char a[55][55];
void add(int f, int t, int cost, int cap)
{
    e[++tot] = {cost, cap, head[f], t};
    head[f] = tot;
}
bool spfa()
{
    fill(dis + 1, dis + 1 + tim, -INF);
    dis[s] = 0;
    in[s] = true;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        in[now] = false;
        que.pop();
        for (int i = head[now]; i; i = e[i].nxt)
        {
            if (e[i].cap && dis[e[i].to] < dis[now] + e[i].cost)
            {
                dis[e[i].to] = dis[now] + e[i].cost;
                if (!in[e[i].to])
                {
                    in[e[i].to] = true;
                    que.push(e[i].to);
                }
            }
        }
    }
    return dis[t] != -INF;
}
int dfs(int now, int v)
{
    // cout << now << ' ' << v << ' ' << sta << endl;
    if (now == t)
    {
        ans += v;
        return v;
    }
    in[now] = true;
    int res = 0;
    for (int i = NOW[now]; i && v; i = e[i].nxt)
    {
        NOW[now] = i;
        if (!in[e[i].to] && e[i].cap && dis[now] + e[i].cost == dis[e[i].to])
        {
            int tmp = dfs(e[i].to, min(v, e[i].cap));
            e[i ^ 0].cap -= tmp;
            e[i ^ 1].cap += tmp;
            v -= tmp;
            res += tmp;
            cost += e[i].cost * tmp;
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
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'o')
            {
                g[++cnt] = {i, j};
            }
        }
    }
    for (int k = 1; k <= cnt; ++k)
    {
        g[k].can[g[k].x][g[k].y] = true;
        for (int i = g[k].x; i <= n; ++i)
        {
            for (int j = g[k].y; j <= m; ++j)
            {
                g[k].can[i][j] |= (a[i][j] != '#' && (g[k].can[i - 1][j] || g[k].can[i][j - 1]));
            }
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        ++tim;
    }
    s = ++tim;
    t = ++tim;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            id[i][j] = ++tim;
            add(id[i][j], t, 0, 1);
            add(t, id[i][j], 0, 0);
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        add(s, i, 0, 1);
        add(i, s, 0, 0);
        for (int j = g[i].x; j <= n; ++j)
        {
            for (int k = g[i].y; k <= m; ++k)
            {
                if (g[i].can[j][k])
                {
                    add(i, id[j][k], +(j - g[i].x) + (k - g[i].y), 1);
                    add(id[j][k], i, -(j - g[i].x) - (k - g[i].y), 0);
                }
            }
        }
    }
    while (spfa())
    {
        for (int i = 1; i <= tim; ++i)
        {
            NOW[i] = head[i];
        }
        int l = dfs(s, INF);
        while (l)
        {
            l = dfs(s, INF);
            // getchar();
        }
    }
    cout << cost << endl;
    return 0;
}
