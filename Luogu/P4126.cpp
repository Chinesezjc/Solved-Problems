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
int n, m, s, t, head[4005], cnt = 2, dis[4005], cur[4005], dfn[4005], low[4005], fa[4005], sta[4005], top, tim;
bool ins[4005], ans1[4005], ans2[4005];
class edge
{
public:
    int t, v, n, p;
} e[120005];
void add_flow(const int &F, const int &T, const int &Flow, const int &Pos)
{
    e[cnt] = {T, Flow, head[F], Pos};
    head[F] = cnt++;
    e[cnt] = {F, Flow, head[T], Pos};
    head[T] = cnt++;
}
bool bfs()
{
    queue<int> que({s});
    fill(dis + 1, dis + 1 + n, -1);
    dis[s] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i; i = e[i].n)
        {
            if (!~dis[e[i].t] && e[i].v)
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == t)
                    return true;
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(const int &now = s, int Flow = INF)
{
    if (now == t)
        return Flow;
    int res = 0;
    for (int i = cur[now]; i && Flow; cur[now] = i = e[i].n)
    {
        if (dis[now] + 1 == dis[e[i].t] && e[i].v)
        {
            int tmp = dfs(e[i].t, min(Flow, e[i].v));
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            Flow -= tmp;
            res += tmp;
        }
    }
    return res;
}
void dinic()
{
    while (bfs())
    {
        copy(head + 1, head + 1 + n, cur + 1);
        cout << dfs() << endl;
    }
}
void Tarjan(int now)
{
    sta[++top] = now;
    dfn[now] = low[now] = ++tim;
    ins[now] = true;
    for (int i = head[now]; i; i = e[i].n)
    {
        if (!e[i].v)
            continue;
        if (!dfn[e[i].t])
        {
            Tarjan(e[i].t);
            low[now] = min(low[now], low[e[i].t]);
        }
        else if (ins[e[i].t])
            low[now] = min(low[now], low[e[i].t]);
    }
    if (dfn[now] == low[now])
    {
        fa[now] = now;
        while (sta[top] != now)
        {
            fa[sta[top]] = now;
            ins[sta[top]] = false;
            --top;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, c;
        cin >> a >> b >> c;
        add_flow(a, b, c, i);
    }
    dinic();
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            Tarjan(i);
    for (int i = 1; i <= n; ++i)
    {
        cout << fa[i] << endl;
    }
    for (int i = 2; i != cnt; ++i)
    {
        if ((i & 1) || e[i].v || fa[e[i].t] == fa[e[i ^ 1].t])
            continue;
        ans1[i / 2] = true;
        if (min(fa[s], fa[t]) == min(fa[e[i].t], fa[e[i ^ 1].t]) &&
            max(fa[s], fa[t]) == max(fa[e[i].t], fa[e[i ^ 1].t]))
            ans2[i / 2] = true;
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << ans1[i] << ' ' << ans2[i] << endl;
    }
    return 0;
}