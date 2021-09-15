// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long A, B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x; i <= n; ++i)
        std::cin >> x, A += x * 3, B += x;
    for (int i = 1, x; i <= n; ++i)
        std::cin >> x, A -= x * 2, B -= x;
    std::cout << std::fixed << std::setprecision(6) << 1.0l * A / B << std::endl;
    return 0;
}