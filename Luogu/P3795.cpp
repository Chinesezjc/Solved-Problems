// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 14233333;
const long long inv2 = (MOD + 1) / 2;
int n, ans, ifact[5000005];
int fact(int x)
{
    int res = 1;
    for (int i = 1; i <= x; ++i)
        res = 1ll * res * i % MOD;
    return res;
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    ifact[n >> 1] = power(fact(n >> 1), MOD - 2);
    for (int i = n >> 1; i; --i)
        ifact[i - 1] = 1ll * ifact[i] * i % MOD;
    int tmp = fact(n);
    for (int i = 0, j = power(tmp, MOD - 2);
         i <= n >> 1;
         j = j * inv2 % MOD * (n - 2 * i) % MOD * (n - 2 * i - 1) % MOD, ++i)
        ans = (ans + 1ll * ifact[i] * j) % MOD;
    std::cout << 1ll * tmp * ans % MOD << std::endl;
    return 0;
}