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
std::vector<int> g[55];
int c[100005], dis[100005][2], n, m;
bool can[55][55];
char nmsl;
struct node
{
    int v, p;
    bool stoped;
    bool operator>(const node &val) const { return v > val.v; }
};
std::priority_queue<node, std::vector<node>, std::greater<node>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> c[i];
        g[c[i]].push_back(i);
        dis[i][0] = dis[i][1] = INF;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> nmsl;
            can[i][j] = nmsl == '1';
        }
    }
    dis[1][1] = 0;
    que.push({0, 1, true});
    while (!que.empty())
    {
        node now = que.top();
        que.pop();
        if (now.v != dis[now.p][now.stoped])
            continue;
        if (now.stoped)
        {
            for (int i = 1; i <= m; ++i)
            {
                if (can[c[now.p]][i])
                {
                    std::vector<int>::iterator nxt = std::upper_bound(g[i].begin(), g[i].end(), now.p);
                    if (nxt != g[i].end() && dis[*nxt][0] > now.v + *nxt - now.p)
                        que.push({dis[*nxt][0] = now.v + *nxt - now.p, *nxt, false});
                    std::vector<int>::iterator lst = std::lower_bound(g[i].begin(), g[i].end(), now.p);
                    if (lst-- != g[i].begin() && dis[*lst][0] > now.v + now.p - *lst)
                        que.push({dis[*lst][0] = now.v + now.p - *lst, *lst, false});
                }
            }
        }
        else
        {
            if (now.v < dis[now.p][1])
                que.push({dis[now.p][1] = now.v, now.p, true});
            std::vector<int>::iterator nxt = std::upper_bound(g[c[now.p]].begin(), g[c[now.p]].end(), now.p);
            if (nxt != g[c[now.p]].end() && dis[*nxt][0] > now.v + *nxt - now.p)
                que.push({dis[*nxt][0] = now.v + *nxt - now.p, *nxt, false});
            std::vector<int>::iterator lst = std::lower_bound(g[c[now.p]].begin(), g[c[now.p]].end(), now.p);
            if (lst-- != g[c[now.p]].begin() && dis[*lst][0] > now.v + now.p - *lst)
                que.push({dis[*lst][0] = now.v + now.p - *lst, *lst, false});
        }
    }
    std::cout << (dis[n][1] == INF ? -1 : dis[n][1]) << std::endl;
    return 0;
}