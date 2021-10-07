// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
const long long inv2 = (MOD + 1) / 2;
int m, cnt[1 << 19];
long long n;
int power(int A, long long B)
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
    std::cin >> n >> m;
    for (int i = 0; 1 << i <= m; ++i)
        for (int j = 0; j != 1 << i && (1 << i | j) <= m; ++j)
            ++cnt[j + 1];
    for (int i = 0; i != 19; ++i)
        for (int j = 1 << i; j < 1 << 19; j = (j + 1) | 1 << i)
        {
            int A = cnt[j ^ 1 << i], B = cnt[j];
            cnt[j ^ 1 << i] = (A + B) % MOD;
            cnt[j] = (A - B + MOD) % MOD;
        }
    for (int i = 0; i != 1 << 19; ++i)
        cnt[i] = power(cnt[i], n);
    for (int i = 0; i != 19; ++i)
        for (int j = 1 << i; j < 1 << 19; j = (j + 1) | 1 << i)
        {
            int A = cnt[j ^ 1 << i], B = cnt[j];
            cnt[j ^ 1 << i] = (A + B) * inv2 % MOD;
            cnt[j] = (A - B) * inv2 % MOD;
        }
    std::cout << (power(m, n) - cnt[0] + MOD) % MOD << std::endl;
    return 0;
}