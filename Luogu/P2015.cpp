// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, q, fa[105], dp[105][105], x[105], y[105], v[105];
std::vector<int> son[105];
void dfs(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        int to = x[son[now][i]] ^ y[son[now][i]] ^ now;
        if (fa[now] == to)
            continue;
        fa[to] = now;
        dfs(to);
        for (int j = q; j >= 0; --j)
            for (int k = 0; k < j; ++k)
                dp[now][j] = std::max(dp[now][j], dp[now][j - k - 1] + dp[to][k] + v[son[now][i]]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i != n; ++i)
    {
        std::cin >> x[i] >> y[i] >> v[i];
        son[x[i]].push_back(i);
        son[y[i]].push_back(i);
    }
    dfs(1);
    std::cout << dp[1][q] << std::endl;
    return 0;
}