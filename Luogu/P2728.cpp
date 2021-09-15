// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a[5], n[5], b[5][5], c[5][5];
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 5; ++i)
    {
        std::cin >> a[i] >> n[i];
        for (int j = 0; j != n[i]; ++j)
            std::cin >> b[i][j] >> c[i][j];
    }
    for (int i = 0; i != 360; ++i)
    {
        static int t[360];
        memset(t, 0, sizeof(t));
        for (int j = 0; j != 5; ++j)
            for (int k = 0; k != n[j]; ++k)
                for (int l = 0; l <= c[j][k]; ++l)
                    ++t[(i * a[j] + b[j][k] + l) % 360];
        if (std::count(t, t + 360, 5))
            return std::cout << i << std::endl, 0;
    }
    std::cout << "none" << std::endl;
    return 0;
}