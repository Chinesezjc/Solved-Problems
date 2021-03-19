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
const int block = 1 << 16;
int n, m, ans, endx, endy;
char c[15][15];
std::vector<std::pair<int, int>> dp[2][block];
bool now = true, lst = false;
void add(bool f, int c, int v)
{
    int b = c % block;
    for (int i = 0; i < dp[f][b].size(); ++i)
    {
        if (dp[f][b][i].first == c)
        {
            dp[f][b][i].second += v;
            return;
        }
    }
    dp[f][b].push_back(std::make_pair(c, v));
}
int update(int now)
{
    int res = 0, cnt = 0;
    for (int i = 0; i <= m; ++i)
    {
        int tmp = now >> (i * 3) & 7;
        if (tmp)
        {
            ++cnt;
            for (int j = i; j <= m; ++j)
            {
                if ((now >> (j * 3) & 7) == tmp)
                {
                    res ^= cnt << (j * 3);
                    now ^= tmp << (j * 3);
                }
            }
        }
    }
    return res;
}
int replace(int now, int from, int to)
{
    for (int i = 0; i <= m; ++i)
        if ((now >> (i * 3) & 7) == from)
            now ^= (from ^ to) << (i * 3);
    return now;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
#ifdef debug
    std::cout << std::oct;
#endif
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            std::cin >> c[i][j];
            if (c[i][j] == '.')
            {
                endx = i;
                endy = j;
            }
        }
    dp[now][0].push_back(std::make_pair(0, 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::swap(now, lst);
            for (int k = 0; k < block; ++k)
                dp[now][k].clear();
            for (int k = 0; k < block; ++k)
                for (int l = 0; l < dp[lst][k].size(); ++l)
                {
                    int L = dp[lst][k][l].first >> (j * 3) & 7, U = dp[lst][k][l].first >> (j * 3 + 3) & 7;
                    int e = dp[lst][k][l].first ^ (L << (j * 3)) ^ (U << (j * 3 + 3));
                    switch (c[i][j])
                    {
                    case '*':
                        if (!L && !U)
                        {
                            add(now, update(e), dp[lst][k][l].second);
                        }
                        break;
                    case '.':
                        if (!L && !U)
                        {
                            if (c[i + 1][j] == '.' && c[i][j + 1] == '.')
                                add(now, update(e | 7ll << (j * 3) | 7ll << (j * 3 + 3)), dp[lst][k][l].second);
                        }
                        if (!L && U)
                        {
                            if (c[i + 1][j] == '.')
                                add(now, update(e | U << (j * 3)), dp[lst][k][l].second);
                            if (c[i][j + 1] == '.')
                                add(now, update(e | U << (j * 3 + 3)), dp[lst][k][l].second);
                        }
                        if (L && !U)
                        {
                            if (c[i + 1][j] == '.')
                                add(now, update(e | L << (j * 3)), dp[lst][k][l].second);
                            if (c[i][j + 1] == '.')
                                add(now, update(e | L << (j * 3 + 3)), dp[lst][k][l].second);
                        }
                        if (L && U)
                        {
                            if (L == U && i == endx && j == endy)
                                add(now, update(e), dp[lst][k][l].second);
                            if (L != U)
                                add(now, update(replace(e, U, L)), dp[lst][k][l].second);
                        }
                        break;
                    }
                }
#ifdef debug
            std::cout << i << ' ' << j << std::endl;
            for (int k = 0; k < block; ++k)
                for (int l = 0; l < dp[now][k].size(); ++l)
                    std::cout << dp[now][k][l].first << ' ' << dp[now][k][l].second << std::endl;
            std::cout << std::endl;
#endif
        }
        std::swap(now, lst);
        for (int k = 0; k < block; ++k)
            dp[now][k].clear();
        for (int k = 0; k < block; ++k)
            for (int l = 0; l < dp[lst][k].size(); ++l)
                if (!(dp[lst][k][l].first & 7ll << (m * 3)))
                    add(now, dp[lst][k][l].first << 3, dp[lst][k][l].second);
#ifdef debug
        std::cout << "end " << i << std::endl;
        for (int k = 0; k < block; ++k)
            for (int l = 0; l < dp[now][k].size(); ++l)
                std::cout << dp[now][k][l].first << ' ' << dp[now][k][l].second << std::endl;
        std::cout << std::endl;
#endif
    }
    for (int k = 0; k < block; ++k)
        for (int l = 0; l < dp[now][k].size(); ++l)
            if (!dp[now][k][l].first)
                ans += dp[now][k][l].second;
    std::cout << ans << std::endl;
    return 0;
}