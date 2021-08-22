// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        switch (n)
        {
        case 1:
            std::cout << "No!" << std::endl;
            break;
        case 2:
            std::cout << (k == 2 ? "No!" : "Yes!") << std::endl;
            break;
        default:
            std::cout << ((k & 1) || n == k ? "Yes!" : "No!") << std::endl;
            break;
        }
    }
    return 0;
}