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
int n, m, s, t, a, b, c, d, cnt = 1, head[5005], dis[5005], ans, cost;
queue<int> que;
bool in[5005];
struct edge
{
    int n, t, cap, cost;
} e[100005];
void add(int F, int T, int CAP, int COST)
{
    e[++cnt] = {head[F], T, CAP, COST};
    head[F] = cnt;
}
bool spfa()
{
    fill(dis + 1, dis + 1 + n, INF);
    dis[s] = 0;
    in[s] = true;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        in[now] = false;
        que.pop();
        for (int i = head[now]; i; i = e[i].n)
        {
            if (e[i].cap && dis[e[i].t] > dis[now] + e[i].cost)
            {
                dis[e[i].t] = dis[now] + e[i].cost;
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
        }
    }
    return dis[t] != INF;
}
int dfs(int now, int v)
{
    // cout << now << ' ' << v << endl;
    if (now == t)
    {
        ans += v;
        return v;
    }
    in[now] = true;
    int res = 0;
    for (int i = head[now]; i && v; i = e[i].n)
    {
        if (!in[e[i].t] && e[i].cap && dis[now] + e[i].cost == dis[e[i].t])
        {
            int tmp = dfs(e[i].t, min(v, e[i].cap));
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
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c >> d;
        add(a, b, c, +d);
        add(b, a, 0, -d);
    }
    while (spfa())
    {
        dfs(s, INF);
    }
    cout << ans << ' ' << cost << endl;
    return 0;
}   