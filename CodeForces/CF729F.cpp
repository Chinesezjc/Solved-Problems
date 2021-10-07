// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #include <atcoder/internal_math>
// const bool x = atcoder::internal::is_prime<50000017>;
// #define debug
struct node
{
    int a, b, c, d;
    std::size_t operator()() const { return d * 50000017 + ((a * 4000ull + b - a) * 100ull + c) % 50000017; }
};
int n, a[4005], pre[4005], suf[4005], dp[50000017 * 2];
int dfs(node now)
{
    if (now.a + now.b + now.c > n)
        return pre[now.a] - suf[n - now.b];
    std::size_t s = now();
    if (dp[s] != INT_MIN)
        return dp[s];
    int v;
    if (now.d)
        v = std::min(dfs({now.a, now.b + now.c, now.c, 0}), dfs({now.a, now.b + now.c + 1, now.c + 1, 0}));
    else
        v = std::max(dfs({now.a + now.c, now.b, now.c, 1}), dfs({now.a + now.c + 1, now.b, now.c + 1, 1}));
    return dp[s] = v;
}
signed main()
{
    std::fill(dp, dp + 50000017 * 2, INT_MIN);
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    for (int i = 0; i != n; ++i)
        pre[i + 1] = pre[i] + a[i];
    for (int i = n; i--;)
        suf[i] = suf[i + 1] + a[i];
    std::cout << dfs({0, 0, 1, 0}) << std::endl;
    return 0;
}