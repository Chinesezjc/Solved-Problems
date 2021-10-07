// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[250005], b[250005], t[1 << 18][18][2], A[1 << 18][18][2][2][2], B[1 << 18][18][2][2][2], pre[18];
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    for (int i = 0; i != n; ++i)
        std::cin >> b[i];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != 18; ++j)
            ans += 1ll * t[a[i] ^ b[i]][j][~a[i] >> j & 1] << j, ++t[a[i] ^ b[i]][j][a[i] >> j & 1];
    for (int i = 0; i != 18; ++i)
        pre[i] = (1 << 18) - (1 << i << 1);
    for (int i = 0; i != 18; ++i)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        for (int j = 0; j != n; ++j)
        {
            int now = (a[j] ^ b[j]) & pre[i];
            for (int k = 0; k != 18; ++k)
            {
                long long tot = A[now][k][+a[j] >> i & 1][~b[j] >> i & 1][~a[j] >> k & 1] +
                                B[now][k][~a[j] >> i & 1][+b[j] >> i & 1][~b[j] >> k & 1];
                ans += tot << k;
                ++A[now][k][a[j] >> i & 1][b[j] >> i & 1][a[j] >> k & 1];
                ++B[now][k][a[j] >> i & 1][b[j] >> i & 1][b[j] >> k & 1];
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}