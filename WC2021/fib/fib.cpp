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
int dp[1005][1005], n, m, a, b;
int dfs(int i, int j)
{
    if (~dp[i][j])
        return dp[i][j];
    if (i == 0)
        return dp[i][j] = 0;
    if (j == a && (i + j) % m == b)
        return dp[i][j] = INF;
    return dp[i][j] = dfs(j, (i + j) % m) + 1;
}
signed boom()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a >> b;
        std::cout << (dfs(a, b) >= INF ? -1 : dfs(a, b)) << std::endl;
    }
    return 0;
}
signed main()
{
    // freopen("fib.in", "r", stdin);
    // freopen("fib.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (n <= 1000 && m <= 1000)
    {
        return boom();
    }
    return 0;
}