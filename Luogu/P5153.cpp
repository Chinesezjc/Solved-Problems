// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
unsigned long long n, p[50], f[50], cnt[50], ans = 1;
unsigned long long power(unsigned long long A, unsigned long long B)
{
    unsigned long long res = 1;
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
    f[2] = 1;
    for (int i = 3; i != 50; ++i)
        for (int j = 1; j <= i; ++j)
            if (i % j)
            {
                f[i] = f[j] + 1;
                break;
            }
    for (unsigned long long i = 1, j = 1; i <= 43; ++i)
        p[i] = j = i / std::__gcd(i, j) * j;
    for (int i = 1; i < 43; ++i)
        cnt[i + 1] = n / p[i] - n / p[i + 1];
    --cnt[2];
    --cnt[3];
    for (int i = 2; i != 50; ++i)
        ans = ans * power(f[i] + 1, cnt[i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}