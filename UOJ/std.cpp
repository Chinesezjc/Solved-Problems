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
const int MOD = 998244353;
int n, m, N, a[35], ipw[35][905], C[905][905], dp[1 << 10][905],
    finv[905], fact[905], lowbit[1 << 10], popcount[1 << 10];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        m = std::max(a[i], m);
        N += a[i];
    }
    for (int i = 1, j, inv; i <= n; ++i)
        for (ipw[i][0] = 1, inv = i == 1 ? 1 : (MOD - MOD / i) * ipw[MOD % i][1] % MOD, j = 1; j <= N; ++j)
            ipw[i][j] = ipw[i][j - 1] * inv % MOD;
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    finv[N] = power(fact[N], MOD - 2);
    for (int i = N; i; --i)
        finv[i - 1] = finv[i] * i % MOD;
    for (int i = 0; i <= N; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        C[i][i] = 1;
    }
    for (int i = 0; i != n; ++i)
        lowbit[1 << i] = i;
    for (int i = 1; i != 1 << n; ++i)
        lowbit[i] = lowbit[i & -i], popcount[i] = popcount[i & (i - 1)] + 1;
    for (int i = 1; i <= n; ++i)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][a[i] - 1] = 1;
        for (int j = 1; j != 1 << n; ++j)
            if (~j & 1 << i >> 1)
                for (int l = 0; l < a[lowbit[j] + 1]; ++l)
                    for (int k = l; k <= N; ++k)
                        dp[j][k] = (dp[j][k] + dp[j & (j - 1)][k - l] * C[k][l]) % MOD;
        int ans = 0;
        for (int j = 0; j != 1 << n; ++j)
            for (int k = 0, pop; k <= N; ++k)
                std::cout << dp[j][k] << " \n"[k == N],
                    pop = popcount[j], ans = (ans + (pop & 1 ? MOD - 1 : 1) * dp[j][k] % MOD * ipw[pop + 1][k + 1]) % MOD;
        std::cout << ans << " \n"[i == n];
    }
    return 0;
}