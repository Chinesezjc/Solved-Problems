// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint1000000007 mint;
int n, c[200005];
mint pow2[200005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> c[i];
    std::sort(c, c + n);
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = pow2[i - 1] * 2;
    if (n == 1)
        std::cout << mint(2 * c[0]).val() << std::endl, exit(0);
    for (int i = 0; i != n; ++i)
        ans += (pow2[n] * pow2[n - 2] * (n - i - 1) + pow2[n] * pow2[n - 1]) * c[i];
    std::cout << ans.val() << std::endl;
    return 0;
}