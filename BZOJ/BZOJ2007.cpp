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
const int xx[] = {0, 1, 0, -1},
          yy[] = {1, 0, -1, 0};
const int INF = 0x3fffffff;
int n, v[4][505][505], ecnt, ncnt, id[505][505], head[300005], S, T, cur[300005], dis[300005];
bool vis[300005];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
struct edge
{
    int n, t, v;
} e[2500005];
void add_edge(int A, int B, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            id[i][j] = ncnt++;
    S = ncnt++;
    T = ncnt++;
    memset(head, -1, sizeof(head));
    for (int k = 0; k != 4; ++k)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (i + xx[k] >= 0 && i + xx[k] <= n && j + yy[k] >= 0 && j + yy[k] <= n)
                {
                    std::cin >> v[k][i][j];
                    switch (k)
                    {
                    case 0:
                        add_edge(i == 0 ? S : id[i - 1][j], i == n ? T : id[i][j], v[k][i][j]);
                        break;
                    case 1:
                        add_edge(j == n ? S : id[i][j], j == 0 ? T : id[i][j - 1], v[k][i][j]);
                        break;
                    case 2:
                        add_edge(i == n ? T : id[i][j - 1], i == 0 ? S : id[i - 1][j - 1], v[k][i][j]);
                        break;
                    case 3:
                        add_edge(j == 0 ? T : id[i - 1][j - 1], j == n ? S : id[i - 1][j], v[k][i][j]);
                        break;
                    }
                }
    std::fill(dis, dis + ncnt, INF);
    que.push(std::make_pair(dis[S] = 0, S));
    while (!que.empty())
    {
        int now = que.top().second;
        que.pop();
        if (vis[now])
            continue;
        for (int i = head[now]; ~i; i = e[i].n)
            if (dis[e[i].t] > dis[now] + e[i].v)
                que.push(std::make_pair(dis[e[i].t] = dis[now] + e[i].v, e[i].t));
    }
    std::cout << dis[T] << std::endl;
    return 0;
}