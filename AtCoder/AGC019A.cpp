// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a, b, c, d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c >> d >> n;
    b = std::min(a + a, b);
    c = std::min(b + b, c);
    d = std::min(c + c, d);
    std::cout << n / 2ll * d + n % 2ll * c << std::endl;
    return 0;
}