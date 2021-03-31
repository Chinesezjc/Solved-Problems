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
const int MOD = 1000000007;
int n, k, fa[100005], siz[100005];
unsigned dp[100005][105][2][2];
//The first one means the root is protected.
//The second one means the root is lighted.
std::vector<int> son[100005];
inline void add(unsigned &A, const int &B) { A = (A + B) % MOD; }
void dfs(int u)
{
    siz[u] = 1;
    dp[u][0][0][0] = 1;
    dp[u][1][0][1] = 1;
    for (int i = 0; i != (int)son[u].size(); ++i)
    {
        if (fa[u] == son[u][i])
        {
            std::swap(son[u][i--], son[u].back());
            son[u].pop_back();
            continue;
        }
        fa[son[u][i]] = u;
        dfs(son[u][i]);
        static unsigned DP[105][2][2];
        memcpy(DP, dp[u], sizeof(DP));
        memset(dp[u], 0, sizeof(DP));
        for (int j = 0; j <= siz[u] && j <= k; ++j)
            for (int l = 0; l <= siz[son[u][i]] && j + l <= k; ++l)
                for (int o = 0; o != 2; ++o)
                    for (int q = 0; q != 2; ++q)
                        for (int r = 0; r != 2; ++r)
                        {
                            // dp[u][j][o][0] && dp[son[u][i]][l][q][r]
                            if (q)
                                add(dp[u][j + l][o || r][0], 1ll * DP[j][o][0] * dp[son[u][i]][l][q][r]);
                            // dp[u][j][o][1] && dp[son[u][l]][l][q][r]
                            add(dp[u][j + l][o || r][1], 1ll * DP[j][o][1] * dp[son[u][i]][l][q][r]);
                        }
        siz[u] += siz[son[u][i]];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs(1);
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 0; j <= std::min(siz[i], k); ++j)
    //         std::cout << "{{" << dp[i][j][0][0] << ',' << dp[i][j][0][1] << "},{" << dp[i][j][1][0] << ',' << dp[i][j][1][1] << "}}";
    //     std::cout << std::endl;
    // }
    std::cout << (dp[1][k][1][0] + dp[1][k][1][1]) % MOD << std::endl;
    return 0;
}