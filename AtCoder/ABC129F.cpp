// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
long long l, a, b, m;
typedef atcoder::modint mint;
mint ans, pow10[37];
long long cnt(long long x) { return x <= a ? 0 : (x - 1 - a) / b + 1; }
long long get(long long x) { return a + x * b; }
mint work1(mint A, long long B)
{
    mint res = 0, C = 1;
    while (B)
    {
        if (B & 1)
            res = res * A + C;
        C = A * C + C;
        A *= A;
        B >>= 1;
    }
    return res;
}
mint work2(mint A, long long B)
{
    return B ? work2(A, B / 2) * (1 + A.pow((B + 1) / 2)) + A.pow(B / 2) * ((B + 1) / 2) * work1(A, (B + 1) / 2) : 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> l >> a >> b >> m;
    mint::set_mod(m);
    pow10[0] = 1;
    for (int i = 1; i <= 18; ++i)
    {
        pow10[i] = pow10[i - 1] * 10;
        static long long lim = 10;
        long long L = std::min(cnt(lim), l) - cnt(lim / 10), A = get(cnt(lim / 10));
        ans = ans * pow10[i].pow(L) + (A + L * b) * work1(pow10[i], L) - b * work2(pow10[i], L);
        if (cnt(lim) >= l)
            break;
        lim *= 10;
    }
    std::cout << ans.val() << std::endl;
    return 0;
}