// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int MOD = 998244353;
// #define debug
int n, a[5005], b[5005], A[5005], SA[5005], B[5005], SB[5005], ans, C[5005][5005], cnt;
char c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> c, a[i] += c == '1', b[j] += c == '1', cnt += c == '0';
    for (int i = 1; i <= n; ++i)
        ++A[a[i]], ++B[b[i]];
    for (int i = n; i; --i)
        SA[i - 1] = SA[i] + A[i], SB[i - 1] = SB[i] + B[i];
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    std::sort(a + 1, a + 1 + n, std::greater<int>());
    std::sort(b + 1, b + 1 + n, std::greater<int>());
    for (int i = 0, sa = cnt; i <= n; sa += 2 * a[++i] - n)
        for (int j = 0, sb = cnt; j <= n; sb += 2 * b[++j] - n)
            if (sa + sb - i * j - (n - i) * (n - j) == n * n)
                ans = (ans +
                       1ll * (i ? C[A[a[i]]][i - SA[a[i]]] : 1) * (j ? C[B[b[j]]][j - SB[b[j]]] : 1)) %
                      MOD;
    std::cout << ans << std::endl;
    return 0;
}