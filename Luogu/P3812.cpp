// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long s[60];
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static long long x;
        std::cin >> x;
        for (int i = 49; i >= 0; --i)
        {
            if (~x >> i & 1)
                continue;
            if (s[i])
                x ^= s[i];
            else
            {
                s[i] = x;
                break;
            }
        }
    }
    long long ans = 0;
    for (int i = 49; i >= 0; --i)
        if (~ans >> i & 1)
            ans ^= s[i];
    std::cout << ans << std::endl;
    return 0;
}