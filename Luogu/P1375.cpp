// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int fact[200005], n;
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
    fact[0] = 1;
    for (int i = 1; i <= 2 * n; ++i)
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    std::cout << 1ll * fact[2 * n] * power(1ll * fact[n] * fact[n + 1] % MOD, MOD - 2) % MOD << std::endl;
    return 0;
}