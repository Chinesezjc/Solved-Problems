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
const char color[4] = {'R', 'Y', 'G', 'B'};
const int xx[] = {0, 1, 0, -1},
          yy[] = {1, 0, -1, 0};
int n, m, d;
std::map<int, std::map<int, int>> ans;
void paint(int X, int Y, int len, int color)
{
    len /= 2;
    for (int i = 0; i < len; ++i)
        for (int j = -i; j <= i; ++j)
            if (X + j > 0 && X + j <= n && Y + i > 0 && Y + i <= m)
                ans[X + j][Y + i] = color;
    Y += len - 1;
    for (int i = 1; i <= len; ++i)
        for (int j = -len + i; j <= len - i; ++j)
            if (X + j > 0 && X + j <= n && Y + i > 0 && Y + i <= m)
                ans[X + j][Y + i] = color;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> d;
    if (d & 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                std::cout << color[(i + j) & 1];
            }
            std::cout << std::endl;
        }
        return 0;
    }
    for (int i = -d * 3; i <= n + d * 3; i += d + d)
    {
        for (int j = -d * 3; j <= m + d * 3; j += d + d)
            paint(i, j, d, 1);
    }
    for (int i = -d * 3; i <= n + d * 3; i += d + d)
    {
        for (int j = -d * 3 + d; j <= m + d * 3; j += d + d)
            paint(i, j, d, 2);
    }
    for (int i = -d * 3 + d / 2; i <= n + d * 3; i += d + d)
    {
        for (int j = -d * 3 + d / 2; j <= m + d * 3; j += d + d)
            paint(i, j, d, 3);
    }
    for (int i = -d * 3 + d; i <= n + d * 3; i += d + d)
    {
        for (int j = -d * 3 + d; j <= m + d * 3; j += d + d)
            paint(i, j, d, 1);
    }
    for (int i = -d * 3 + d; i <= n + d * 3; i += d + d)
    {
        for (int j = -d * 3 + d + d; j <= m + d * 3; j += d + d)
            paint(i, j, d, 2);
    }
    for (int i = -d * 3 + d / 2 + d; i <= n + d * 3; i += d + d)
    {
        for (int j = -d * 3 + d / 2 + d; j <= m + d * 3; j += d + d)
            paint(i, j, d, 3);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cout << color[ans[i][j]];
        }
        std::cout << std::endl;
    }
    return 0;
}