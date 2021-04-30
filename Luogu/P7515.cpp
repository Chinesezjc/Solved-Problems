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
int n, m, b[305][305], T, a[305][305], dis[605], head[605], cnt, tim[605];
bool in[605], yes;
std::deque<int> que;
struct edge
{
    int n, t, v;
} e[250005];
void add(int A, int B, int V)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].v = V;
    head[A] = cnt++;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        cnt = 0;
        yes = true;
        memset(head, -1, sizeof(head));
        memset(tim, 0, sizeof(tim));
        memset(a, 0, sizeof(a));
        // memset(dis,0,sizeof(dis));
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                std::cin >> b[i][j];
        for (int i = 2; i <= n; ++i)
            for (int j = 2; j <= m; ++j)
                a[i][j] = b[i - 1][j - 1] - a[i - 1][j - 1] - a[i - 1][j] - a[i][j - 1];
        for (int i = 1; i <= n; ++i)
            que.push_back(i);
        for (int i = 1; i <= m; ++i)
            que.push_back(i + n);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if ((i + j) & 1)
                {
                    add(j + n, i, 1000000 - a[i][j]);
                    add(i, j + n, a[i][j]);
                }
                else
                {
                    add(i, j + n, 1000000 - a[i][j]);
                    add(j + n, i, a[i][j]);
                }
        while (!que.empty())
        {
            int now = que.front();
            que.pop_front();
            in[now] = false;
            if (++tim[now] > n + m)
            {
                yes = false;
                break;
            }
            for (int i = head[now]; ~i; i = e[i].n)
            {
                if (dis[now] + e[i].v < dis[e[i].t])
                {
                    dis[e[i].t] = dis[now] + e[i].v;
                    if (!in[e[i].t])
                    {
                        if (tim[e[i].t] > 30)
                            que.push_front(e[i].t);
                        else
                            que.push_back(e[i].t);
                        in[e[i].t] = true;
                    }
                }
            }
        }
        if (yes)
        {
            std::cout << "YES" << std::endl;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    std::cout << a[i][j] + ((i + j) & 1 ? 1 : -1) * (dis[i] - dis[n + j]) << " \n"[j == m];
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}