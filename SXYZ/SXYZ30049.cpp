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
int n, m, v[55][55], id[55][55], cnt[2], val[1505][1505], fa[55], pm[2][1505], from[1505], match[2][1505], CNT, d[1505];
bool vis[2][1505], side[55][55];
void update(int now)
{
    static int tmp;
    while (now)
    {
        tmp = match[0][from[now]];
        match[0][from[now]] = now;
        match[1][now] = from[now];
        now = tmp;
    }
}
void bfs(int s)
{
    std::fill(vis[0] + 1, vis[0] + 1 + CNT, false);
    std::fill(vis[1] + 1, vis[1] + 1 + CNT, false);
    std::fill(d + 1, d + 1 + CNT, INF);
    std::queue<int> que;
    que.push(s);
    while (true)
    {
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            vis[0][now] = true;
            for (int i = 1; i <= CNT; ++i)
            {
                if (!vis[1][i] && pm[0][now] + pm[1][i] - val[now][i] < d[i])
                {
                    d[i] = pm[0][now] + pm[1][i] - val[now][i];
                    from[i] = now;
                    if (!d[i])
                    {
                        vis[1][i] = true;
                        if (!match[1][i])
                        {
                            return update(i);
                        }
                        else
                        {
                            que.push(match[1][i]);
                        }
                    }
                }
            }
        }
        int down = INF;
        for (int i = 1; i <= CNT; ++i)
        {
            if (!vis[1][i])
            {
                down = std::min(down, d[i]);
            }
        }
        for (int i = 1; i <= CNT; ++i)
        {
            if (vis[0][i])
                pm[0][i] -= down;
            if (vis[1][i])
                pm[1][i] += down;
            else
                d[i] -= down;
        }
        for (int i = 1; i <= CNT; ++i)
        {
            if (!vis[1][i] && !d[i])
            {
                vis[1][i] = true;
                if (!match[1][i])
                {
                    return update(i);
                }
                else
                {
                    que.push(match[1][i]);
                }
            }
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::fill(v[i] + 1, v[i] + 1 + n, INF);
        v[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b >> v[a][b];
        v[b][a] = v[a][b];
    }
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        side[a][b] = true;
        side[b][a] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (side[i][j])
                id[i][j] = id[j][i] = ++cnt[1];
            else
                id[i][j] = id[j][i] = ++cnt[0];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (!side[i][j] && v[i][j] != INF)
            {
                std::fill(fa + 1, fa + 1 + n, 0);
                std::queue<int> que;
                que.push(i);
                while (!que.empty())
                {
                    int now = que.front();
                    que.pop();
                    for (int k = 1; k <= n; ++k)
                        if (now != k && fa[now] != k && side[now][k])
                        {
                            fa[k] = now;
                            que.push(k);
                        }
                }
                int now = j;
                do
                    val[id[i][j]][id[fa[now]][now]] = std::max(0ll, v[fa[now]][now] - v[i][j]);
                while ((now = fa[now]));
            }
    for (int i = 1; i <= cnt[0]; ++i)
        pm[0][i] = *std::max_element(val[i] + 1, val[i] + 1 + cnt[1]);
    CNT = std::max(cnt[0], cnt[1]);
    for (int i = 1; i <= CNT; ++i)
        bfs(i);
    int res = 0;
    for (int i = 1; i <= CNT; ++i)
        res += pm[0][i] + pm[1][i];
    std::cout << res << std::endl;
    return 0;
}