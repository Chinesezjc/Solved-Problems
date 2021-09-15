// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
bool is[10005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    is[1] = true;
    for (int i = 2; i <= n; ++i)
        if (!is[i])
            for (int j = i + i; j <= n; j += i)
                is[j] = true;
    for (int i = 2; i <= n; i += 2)
        for (int j = 2; j < i; ++j)
            if (!is[j] && !is[i - j])
            {
                std::cout << i << '=' << j << '+' << i - j << std::endl;
                break;
            }
    return 0;
}