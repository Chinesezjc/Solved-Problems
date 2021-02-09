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
int n, m, k, fa[300005], ans;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
std::vector<std::pair<int, int> /**/> to[300005];
std::queue<std::pair<int, int> /**/> que;
signed main()
{
    // freopen("bracket.in", "r", stdin);
    // freopen("bracket.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        to[b].push_back(std::make_pair(c, a));
    }
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        que.push(std::make_pair(i, i));
    }
    while (!que.empty())
    {
        std::pair<int, int> now = que.front();
        que.pop();
        for (int i = 0; i != to[now.first].size(); ++i)
        {
            for (int j = 0; j != to[now.second].size(); ++j)
            {
                if (to[now.first][i].first == to[now.second][j].first)
                {
                    int A = find(to[now.first][i].second), B = find(to[now.second][j].second);
                    if (A == B)
                        continue;
                    std::vector<int> a, b;
                    for (int l = 1; l <= n; ++l)
                    {
                        if (find(l) == A)
                            a.push_back(l);
                        if (find(l) == B)
                            b.push_back(l);
                    }
                    for (int l = 0; l != a.size(); ++l)
                        for (int o = 0; o != b.size(); ++o)
                            que.push(std::make_pair(a[l], b[o]));
                    fa[A] = B;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (find(i) == find(j))
                ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}