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
const int INF = 0x3fffffffffffffff;
int n, m, s, t, S, T, need[205], head[205], ecnt = 1, cost, from[205], Cost[205], Flow[205];
bool in[205];
struct edge
{
    int n, t, flow, cost;
} e[50005];
void add_edge(int A, int B, int FLOW, int COST)
{
    e[++ecnt] = {head[A], B, FLOW, COST};
    head[A] = ecnt;
}
void add_flow(int A, int B, int FLOW, int COST)
{
    if (COST < 0)
    {
        need[A] += FLOW;
        need[B] -= FLOW;
        cost += FLOW * COST;
        add_edge(B, A, FLOW, -COST);
        add_edge(A, B, 0, COST);
    }
    else
    {
        add_edge(A, B, FLOW, COST);
        add_edge(B, A, 0, -COST);
    }
}
bool spfa(int beg, int end)
{
    std::fill(Cost + 1, Cost + 1 + n, INF);
    Flow[beg] = INF;
    Cost[beg] = 0;
    std::queue<int> que;
    que.push(beg);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        for (int i = head[now]; i; i = e[i].n)
        {
            if (e[i].flow && Cost[e[i].t] > Cost[now] + e[i].cost)
            {
                Cost[e[i].t] = Cost[now] + e[i].cost;
                Flow[e[i].t] = std::min(Flow[now], e[i].flow);
                from[e[i].t] = i;
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
        }
    }
    return Cost[end] != INF;
}
int EK(int beg, int end)
{
    int res = 0;
    while (spfa(beg, end))
    {
        int now = end;
        res += Flow[end];
        cost += Cost[end] * Flow[end];
        while (now != beg)
        {
            e[from[now] ^ 0].flow -= Flow[end];
            e[from[now] ^ 1].flow += Flow[end];
            now = e[from[now] ^ 1].t;
        }
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s >> t;
    S = ++n;
    T = ++n;
    for (int i = 1; i <= m; ++i)
    {
        static int F, T, FLOW, COST;
        std::cin >> F >> T >> FLOW >> COST;
        add_flow(F, T, FLOW, COST);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (need[i] < 0)
            add_flow(S, i, -need[i], 0);
        if (need[i] > 0)
            add_flow(i, T, +need[i], 0);
    }
    add_flow(t, s, INF, 0);
    EK(S, T);
    std::cout << EK(s, t) << ' ' << cost << std::endl;
    return 0;
}