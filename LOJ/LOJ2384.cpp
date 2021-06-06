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
const int xx[] = {0, 1, 0, -1},
          yy[] = {1, 0, -1, 0};
int n, m, l, d, a[45][45][45], head[100005], cur[100005], dis[100005], ncnt, ecnt, id[45][45][45], S, T;
struct edge
{
    int n, t, v;
} e[200005];
void add_edge(int A, int B, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int V)
{
    add_edge(A, B, V);
    add_edge(B, A, 0);
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
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[now] + 1 == dis[e[i].t])
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
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
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> l >> d;
    for (int k = 1; k <= l; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> a[k][i][j];
    for (int k = 0; k <= l; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                id[k][i][j] = ncnt++;
    S = ncnt++;
    T = ncnt++;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            add_flow(S, id[0][i][j], INF);
            for (int k = 1; k <= l; ++k)
            {
                add_flow(id[k - 1][i][j], id[k][i][j], a[k][i][j]);
                if (k > d)
                    for (int l = 0; l != 4; ++l)
                        if (i + xx[l] >= 1 && i + xx[l] <= n && j + yy[l] >= 1 && j + yy[l] <= m)
                            add_flow(id[k][i][j], id[k - d][i + xx[l]][j + yy[l]], INF);
            }
            add_flow(id[l][i][j], T, INF);
        }
    std::cout << Dinic() << std::endl;
    return 0;
}