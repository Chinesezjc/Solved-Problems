// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
typedef atcoder::modint998244353 mint;
// #define debug
std::string A, B;
mint fact[10005], ifact[10005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B;
    int n = A.size(), m = 0, c = 0;
    for (int i = 0; i != n; ++i)
        m += A[i] == '1' && B[i] == '1', c += A[i] == '1' && B[i] == '0';
    ifact[0] = (fact[0] = 1).inv();
    for (int i = 1; i <= n + 1; ++i)
        ifact[i] = (fact[i] = fact[i - 1] * i).inv();
    std::vector<mint> f(n + 1);
    for (int i = 0; i <= c; ++i)
    {
        mint C = fact[c] * ifact[i] * ifact[c - i] * ((c - i) & 1 ? -1 : 1), D = 1;
        for (int j = 0; j <= n; ++j, D *= i)
            f[j] += C * ifact[j] * D;
    }
    mint ans;
    for (int i = c; i <= c + m; ++i)
        ans += f[i];
    ans *= fact[c] * fact[m] * fact[c + m];
    std::cout << ans.val() << std::endl;
    return 0;
}