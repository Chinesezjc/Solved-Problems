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
const int INF = 0x3fffffff;
int n, m, k, s[100005], f[23][23], popcount[1 << 23], rk[1 << 23], dp[1 << 23], g[2][23][1352078], lg[1 << 23];
bool now = true, lst = false;
std::vector<int> t[24];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 0; i != n; ++i)
        std::cin >> s[i];
    for (int i = 1; i != n; ++i)
        ++f[s[i - 1] - 1][s[i] - 1];
    for (int i = 1; i != 1 << m; ++i)
    {
        popcount[i] = popcount[i & (i - 1)] + 1;
        rk[i] = t[popcount[i]].size();
        t[popcount[i]].push_back(i);
    }
    std::fill(dp + 1, dp + (1 << m), INF);
    for (int i = 0; i != m; ++i)
        for (int j = 0; j != m; ++j)
            if (i ^ j)
                g[lst][i][rk[1 << i]] += k * f[j][i] - f[i][j];
    for (int i = 0; i != m; ++i)
        dp[1 << i] = g[lst][i][rk[1 << i]];
    for (int i = 0; i != m; ++i)
        lg[1 << i] = i;
    for (int i = 0; i != 1 << m; ++i)
        lg[i] = lg[i & -i];
    for (int i = 2; i <= m; ++i, std::swap(now, lst))
        for (int j = 0; j != (int)t[i].size(); ++j)
            for (int l = 0; l != m; ++l)
            {
                if (t[i][j] & (1 << l))
                {
                    g[now][l][j] = g[lst][l][rk[t[i][j] ^ (1 << lg[t[i][j] ^ (1 << l)])]] +
                                   (1 + k) * f[l][lg[t[i][j] ^ (1 << l)]] + (1 - k) * f[lg[t[i][j] ^ (1 << l)]][l];
                    // std::cout << l << ' ' << std::bitset<3>(t[i][j]) << ' ' << g[now][l][j] << std::endl;
                    if (g[now][l][j] < INF / 2)
                        dp[t[i][j]] = std::min(dp[t[i][j]], dp[t[i][j] ^ (1 << l)] + i * g[now][l][j]);
                }
                else
                    g[now][l][j] = INF;
            }
    std::cout << dp[(1 << m) - 1] << std::endl;
    return 0;
}