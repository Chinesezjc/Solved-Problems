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
#include <cassert>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, p[45], cid[45], pid[105], did[105], s, t, ncnt, ecnt, tim[45][105], head[100000], xx[105], cost;
int Cost[100000], Flow[100000], from[100000];
bool in[100000];
struct edge
{
    int t, n, flow, cost;
} e[100000];
int add_edge(int F, int T, int FLOW, int COST)
{
    e[ecnt] = {T, head[F], FLOW, COST};
    return head[F] = ecnt++;
}
int add_flow(int F, int T, int FLOW, int COST)
{
    add_edge(F, T, FLOW, COST);
    return add_edge(T, F, 0, -COST) - 1;
}
int cnt[100000];
bool spfa()
{
    std::queue<int> que;
    std::fill(Cost, Cost + ncnt, INF);
    std::fill(cnt, cnt + ncnt, 0);
    que.push(s);
    in[s] = true;
    Cost[s] = 0;
    Flow[s] = INF;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].flow && Cost[e[i].t] > Cost[now] + e[i].cost)
            {
                Cost[e[i].t] = Cost[now] + e[i].cost;
                Flow[e[i].t] = std::min(Flow[now], e[i].flow);
                from[e[i].t] = i;
                if (!in[e[i].t])
                {
                    if (++cnt[e[i].t] > ncnt)
                        assert(false);
                    que.push(e[i].t);
                    in[e[i].t] = true;
                }
            }
    }
    return Cost[t] != INF;
}
void update()
{
    int now = t;
    cost += Cost[t] * Flow[t];
    while (now != s)
    {
        e[from[now]].flow -= Flow[t];
        e[from[now] ^ 1].flow += Flow[t];
        now = e[from[now] ^ 1].t;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> m;
    s = ncnt++;
    t = ncnt++;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cid[i] = ncnt++;
    for (int i = 1; i <= m; ++i)
        pid[i] = ncnt++;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> tim[i][j];
    for (int i = 1; i <= n; ++i)
        add_flow(cid[i], t, p[i], 0);
    for (int i = 1; i <= m; ++i)
        did[i] = add_flow(s, pid[i], 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            add_flow(pid[j], cid[i], 1, tim[i][j]);
    while (spfa())
    {
        update();
        for (int j = 1; j <= m; ++j)
            if (!e[did[j]].flow)
            {
                ++xx[j];
                pid[j] = ncnt++;
                did[j] = add_flow(s, pid[j], 1, 0);
                for (int i = 1; i <= n; ++i)
                    add_flow(pid[j], cid[i], 1, tim[i][j] * (xx[j] + 1));
            }
    }
    std::cout << cost << std::endl;
    return 0;
}