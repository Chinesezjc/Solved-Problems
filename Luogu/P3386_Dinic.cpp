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
struct edge
{
    int v, n, t;
} e[200005];
int n, m, g, cnt = 1, head[1005], a, b, s, t, ans, dis[1005];
queue<int> que;
void add(int F, int T, int V)
{
    e[++cnt] = {V, head[F], T};
    head[F] = cnt;
}
bool bfs()
{
    memset(dis, -1, sizeof(dis));
    que.push(s);
    dis[s] = 0;
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
            int tmp = dfs(e[i].t, min(v, e[i].v));
            e[i ^ 0].v -= tmp;
            e[i ^ 1].v += tmp;
            res += tmp;
            v -= tmp;
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> g;
    s = 0;
    t = n + m + 1;
    for (int i = 1; i <= g; ++i)
    {
        cin >> a >> b;
        add(a, b + n, 1);
        add(b + n, a, 0);
    }
    for (int i = 1; i <= n; ++i)
    {
        add(s, i, 1);
        add(i, s, 0);
    }
    for (int i = 1; i <= m; ++i)
    {
        add(i + n, t, 1);
        add(t, i + n, 0);
    }
    while (bfs())
    {
        ans += dfs(s, INF);
    }
    cout << ans << endl;
    return 0;
}