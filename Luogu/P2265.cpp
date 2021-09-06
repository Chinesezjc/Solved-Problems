// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
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
int fact(int x) { return x ? 1ll * fact(x - 1) * x % MOD : 1; }
int n, m;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    std::cout << 1ll * fact(n + m) * power(1ll * fact(n) * fact(m) % MOD, MOD - 2) % MOD << std::endl;
    return 0;
}