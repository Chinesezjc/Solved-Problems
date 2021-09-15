// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long long MOD = 998244353;
const long long inv100 = 828542813;
int n, dp[2][100005], lst[26];
long long a[100005], pow100[100005];
char c[100005];
long long power(int x, int y) { return y ? power(x, y - 1) * x % MOD : 1; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], a[i] = 100 - a[i];
    pow100[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow100[i] = pow100[i - 1] * 100 % MOD;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = ((dp[0][i - 1] + dp[1][i - 1] -
                     dp[1][lst[c[i] - 'a']] * pow100[i - lst[c[i] - 'a'] - 1] % MOD + MOD) *
                    100) %
                   MOD;
        dp[1][i] = ((dp[0][i - 1] + dp[1][i - 1]) * a[i] +
                    dp[1][lst[c[i] - 'a']] * pow100[i - lst[c[i] - 'a'] - 1] % MOD * (100 - a[i]) % MOD) %
                   MOD;
        lst[c[i] - 'a'] = i;
    }
    std::cout << (dp[0][n] + dp[1][n]) * power(inv100, n) % MOD << std::endl;
    return 0;
}