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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 2147483647;
int n, m, s, head[10005], cnt, dis[10005];
bool vis[10005];
std::queue<int> que;
struct edge
{
    int t, n, v;
} e[500005];
void add(int F, int T, int V)
{
    e[cnt] = {T, head[F], V};
    head[F] = cnt++;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s;
    memset(head, -1, sizeof(head));
    std::fill(dis + 1, dis + 1 + n, INF);
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, v;
        std::cin >> x >> y >> v;
        add(x, y, v);
    }
    que.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!que.empty())
    {
        int now = que.front();
        vis[now] = false;
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (dis[e[i].t] > dis[now] + e[i].v)
            {
                dis[e[i].t] = dis[now] + e[i].v;
                if (!vis[e[i].t])
                {
                    que.push(e[i].t);
                    vis[e[i].t] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cout << dis[i] << " \n"[i == n];
    }
    return 0;
}