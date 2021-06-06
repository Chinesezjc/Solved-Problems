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
const int INF = 0x3fffffff;
int Cases, n, ncnt, ecnt, head[1405], S, T, dp[705], rk[705], sp[705],
    a[705], b[705], c[705], in[705], out[705], Max, cur[1405], dis[1405], ans1;
std::vector<int> ans2;
struct edge
{
    int n, t, v;
} e[497025];
int add_edge(int A, int B, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = V;
    return head[A] = ecnt++;
}
int add_flow(int A, int B, int V)
{
    add_edge(B, A, 0);
    return add_edge(A, B, V);
}
bool bfs()
{
    std::queue<int> que;
    std::fill(dis, dis + ncnt, -1);
    dis[S] = 0;
    que.push(S);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            if (!flow)
                break;
        }
    return res;
}
int Dinic()
{
    int res = 0;
    while (bfs())
    {
        std::copy(head, head + ncnt, cur);
        res += dfs();
    }
    return res;
}
bool cmprk(const int &A, const int &B) { return c[A] < c[B]; }
signed main()
{
    std::ios::sync_with_stdio(false);
    for (std::cin >> Cases; Cases--;)
    {
        std::cin >> n;
        ncnt = 0;
        ecnt = 0;
        memset(head, -1, sizeof(head));
        S = ncnt++;
        T = ncnt++;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> c[i];
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = 1;
            for (int j = 1; j < i; ++j)
                if (a[j] < a[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
        }
        for (int i = 1; i <= n; ++i)
            in[i] = ncnt++;
        for (int i = 1; i <= n; ++i)
            out[i] = ncnt++;
        Max = *std::max_element(dp + 1, dp + 1 + n);
        for (int i = 1; i <= n; ++i)
        {
            sp[i] = add_flow(in[i], out[i], b[i]);
            if (dp[i] == 1)
                add_flow(S, in[i], INF);
            if (dp[i] == Max)
                add_flow(out[i], T, INF);
            for (int j = 1; j < i; ++j)
                if (dp[j] + 1 == dp[i] && a[j] < a[i])
                    add_flow(out[j], in[i], INF);
        }
        // std::cout << ecnt << std::endl;
        std::cout << (ans1 = Dinic()) << ' ';
        for (int i = 1; i <= n; ++i)
            rk[i] = i;
        std::sort(rk + 1, rk + 1 + n, cmprk);
        // for (int j = 0; j != ncnt; ++j)
        //     for (int k = head[j]; ~k; k = e[k].n)
        //             std::cout << j << ' ' << e[k].t << std::endl;
        for (int i = 1; i <= n; ++i)
            if (!e[sp[rk[i]]].v)
            {
                for (int j = 0; j != ecnt; ++j)
                    if (j & 1)
                        e[j].v += e[j ^ 1].v, e[j ^ 1].v = 0;
                // std::cout << rk[i] << std::endl;
                e[sp[rk[i]]].v = 0;
                if (Dinic() + b[rk[i]] == ans1)
                    ans1 -= b[rk[i]], ans2.push_back(rk[i]);
                else
                {
                    e[sp[rk[i]]].v = b[rk[i]];
                    Dinic();
                }
            }
        std::sort(ans2.begin(), ans2.end());
        std::cout << ans2.size() << std::endl;
        for (int i = 0; i != (int)ans2.size(); ++i, std::cout << " \n"[i == (int)ans2.size()])
            std::cout << ans2[i];
        ans2.clear();
    }
    return 0;
}