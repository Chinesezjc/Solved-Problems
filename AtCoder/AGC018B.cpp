// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, rk[305][305], x[305];
bool del[305];
std::size_t ans = -1;
std::vector<int> cnt[305];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            std::cin >> rk[i][j], --rk[i][j];
    for (int i = 0; i != n; ++i)
        cnt[rk[i][x[i]]].push_back(i);
    for (int i = 0; i != m; ++i)
    {
        auto now = std::max_element(cnt, cnt + m, [&](const auto &A, const auto &B)
                                    { return A.size() < B.size(); });
        del[now - cnt] = true;
        ans = std::min(ans, now->size());
        for (auto j : *now)
        {
            while (del[rk[j][x[j]]])
                ++x[j];
            cnt[rk[j][x[j]]].push_back(j);
        }
        now->clear();
    }
    std::cout << ans << std::endl;
    return 0;
}