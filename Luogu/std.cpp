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
int n, m, s, t, a, b, c, d, cnt = 1, head[5005], dis[5005], cur[5005], ans, cost;
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
    std::queue<int> que;
    std::fill(dis + 1, dis + 1 + n, INF);
    que.push(s);
    in[s] = true;
    dis[s] = 0;
    while (!que.empty())
    {
        int now = que.front();
#ifdef debug
        std::cout << now << ' ' << dis[now] << std::endl;
#endif
        que.pop();
        in[now] = false;
        for (int i = head[now]; i; i = e[i].n)
            if (e[i].cap && dis[e[i].t] > dis[now] + e[i].cost)
            {
                dis[e[i].t] = dis[now] + e[i].cost;
                if (!in[e[i].t])
                {
                    que.push(e[i].t);
                    in[e[i].t] = true;
                }
            }
    }
#ifdef debug
    getchar();
#endif
    return dis[t] != INF;
}
int dfs(int now = s, int flow = INF)
{
    if (now == t)
        return flow;
    int res = 0;
    in[now] = true;
    while (cur[now] && flow)
    {
        if (!in[e[cur[now]].t] && e[cur[now]].cap && dis[now] + e[cur[now]].cost == dis[e[cur[now]].t])
        {
            int tmp = dfs(e[cur[now]].t, std::min(e[cur[now]].cap, flow));
            cost += e[cur[now]].cost * tmp;
            e[cur[now]].cap -= tmp;
            e[cur[now] ^ 1].cap += tmp;
            flow -= tmp;
            res += tmp;
        }
        cur[now] = e[cur[now]].n;
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
        std::copy(head + 1, head + 1 + n, cur + 1);
        int l = dfs(s, INF);
        ans += l;
        while (l)
        {
            ans += l = dfs(s, INF);
        }
    }
    cout << ans << ' ' << cost << endl;
    return 0;
}