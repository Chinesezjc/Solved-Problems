// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int kmp[200005], n, a[400005], b[200005], c[200005], x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], c[i] = a[i];
    x = a[1];
    for (int i = 1; i <= n; ++i)
        a[i + n] = a[i] = a[i] ^ (i == n ? x : a[i + 1]);
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    x = b[1];
    for (int i = 1; i <= n; ++i)
        b[i] = b[i] ^ (i == n ? x : b[i + 1]);
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && b[j + 1] != b[i])
            j = kmp[j];
        kmp[i] = j += b[j + 1] == b[i];
    }
    for (int i = 1, j = 0; i < n + n; ++i)
    {
        while (j && b[j + 1] != a[i])
            j = kmp[j];
        j += b[j + 1] == a[i];
        if (j == n)
            std::cout << i - n << ' ' << (c[i - n + 1] ^ x) << std::endl, j = kmp[j];
    }
    return 0;
}