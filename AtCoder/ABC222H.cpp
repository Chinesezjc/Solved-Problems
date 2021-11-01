// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint998244353 mint;
const int MOD = 998244353;
int n;
mint power(int B, int C)
{
    mint inv[C + 1], res[C + 1];
    res[0] = 1;
    res[1] = B * 3;
    inv[1] = 1;
    for (int i = 1; i < C; ++i)
    {
        inv[i + 1] = -inv[MOD % (i + 1)] * (MOD / (i + 1));
        res[i + 1] = inv[i + 1] * ((3 * B - 3 * i) * res[i] + (2 * B - (i - 1)) * res[i - 1]);
    }
    return res[C];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::cout << (mint(n).inv() * power(n * 2, n - 1)).val() << std::endl;
    return 0;
}