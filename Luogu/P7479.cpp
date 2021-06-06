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
const int xx[] = {0, -1, 0, +1},
          yy[] = {-1, 0, +1, 0};
int n, m, ans, T;
bool o[2005][2005];
std::pair<int, int> fa[2005][2005];
char c[2005][2005];
std::pair<int, int> find(std::pair<int, int> now)
{
    return fa[now.first][now.second] == now ? now : fa[now.first][now.second] = find(fa[now.first][now.second]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 0; i <= n + 1; ++i)
            for (int j = 0; j <= m + 1; ++j)
                o[i][j] = false;
        for (int i = 0; i <= n + 1; ++i)
            for (int j = 0; j <= m + 1; ++j)
                c[i][j] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> c[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '*')
                    for (int k = 0; k != 4; ++k)
                        if (c[i + xx[k]][j + yy[k]] == '.')
                            c[i + xx[k]][j + yy[k]] = '@';
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                fa[i][j] = std::make_pair(i, j);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '@')
                    for (int k = 0; k != 2; ++k)
                        if (c[i + xx[k]][j + yy[k]] == '@')
                            fa[find(std::make_pair(i, j)).first][find(std::make_pair(i, j)).second] =
                                find(std::make_pair(i + xx[k], j + yy[k]));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '@')
                    for (int k = 0; k != 4; ++k)
                        if (c[i + xx[k]][j + yy[k]] == '.')
                            o[find(std::make_pair(i, j)).first][find(std::make_pair(i, j)).second] = true;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (std::make_pair(i, j) == find(std::make_pair(i, j)) && !o[i][j] && c[i][j] == '@')
                    ++ans;
#ifdef debug
        for (int i = 1; i <= n; ++i, std::cout << std::endl)
            for (int j = 1; j <= m; ++j)
                std::cout << fa[i][j].first << ',' << fa[i][j].second << ' ';
        for (int i = 1; i <= n; ++i, std::cout << std::endl)
            for (int j = 1; j <= m; ++j)
                std::cout << c[i][j];
        std::cout << ans << std::endl;
#endif
        std::cout << (ans < 2 ? "NO" : "YES") << std::endl;
    }
    return 0;
}