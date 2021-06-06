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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, MOD, dp[805][805], ldp[805][805], ans, fact[805], inv[805], pow2[805], C[808][808];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> MOD;
    for (int i = C[0][0] = 1; i <= n; i++)
        for (int j = C[i][0] = 1; j <= n; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    pow2[1] = 1;
    for (int i = 2; i <= n << 1; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][i] = pow2[i];
        std::cout << dp[i][i] << ' ';
        for (int j = 1; j <= i - 1; ++j)
        {
            for (int k = 1; k <= std::min(i - 2, j - 1); ++k)
                dp[i][j] = (dp[i][j] + dp[i - k - 1][j - k] * C[j][k] % MOD * pow2[k]) % MOD;
            std::cout << dp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    for (int i = 1; i <= n; ++i)
        ans = (ans + dp[n][i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}