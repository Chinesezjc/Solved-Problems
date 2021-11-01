// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
int n, m, k, tim[1005], a[1005], b[1005], fa[1005], depth[1005], c[105];
std::vector<int> to[1005];
atcoder::modint998244353 dp[100005];
void init(int now)
{
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        int v = a[i] ^ b[i] ^ now;
        fa[v] = i;
        depth[v] = depth[now] + 1;
        init(v);
    }
}
void work(int A, int B)
{
    while (A != B)
        if (depth[A] < depth[B])
            ++tim[fa[B]], B = a[fa[B]] ^ b[fa[B]] ^ B;
        else
            ++tim[fa[A]], A = a[fa[A]] ^ b[fa[A]] ^ A;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
        std::cin >> c[i];
    for (int i = 1; i < n; ++i)
        std::cin >> a[i] >> b[i], to[a[i]].push_back(i), to[b[i]].push_back(i);
    init(1);
    for (int i = 2; i <= m; ++i)
        work(c[i - 1], c[i]);
    dp[0] = 1;
    int sum = std::accumulate(tim + 1, tim + n, 0);
    for (int i = 1; i < n; ++i)
        for (int j = 100000; j >= tim[i]; --j)
            dp[j] += dp[j - tim[i]];
    std::cout << (((sum + k) & 1) || (sum + k) < 0 ? 0 : dp[(sum + k) >> 1].val()) << std::endl;
    return 0;
}