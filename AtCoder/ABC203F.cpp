//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
const int INF = 0x3fffffffffffffff;
const double PI = acos(-1);
const double eps = 1e-13;
int n, k, a[200005], dp[35][200005];
int c(int x) { return x >= 1e9 ? -1 : x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a + 1, a + 1 + n, std::greater<int>());
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int to = std::lower_bound(a + 1, a + 1 + n, a[i + 1] / 2, std::greater<int>()) - a - 1;
        // std::cout<<to<<std::endl;
        for (int j = 0; j != 32; ++j)
        {
            dp[j][i + 1] = std::min(dp[j][i + 1], dp[j][i] + 1);
            dp[j + 1][to] = std::min(dp[j + 1][to], dp[j][i]);
        }
        // for(int j=0;j!=32;++j)
        //     std::cout<<c(dp[j][i])<<" \n"[j+1==32];
    }
    for (int i = 0; i != 32; ++i)
        if (dp[i][n] <= k)
            return std::cout << i << ' ' << dp[i][n] << std::endl, 0;
    return 0;
}