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
int n, m, id[105][105], num, cnt = 1, head[20005], dis[20005], ans, s, t;
char Map[105][105];
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
const char cha[4][3] = {"<>", "^v", "><", "v^"};
queue<int> que;
struct edge
{
    int n, v, t;
} e[80005];
void add(int a, int b, int c)
{
    e[++cnt] = {head[a], c, b};
    head[a] = cnt;
}
bool bfs()
{
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == t)
                {
                    while (!que.empty())
                    {
                        que.pop();
                    }
                    return true;
                }
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int now, int v)
{
    if (now == t)
    {
        return v;
    }
    int res = 0;
    for (int i = head[now]; i && v; i = e[i].n)
    {
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, min(e[i].v, v));
            res += tmp;
            v -= tmp;
            e[i ^ 0].v -= tmp;
            e[i ^ 1].v += tmp;
        }
    }
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
            cin >> Map[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            id[i][j] = ++num;
        }
    }
    s = 0;
    t = ++num;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) & 1)
            {
                add(s, id[i][j], 1);
                add(id[i][j], s, 0);
            }
            else
            {
                add(id[i][j], t, 1);
                add(t, id[i][j], 0);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (((i + j) & 1) && Map[i][j] == '.')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + xx[k], y = j + yy[k];
                    if (x < 1 || x > n || y < 1 || y > m || Map[x][y] == '#')
                    {
                        continue;
                    }
                    add(id[i][j], id[x][y], 1);
                    add(id[x][y], id[i][j], 0);
                }
            }
        }
    }
    while (bfs())
    {
        ans += dfs(s, INF);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (((i + j) & 1) && Map[i][j] == '.')
            {
                for (int k = head[id[i][j]]; k; k = e[k].n)
                {
                    if (e[k].v == 0)
                    {
                        for (int l = 0; l < 4; ++l)
                        {
                            int x = i + xx[l], y = j + yy[l];
                            if (x < 1 || x > n || y < 1 || y > m || Map[x][y] == '#')
                            {
                                continue;
                            }
                            if (e[k].t == id[x][y])
                            {
                                Map[i][j] = cha[l][1];
                                Map[x][y] = cha[l][0];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << Map[i][j];
        }
        cout << endl;
    }
    return 0;
}