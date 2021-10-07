// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint998244353 mint;
int n, d;
mint c[2000005], pw[2000005], ans;
void add(int l, int r, mint v)
{
    c[l] += v;
    c[r + 1] -= v;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d;
    pw[0] = 1;
    for (int i = 1; i <= 2 * n; ++i)
        pw[i] = pw[i - 1] * 2;
    for (int i = 0; i != n; ++i)
    {
        if (i + d < n)
            add(d, d, pw[i]);
        if (i + n - 1 >= d)
            add(std::max(0, d - i - 1), std::min(d - 2, (n - 3 + d - i) / 2), pw[i]);
        if (i >= d)
            add(0, 0, pw[i]);
    }
    for (int i = 0; i <= 2 * n; ++i)
        ans += pw[i] * c[i], c[i + 1] += c[i];
    std::cout << ans.val() << std::endl;
    return 0;
}