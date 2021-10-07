// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> to[200005];
int n, fa[200005];
long long ans[200005], sum[200005], siz[200005];
void dfs1(int now)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (fa[now] == i)
            continue;
        fa[i] = now;
        dfs1(i);
        siz[now] += siz[i];
        sum[now] += sum[i] + siz[i];
    }
}
void dfs2(int now)
{
    for (auto i : to[now])
    {
        if (fa[now] == i)
            continue;
        ans[i] = ans[now] + (n - siz[i]) - siz[i];
        dfs2(i);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a, b; i != n; ++i)
        std::cin >> a >> b, to[a].push_back(b), to[b].push_back(a);
    dfs1(1);
    ans[1] = sum[1];
    dfs2(1);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}