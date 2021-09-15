// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, dp1[3][100005], dp2[3][100005], fa[100005], fe[100005];
long long ans;
std::vector<std::pair<int, int>> to[100005];
void dfs1(int now)
{
    for (std::size_t i = 0; i != to[now].size(); ++i)
    {
        if (fa[now] == to[now][i].first)
        {
            std::swap(to[now][i--], to[now].back());
            to[now].pop_back();
            continue;
        }
        fa[to[now][i].first] = now;
        fe[to[now][i].first] = to[now][i].second;
        dfs1(to[now][i].first);
        dp1[2][now] = std::max({dp1[2][now], dp1[1][now] + dp1[1][to[now][i].first] + to[now][i].second,
                                dp1[2][to[now][i].first]});
        dp1[1][now] = std::max(dp1[1][now], dp1[0][now] + dp1[1][to[now][i].first] + to[now][i].second);
    }
}
void dfs2(int now)
{
    int L[3][to[now].size() + 1], R[3][to[now].size() + 1];
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    for (std::size_t i = 0; i != to[now].size(); ++i)
    {
        L[2][i + 1] = std::max({L[2][i], L[1][i] + dp1[1][to[now][i].first] + to[now][i].second,
                                dp1[2][to[now][i].first]});
        L[1][i + 1] = std::max(L[1][i], L[0][i] + dp1[1][to[now][i].first] + to[now][i].second);
    }
    for (std::size_t i = to[now].size(); i--;)
    {
        R[2][i] = std::max({R[2][i + 1], R[1][i + 1] + dp1[1][to[now][i].first] + to[now][i].second,
                            dp1[2][to[now][i].first]});
        R[1][i] = std::max(R[1][i + 1], R[0][i + 1] + dp1[1][to[now][i].first] + to[now][i].second);
    }
    for (std::size_t i = 0; i != to[now].size(); ++i)
    {
        dp2[1][to[now][i].first] = std::max({dp2[1][now] + fe[now], L[1][i], R[1][i + 1]});
        dp2[2][to[now][i].first] = std::max({dp2[1][now] + fe[now] + std::max(L[1][i], R[1][i + 1]),
                                             L[1][i] + R[1][i + 1], L[2][i], R[2][i + 1], dp2[2][now]});
        dfs2(to[now][i].first);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x, y, w; i != n; ++i)
    {
        std::cin >> x >> y;
        w = 1;
        to[x].push_back({y, w});
        to[y].push_back({x, w});
    }
    dfs1(1);
    dfs2(1);
    for (int i = 2; i <= n; ++i)
        ans = std::max(ans, 1ll * dp1[2][i] * dp2[2][i]); //, std::cout << dp1[2][i] << ' ' << dp2[2][i] << std::endl;
    std::cout << ans << std::endl;
    return 0;
}