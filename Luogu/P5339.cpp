//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define int long long
#define double long double
const int INF = 0x3fffffffffffffff;
const double eps = 0.0000000000001;
const double PI = acos(-1);
const int MOD = 998244353;
int n, a[5], dp[5][1005], fact[1005], finv[1005], ans;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int C(int N, int M)
{
    if (M < 0 || N < M)
        return 0;
    return fact[N] * finv[M] % MOD * finv[N - M] % MOD;
}
int &add(int &A, int B)
{
    return A = (A + B % MOD + MOD) % MOD;
}
int aaaa[10005], l[5];
std::vector<std::string> wrong;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= 4; ++i)
    {
        std::cin >> a[i];
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    finv[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
    {
        finv[i] = finv[i + 1] * (i + 1) % MOD;
    }
    for (int l = 0; l <= *std::min_element(a + 1, a + 5); ++l)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 0; j <= n - l * 4; ++j)
            {
                for (int k = 0; k <= a[i] - l; ++k)
                {
                    if (j + k > n - l * 4)
                        break;
                    add(dp[i][j + k], dp[i - 1][j] * C(j + k, k));
                }
            }
        }
        add(ans, (l & 1 ? -1 : 1) * dp[4][n - l * 4] * C((n - l * 4) + l, l));
    }
    std::cout << ans << std::endl;
    return 0;
}
