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
std::vector<std::pair<int, int>> to[105];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
int n, m, k, dp[1 << 10][105], p[10], dis[105];
bool vis[105];
void dijkstra(int s)
{
    std::fill(vis + 1, vis + 1 + n, false);
    while (!que.empty())
    {
        int now = que.top().second;
        que.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (int i = 0; i != to[now].size(); ++i)
            if (dp[s][to[now][i].first] > dp[s][now] + to[now][i].second)
                que.push(std::make_pair(dp[s][to[now][i].first] = dp[s][now] + to[now][i].second, to[now][i].first));
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 0; i != m; ++i)
    {
        static int x, y, v;
        std::cin >> x >> y >> v;
        to[x].push_back(std::make_pair(y, v));
        to[y].push_back(std::make_pair(x, v));
    }
    for (int i = 0; i != k; ++i)
        std::cin >> p[i];
    for (int i = 0; i != 1 << k; ++i)
        std::fill(dp[i] + 1, dp[i] + 1 + n, INF);
    for (int i = 0; i != k; ++i)
        dp[1 << i][p[i]] = 0;
    for (int i = 0; i != 1 << k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int l = i & (i - 1); l; l = i & (l - 1))
                dp[i][j] = std::min(dp[i][j], dp[l][j] + dp[i ^ l][j]);
            if (dp[i][j] != INF)
                que.push(std::make_pair(dp[i][j], j));
        }
        dijkstra(i);
    }
    std::cout << *std::min_element(dp[(1 << k) - 1] + 1, dp[(1 << k) - 1] + 1 + n) << std::endl;
    return 0;
}