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
int n, m, k, g1, g2, g3, dp[100005][55], ans;
char c[100005];
std::vector<int> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> g1 >> g2 >> g3 >> (c + 1);
    m = std::count(c + 1, c + 1 + n, '#');
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            if (!~dp[i][j])
                continue;
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
            if (c[i + 1] == '.' && c[i + 2] == '.')
                dp[i + 2][j] = std::max(dp[i + 2][j], dp[i][j] + 1);
            if (c[i + 1] == '.' && c[i + 2] == '#' && c[i + 3] == '.')
                dp[i + 3][j + 1] = std::max(dp[i + 3][j + 1], dp[i][j]);
        }
    for (int i = 0; i <= m; ++i)
    {
        if (!~dp[n][i])
            continue;
        int t1 = std::min(k, n - m - i * 2 - dp[n][i] * 2), t2 = dp[n][i], t3 = i;
        if (g1 * 2 > g2)
            while (k - t1 >= 2 && t2)
            {
                --t2;
                ++t1;
                ++t1;
            }
        if (g1 > g2)
            while (k - t1 >= 1 && t2)
            {
                --t2;
                ++t1;
            }
        ans = std::max(ans, g1 * t1 + g2 * t2 + g3 * t3);
    }
    std::cout << ans << std::endl;
    return 0;
}