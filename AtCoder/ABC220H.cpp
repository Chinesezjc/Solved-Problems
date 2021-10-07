// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
typedef atcoder::modint998244353 mint;
// #define debug
const int lim = 20, LIM = 1 << lim;
int n, m, popcount[1 << lim];
long long ans, A[1 << lim][2], B[1 << lim][2], d[40];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i != 1 << lim; ++i)
        popcount[i] = popcount[i & (i - 1)] ^ 1;
    for (int i = 0, a, b; i != m; ++i)
    {
        std::cin >> a >> b;
        --a;
        --b;
        d[a] ^= 1ll << b;
        d[b] ^= 1ll << a;
    }
    m &= 1;
    if (n <= lim)
    {
        for (int i = 0; i != 1 << n; ++i)
        {
            int x = 0, y = 0;
            for (int j = 0; j != n; ++j)
                if (i >> j & 1)
                    x ^= popcount[y & d[j]], y ^= 1 << j;
            if (x == m)
                ++ans;
        }
        std::cout << ans << std::endl;
        return 0;
    }
    for (int i = 0; i != 1 << lim; ++i)
    {
        int x = 0, y = 0, z = 0;
        for (int j = 0; j != lim; ++j)
            if (i >> j & 1)
                x ^= popcount[y & (d[j] % LIM)], z ^= d[j] >> lim, y ^= 1 << j;
        ++A[z][x];
    }
    for (int i = 0; i != 1 << (n - lim); ++i)
    {
        int x = 0, y = 0;
        for (int j = 0; j != n - lim; ++j)
            if (i >> j & 1)
                x ^= popcount[y & (d[j + lim] >> lim)], y ^= 1 << j;
        ++B[y][x];
    }
    // for (int i = 0; i != 1 << (n - lim); ++i)
    //     for (int j = 0; j != 1 << (n - lim); ++j)
    //         for (int k = 0; k != 2; ++k)
    //             for (int l = 0; l != 2; ++l)
    //                 C[i & j][k ^ l] += A[i][k] * B[j][l];
    for (int i = 0; i != n - lim; ++i)
        for (int j = 1 << i; j < 1 << (n - lim); j = (j + 1) | 1 << i)
        {
            A[j ^ 1 << i][0] += A[j][0];
            A[j ^ 1 << i][1] += A[j][1];
            B[j ^ 1 << i][0] += B[j][0];
            B[j ^ 1 << i][1] += B[j][1];
        }
    for (int i = 0; i != 1 << (n - lim); ++i)
    {
        static long long a, b;
        a = A[i][0], b = A[i][1];
        A[i][0] = a + b;
        A[i][1] = a - b;
        a = B[i][0], b = B[i][1];
        B[i][0] = a + b;
        B[i][1] = a - b;
    }
    for (int i = 0; i != 1 << (n - lim); ++i)
    {
        A[i][0] *= B[i][0];
        A[i][1] *= B[i][1];
    }
    for (int i = 0; i != 1 << (n - lim); ++i)
    {
        static long long a, b;
        a = A[i][0], b = A[i][1];
        A[i][0] = (a + b) / 2;
        A[i][1] = (a - b) / 2;
    }
    for (int i = 0; i != n - lim; ++i)
        for (int j = 1 << i; j < 1 << (n - lim); j = (j + 1) | 1 << i)
        {
            A[j ^ 1 << i][0] -= A[j][0];
            A[j ^ 1 << i][1] -= A[j][1];
        }
    for (int i = 0; i != 1 << (n - lim); ++i)
        ans += A[i][popcount[i] ^ m];
    std::cout << ans << std::endl;
    return 0;
}