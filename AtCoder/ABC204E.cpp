//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, dis[100005], a[100005], b[100005], c[100005], d[100005], e[100005];
std::vector<int> to[100005];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
        e[i] = sqrt(d[i]);
    }
    std::fill(dis + 1, dis + 1 + n, INF);
    que.push({dis[1] = 0, 1});
    while (!que.empty())
    {
        int now = que.top().second;
        if (dis[now] != que.top().first)
        {
            que.pop();
            continue;
        }
        que.pop();
        for (auto i : to[now])
        {
            int nxt = a[i] ^ b[i] ^ now;
            for (int j = std::max(e[i] - 2, dis[now]), lim = j + 5; j <= lim; ++j)
            {
                if (dis[nxt] > c[i] + d[i] / (j + 1) + j)
                {
                    dis[nxt] = c[i] + d[i] / (j + 1) + j;
                    que.push({dis[nxt], nxt});
                }
            }
        }
    }
    std::cout << (dis[n] >= INF ? -1 : dis[n]) << std::endl;
    return 0;
}