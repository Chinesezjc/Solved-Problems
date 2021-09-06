// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, m;
long long n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        m = 0;
        while (n % 2 == 0)
            n /= 2, ++m;
        switch (m)
        {
        case 0:
            std::cout << "Odd" << std::endl;
            break;

        case 1:
            std::cout << "Same" << std::endl;
            break;

        default:
            std::cout << "Even" << std::endl;
            break;
        }
    }
    return 0;
}