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
struct edge
{
    int x, y, a, b;
    friend bool operator<(const edge &A, const edge &B) { return A.a < B.a; }
} e[100005];
int dis[50005], ans = INF;
size_t n, m;
std::vector<edge> to[50005];
std::vector<int> val;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (size_t i = 0; i != m; ++i)
    {
        std::cin >> e[i].x >> e[i].y >> e[i].a >> e[i].b;
        val.push_back(e[i].a);
    }
    std::sort(e, e + m);
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());
    std::fill(dis + 2, dis + 1 + n, INF);
    for (size_t i = 0, j = 0; i != val.size(); ++i)
    {
        while (j != m && e[j].a == val[i])
        {
            to[e[j].x].push_back(edge{e[j].x, e[j].y, e[j].a, e[j].b});
            to[e[j].y].push_back(edge{e[j].y, e[j].x, e[j].a, e[j].b});
            if (dis[e[j].y] > std::max(dis[e[j].x], e[j].b))
                que.push(std::make_pair(dis[e[j].y] = std::max(dis[e[j].x], e[j].b), e[j].y));
            if (dis[e[j].x] > std::max(dis[e[j].y], e[j].b))
                que.push(std::make_pair(dis[e[j].x] = std::max(dis[e[j].y], e[j].b), e[j].x));
            ++j;
        }
        while (!que.empty())
        {
            int now = que.top().second;
            que.pop();
            for (size_t i = 0; i != to[now].size(); ++i)
            {
                if (dis[to[now][i].y] > std::max(dis[now], to[now][i].b))
                    que.push(std::make_pair(dis[to[now][i].y] = std::max(dis[now], to[now][i].b), to[now][i].y));
            }
        }
        ans = std::min(ans, val[i] + dis[n]);
    }
    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}