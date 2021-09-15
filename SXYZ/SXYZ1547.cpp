// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int A, B, K, MOD;
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
int S(int x) { return std::min(x, MOD - x); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B >> K;
    MOD = A + B;
    std::cout << S(1ll * A * power(2, K) % MOD) << std::endl;
    return 0;
}