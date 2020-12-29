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
int n, m, dis[100005], fa[100005], a, b, c, head[100005], cnt, from[100005], ans[100005], depth[100005];
struct edge
{
    int v, n, f, t;
    bool operator<(const edge &__Val) const
    {
        return dis[f] + dis[t] + v < dis[__Val.f] + dis[__Val.t] + __Val.v;
    }
} e[400005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
bool in[100005];
void add(int A, int B, int C)
{
    e[++cnt] = {C, head[A], A, B};
    head[A] = cnt;
}
void spfa()
{
    fill(dis + 1, dis + 1 + n, INF);
    que.push({0, 1});
    in[1] = true;
    dis[1] = 0;
    depth[1] = 1;
    while (!que.empty())
    {
        int now = que.top().second;
        que.pop();
        in[now] = false;
        for (int i = head[now]; i; i = e[i].n)
        {
            if (dis[e[i].t] > dis[now] + e[i].v)
            {
                dis[e[i].t] = dis[now] + e[i].v;
                depth[e[i].t] = depth[now] + 1;
                from[e[i].t] = now;
                if (!in[e[i].t])
                {
                    que.push({dis[e[i].t], e[i].t});
                    in[e[i].t] = true;
                }
            }
        }
    }
}
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
void work(int f, int t, int v)
{
    f = find(f);
    t = find(t);
    while (f != t)
    {
        if (depth[f] < depth[t])
        {
            ans[t] = v - dis[t];
            fa[find(t)] = find(from[t]);
            t = find(t);
        }
        else
        {
            ans[f] = v - dis[f];
            fa[find(f)] = find(from[f]);
            f = find(f);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    spfa();
    sort(e + 1, e + 1 + cnt);
    fill(ans + 1, ans + 1 + n, -1);
    for (int i = 1; i <= cnt; ++i)
    {
        if (abs(dis[e[i].f] - dis[e[i].t]) == e[i].v)
        {
            continue;
        }
        work(e[i].f, e[i].t, e[i].v + dis[e[i].f] + dis[e[i].t]);
    }
    for (int i = 2; i <= n; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}