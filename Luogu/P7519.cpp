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
int n, m, a[20], dp[13][505][1 << 13], rk1, ans, popcount[1 << 13];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    rk1 = std::max_element(a, a + n) - a;
    for (int i = 0; i != n; ++i)
        dp[i][(a[rk1] - a[i] + (i > rk1)) * n][1 << i] = 1;
    for (int i = 1; i != 1 << n; ++i)
        popcount[i] = popcount[i & (i - 1)] + 1;
    for (int k = 0; k != 1 << n; ++k)
        for (int i = 0; i != n; ++i)
            for (int j = 0; j <= m; ++j)
                if (k & 1 << i && dp[i][j][k])
                    for (int l = 0; l != n; ++l)
                        if (!(k & 1 << l) && j + std::max(0ll, a[i] - a[l] + (l > i)) * (n - popcount[k]) <= m)
                            dp[l][j + std::max(0ll, a[i] - a[l] + (l > i)) * (n - popcount[k])][k | 1 << l] +=
                                dp[i][j][k];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j <= m; ++j)
            ans += dp[i][j][(1 << n) - 1];
    std::cout << ans << std::endl;
    return 0;
}