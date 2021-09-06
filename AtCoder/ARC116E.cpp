// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, d[200005], fa[200005], mid, cnt;
std::vector<int> son[200005];
void init(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        init(son[now][i]);
    }
}
void dfs(int now)
{
    d[now] = +1;
    for (auto i : son[now])
    {
        dfs(i);
        int t = d[i] + 1 ?: 1;
        if (d[i] < 0)
        {
            if (d[now] < 0)
                d[now] = std::min(d[now], t);
            else if (-t >= d[now])
                d[now] = t;
        }
        else
        {
            if (d[now] > 0)
                d[now] = std::max(d[now], t);
            else if (t > -d[now])
                d[now] = t;
        }
    }
    if (d[now] == mid + 1)
        d[now] = -mid - 1, ++cnt;
}
bool check()
{
    cnt = 0;
    dfs(1);
    // std::cout << mid << ' ' << cnt << ' ' << d[1] << std::endl;
    return cnt + (d[1] >= 0) <= k;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    if (n == k)
        return std::cout << 0 << std::endl, 0;
    for (int i = 1; i < n; ++i)
    {
        static int u, v;
        std::cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    init(1);
    int l = 1, r = n;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check())
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << std::endl;
    return 0;
}