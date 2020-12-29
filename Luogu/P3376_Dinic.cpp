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
struct edge
{
    int v, t, n;
} e[10005];
int n, m, s, t, head[205], A, B, C, ans, cnt, now[205], dis[205];
void add(int F, int T, int V)
{
    e[cnt] = {V, T, head[F]};
    head[F] = cnt++;
}
bool bfs()
{
    queue<int> que;
    fill(dis + 1, dis + 1 + n, -1);
    que.push(s);
    dis[s] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = head[u]; ~i; i = e[i].n)
        {
            if (e[i].v && dis[e[i].t] == -1)
            {
                dis[e[i].t] = dis[u] + 1;
                if (e[i].t == t)
                {
                    return true;
                }
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int u = s, int flow = INF)
{
    if (u == t)
    {
        return flow;
    }
    int res = 0;
    while (~now[u] && flow)
    {
        if (dis[u] + 1 != dis[e[now[u]].t])
        {
            now[u] = e[now[u]].n;
            continue;
        }
        int v = dfs(e[now[u]].t, min(flow, e[now[u]].v));
        e[now[u] ^ 0].v -= v;
        e[now[u] ^ 1].v += v;
        flow -= v;
        res += v;
        if (flow)
        {
            now[u] = e[now[u]].n;
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    fill(head + 1, head + 1 + n, -1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> A >> B >> C;
        add(A, B, C);
        add(B, A, 0);
    }
    while (bfs())
    {
        for (int i = 1; i <= n; ++i)
        {
            now[i] = head[i];
        }
        ans += dfs();
    }
    cout << ans << endl;
    return 0;
}