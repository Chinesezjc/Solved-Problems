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
int T, n, a[100005], dp[100005][3][3][3];
void max(int &A, int B) { return void(A < B ? A = B : 0); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        memset(dp, 0xf0, sizeof(dp));
        dp[0][0][0][0] = 0;
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        for (int b = -1; b <= 1; ++b)
                            max(dp[i + 1][std::max(0ll, j + b)][std::max(0ll, k + (i & 1 ? 0 : b))][std::max(0ll, l + (i & 1 ? b : 0))], dp[i][j][k][l] + a[i + 1] * b);
        int ans = 0;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    max(ans, dp[n][i][j][k]);
        std::cout << ans << std::endl;
    }
    return 0;
}