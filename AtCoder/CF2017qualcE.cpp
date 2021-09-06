// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/all>
// #define debug
typedef atcoder::modint1000000007 mint;
typedef std::array<int, 3> point;
int d;
point n;
mint ans;
std::vector<point> p;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n[0] >> n[1] >> n[2] >> d;
    for (int k = 0; k != 3; ++k)
        for (int i = 0; i <= d && i < n[k]; ++i)
        {
            point tmp;
            for (int j = 0; j != 3; ++j)
                tmp[j] = 1ll * i * n[j] / n[k];
            p.push_back(tmp);
        }
    for (int k = 0; k != 3; ++k)
        for (int i = 0; i <= d && i < n[k]; ++i)
        {
            point tmp;
            for (int j = 0; j != 3; ++j)
                tmp[j] = 1ll * (n[k] - 1 - i) * n[j] / n[k];
            p.push_back(tmp);
        }
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    ans = 1ll * std::min(n[0], d + 1) * std::min(n[1], d + 1) * std::min(n[2], d + 1);
    for (int i = 0; i + 1 != int(p.size()); ++i)
    {
        point S;
        for (int j = 0; j != 3; ++j)
            S[j] = std::min(n[j] - 1, p[i][j] + d) - std::max(0, p[i][j] - d) + 1;
        for (int j = 0; j != 3; ++j)
            if (p[i + 1][j] + d < n[j])
            {
                mint tmp = 1;
                for (int k = 0; k != 3; ++k)
                    if (j != k)
                        tmp *= S[k];
                ans += tmp * (p[i + 1][j] - p[i][j]);
            }
    }
    std::cout << ans.val() << std::endl;
    return 0;
}