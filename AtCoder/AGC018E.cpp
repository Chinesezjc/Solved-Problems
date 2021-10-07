// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
int x[6], y[6];
typedef atcoder::modint1000000007 mint;
mint fact[2000005], ifact[2000005], ans;
mint C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] * ifact[n - m] : 0; }
mint S(int n, int m) { return C(n + m + 2, n + 1); }
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 6; ++i)
        std::cin >> x[i];
    for (int i = 0; i != 6; ++i)
        std::cin >> y[i];
    ++x[1], ++y[1];
    --x[4], --y[4];
    fact[0] = 1;
    for (int i = 1; i <= 2000000; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[2000000] = fact[2000000].inv();
    for (int i = 2000000; i; --i)
        ifact[i - 1] = ifact[i] * i;
    for (int i = x[2]; i <= x[3]; ++i)
        ans += (i + y[3] + 1) *
               (S(i - x[0], y[3] - y[0]) -
                S(i - x[0], y[3] - y[1]) -
                S(i - x[1], y[3] - y[0]) +
                S(i - x[1], y[3] - y[1])) *
               (S(x[5] - i, y[5] - y[3] - 1) -
                S(x[5] - i, y[4] - y[3] - 1) -
                S(x[4] - i, y[5] - y[3] - 1) +
                S(x[4] - i, y[4] - y[3] - 1));
    for (int i = y[2]; i <= y[3]; ++i)
        ans += (x[3] + i + 1) *
               (S(x[3] - x[0], i - y[0]) -
                S(x[3] - x[0], i - y[1]) -
                S(x[3] - x[1], i - y[0]) +
                S(x[3] - x[1], i - y[1])) *
               (S(x[5] - x[3] - 1, y[5] - i) -
                S(x[5] - x[3] - 1, y[4] - i) -
                S(x[4] - x[3] - 1, y[5] - i) +
                S(x[4] - x[3] - 1, y[4] - i));
    for (int i = x[2]; i <= x[3]; ++i)
        ans -= (i + y[2]) *
               (S(i - x[0], y[2] - 1 - y[0]) -
                S(i - x[0], y[2] - 1 - y[1]) -
                S(i - x[1], y[2] - 1 - y[0]) +
                S(i - x[1], y[2] - 1 - y[1])) *
               (S(x[5] - i, y[5] - y[2]) -
                S(x[5] - i, y[4] - y[2]) -
                S(x[4] - i, y[5] - y[2]) +
                S(x[4] - i, y[4] - y[2]));
    for (int i = y[2]; i <= y[3]; ++i)
        ans -= (x[2] + i) *
               (S(x[2] - 1 - x[0], i - y[0]) -
                S(x[2] - 1 - x[0], i - y[1]) -
                S(x[2] - 1 - x[1], i - y[0]) +
                S(x[2] - 1 - x[1], i - y[1])) *
               (S(x[5] - x[2], y[5] - i) -
                S(x[5] - x[2], y[4] - i) -
                S(x[4] - x[2], y[5] - i) +
                S(x[4] - x[2], y[4] - i));
    std::cout << ans.val() << std::endl;
    return 0;
}