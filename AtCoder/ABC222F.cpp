// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[200005], b[200005], c[200005], d[200005], fa[200005];
long long dp[200005], ans[200005];
std::vector<int> to[200005];
void init(int now)
{
    dp[now] = d[now];
    for (auto i : to[now])
    {
        if (fa[now] == i)
            continue;
        int v = a[i] ^ b[i] ^ now;
        fa[v] = i;
        init(v);
        dp[now] = std::max(dp[now], dp[v] + c[i]);
    }
}
void dfs(int now, long long x)
{
    long long pre[to[now].size() + 1], suf[to[now].size() + 1];
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    pre[0] = d[now];
    suf[to[now].size()] = x;
    for (std::size_t i = 0; i != to[now].size(); ++i)
        if (to[now][i] != fa[now])
            pre[i + 1] = std::max(pre[i], dp[a[to[now][i]] ^ b[to[now][i]] ^ now] + c[to[now][i]]);
        else
            pre[i + 1] = pre[i];
    for (std::size_t i = to[now].size(); i--;)
        if (to[now][i] != fa[now])
            suf[i] = std::max(suf[i + 1], dp[a[to[now][i]] ^ b[to[now][i]] ^ now] + c[to[now][i]]);
        else
            suf[i] = suf[i + 1];
    ans[now] = x;
    for (std::size_t i = 0; i != to[now].size(); ++i)
        if (fa[now] != to[now][i])
            dfs(a[to[now][i]] ^ b[to[now][i]] ^ now, std::max(pre[i], suf[i + 1]) + c[to[now][i]]),
                ans[now] = std::max(ans[now], dp[a[to[now][i]] ^ b[to[now][i]] ^ now] + c[to[now][i]]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
        std::cin >> a[i] >> b[i] >> c[i], to[a[i]].push_back(i), to[b[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        std::cin >> d[i];
    init(1);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}