// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include "airline.h"

long long solve(int n, int x, int y, int q, std::vector<int> P, int L)
{
    static long long dis[2005][2005], dp[2005][2005];
    std::vector<int> s = P;
    s.push_back(x);
    s.push_back(y);
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    x = std::lower_bound(s.begin(), s.end(), x) - s.begin();
    y = std::lower_bound(s.begin(), s.end(), y) - s.begin();
    for (int i = 0; i != (int)P.size(); ++i)
        P[i] = std::lower_bound(s.begin(), s.end(), P[i]) - s.begin();
    for (int i = 0; i != (int)s.size(); ++i)
        for (int j = 0; j != i; ++j)
            dis[i][j] = dis[j][i] = distance(s[i], s[j]);
    memset(dp, 0xf0, sizeof(dp));
    dp[0][x] = dis[y][P[0]];
    dp[0][y] = dis[x][P[0]];
    for (int i = 1; i != (int)P.size(); ++i)
    {
        for (int j = 0; j != (int)s.size(); ++j)
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + dis[P[i - 1]][P[i]]);
        for (int j = 0; j != (int)s.size(); ++j)
            dp[i][P[i - 1]] = std::max(dp[i][P[i - 1]], dp[i - 1][j] + dis[j][P[i]]);
    }
    return *std::max_element(dp[P.size() - 1], dp[P.size() - 1] + s.size());
}