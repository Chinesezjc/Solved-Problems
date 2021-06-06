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
int n, m, head[5005], dis[5005], tim[5005];
bool in[5005];
std::queue<int> que;
struct edge
{
    int n, t, v;
} e[5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, z;
        std::cin >> x >> y >> z;
        e[i].n = head[y];
        e[i].t = x;
        e[i].v = z;
        head[y] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        que.push(i);
        in[i] = true;
    }
    while (!que.empty())
    {
        int now = que.front();
        in[now] = false;
        que.pop();
        if (++tim[now] > n)
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
        for (int i = head[now]; i; i = e[i].n)
        {
            if (dis[e[i].t] > dis[now] + e[i].v)
            {
                dis[e[i].t] = dis[now] + e[i].v;
                if (!in[e[i].t])
                {
                    que.push(e[i].t);
                    in[e[i].t] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << dis[i] << " \n"[i == n];
    return 0;
}