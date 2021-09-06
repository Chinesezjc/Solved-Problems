// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, m, fact[400005], ifact[400005], nxt[200005], ans;
std::vector<int> p;
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
int C(int n, int m) { return 0 <= n && n <= m ? 1ll * fact[m] * ifact[n] % MOD * ifact[m - n] % MOD : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 2; i <= m; ++i)
    {
        if (!nxt[i])
        {
            nxt[i] = i;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > m)
                break;
            nxt[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n + m; ++i)
        ifact[i] = power(fact[i] = 1ll * fact[i - 1] * i % MOD, MOD - 2);
    for (int i = 1; i <= m; ++i)
    {
        int way = 1;
        for (int j = i; j > 1;)
        {
            int tim = 0;
            for (int k = nxt[j]; j % k == 0; j /= k)
                ++tim;
            way = 1ll * way * C(tim, n + tim - 1) % MOD;
        }
        ans = (ans + way) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}