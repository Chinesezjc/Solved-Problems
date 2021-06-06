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
int n, m, N, a[35], ipw[35][905], C[905][905], dp[905][905], finv[905], fact[905];
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
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = n; j; --j)
            for (int k = 0; k < a[i]; ++k)
                for (int l = k; l <= N; ++l)
                    dp[j][l] = (dp[j][l] + dp[j - 1][l - k] * C[l][k]) % MOD;
    for (int i = 1; i <= n; ++i)
    {
        static int tmp[905][905];
        memcpy(tmp, dp, sizeof(dp));
        for (int j = 1; j <= n; ++j)
            for (int k = 0; k < a[i]; ++k)
                for (int l = k; l <= N; ++l)
                    tmp[j][l] = (tmp[j][l] + tmp[j - 1][l - k] * (MOD - C[l][k])) % MOD;
        int ans = 0;
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= N; ++k)
                ans += (j & 1 ? MOD - 1 : 1) * tmp[j][k] % MOD *
                       C[k + a[i] - 1][a[i] - 1] % MOD * ipw[j + 1][k + a[i]] % MOD;
        std::cout << ans % MOD << " \n"[i == n];
    }
    return 0;
}