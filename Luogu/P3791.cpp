// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
long long n, m, x;
int ans;
std::map<long long, int> map;
int pre(long long x)
{
    --x;
    if (map.count(x))
        return map[x];
    long long l = 1, r;
    int res = 0;
    while (l <= x)
    {
        r = x / (x / l);
        res = (res + x / l * (r - l + 1ll)) % MOD;
        l = r + 1;
    }
    return map[x] = res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> x;
    ++n;
    ++m;
    for (int i = 0; 1ll << i <= n; ++i)
        if (n >> i & 1)
            for (int j = 0; 1ll << j <= m; ++j)
                if (m >> j & 1)
                {
                    int k = std::max(i, j);
                    int l = std::min(i, j);
                    int tmp = pre((((n ^ 1ll << i ^ m ^ 1ll << j ^ x) >> k) + 1) << k) -
                              pre((((n ^ 1ll << i ^ m ^ 1ll << j ^ x) >> k) + 0) << k);
                    if (tmp < 0)
                        tmp += MOD;
                    ans = (ans + (1ll << l) % MOD * tmp) % MOD;
                }
    std::cout << ans << std::endl;
    return 0;
}