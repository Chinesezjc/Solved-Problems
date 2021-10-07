// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int A, B, C;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B >> C;
    for (int i = A; i <= B; ++i)
        if (i % C == 0)
            std::cout << i << std::endl, exit(0);
    std::cout << -1 << std::endl;
    return 0;
}