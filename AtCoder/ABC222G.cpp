// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
int T, x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> x;
        x *= 9;
        if (x % 2 == 0)
            x /= 2;
        if (x % 2 == 0 || x % 5 == 0)
            std::cout << -1 << std::endl;
        else
        {
            typedef atcoder::modint mint;
            mint::set_mod(x);
            int phi = 1, tmp = x;
            for (int i = 2; i * i <= tmp; ++i)
                if (tmp % i == 0)
                {
                    phi *= i - 1;
                    tmp /= i;
                    while (tmp % i == 0)
                        tmp /= i, phi *= i;
                }
            if (tmp > 1)
                phi *= tmp - 1;
            int ans = phi;
            for (int i = 1; i * i <= phi; ++i)
                if (phi % i == 0)
                {
                    if (mint(10).pow(i) == 1)
                        ans = std::min(ans, i);
                    if (mint(10).pow(phi / i) == 1)
                        ans = std::min(ans, phi / i);
                }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}