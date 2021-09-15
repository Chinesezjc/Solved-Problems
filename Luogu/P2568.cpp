// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, phi[10000005];
long long ans;
std::vector<int> p;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > n)
                break;
            phi[i * j] = phi[i] * phi[j];
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                break;
            }
        }
    }
    for (auto i : p)
    {
        ++ans;
        for (int j = 1; j <= n / i; ++j)
            ans += phi[j] * 2;
    }
    std::cout << ans << std::endl;
    return 0;
}