// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
typedef atcoder::modint998244353 mint;
// #define debug
mint fact[1000005], ifact[1000005], ans;
int n, m;
mint C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] * ifact[n - m] : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    ifact[0] = fact[0] = 1;
    for (int i = 1; i <= n + m; ++i)
        ifact[i] = (fact[i] = fact[i - 1] * i).inv();
    if (n > m)
        std::swap(n, m);
    for (int i = 1; i <= n; ++i)
        ans += C(2 * i, i) * C(n + m - 2 * i, n - i);
    ans *= (C(n + m, n) * 2).inv();
    ans += m;
    std::cout << ans.val() << std::endl;
    return 0;
}