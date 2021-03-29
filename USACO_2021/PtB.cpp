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
int n, m, T, dis[2][100005];
std::vector<int> to[100005];
std::queue<std::pair<int, int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        for (int i = 1; i <= m; ++i)
        {
            static int a, b;
            std::cin >> a >> b;
            to[a].push_back(b);
            to[b].push_back(a);
        }
        memset(dis, -1, sizeof(dis));
        que.push(std::make_pair(0, 1));
        while (!que.empty())
        {
            std::pair<int, int> now = que.front();
            for (int i = 0; i != to[now.second].size(); ++i)
                if (!~dis[!now.first][to[now.second][i]])
                {
                    dis[!now.first][to[now.second][i]] = dis[now.first][to[now.second][i]] + 1;
                    que.push(std::make_pair(!now.first, to[now.second][i]));
                }
        }
    }
    return 0;
}