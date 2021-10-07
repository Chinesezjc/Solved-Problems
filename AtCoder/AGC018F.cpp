// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, nota[100005], notb[100005], ans[100005], roota, rootb;
std::vector<int> sona[100005], sonb[100005], to[100005];
int dfsa(int now)
{
    int x = sona[now].size() & 1 ? (ans[now] = 2) - 2 : now;
    for (auto i : sona[now])
    {
        int tmp = dfsa(i);
        if (x && tmp)
            to[x].push_back(tmp), to[tmp].push_back(x), x = 0;
        else
            x ^= tmp;
    }
    return x;
}
int dfsb(int now)
{
    int x = sonb[now].size() & 1 ? (ans[now] = 2) - 2 : now;
    for (auto i : sonb[now])
    {
        int tmp = dfsb(i);
        if (x && tmp)
            to[x].push_back(tmp), to[tmp].push_back(x), x = 0;
        else
            x ^= tmp;
    }
    return x;
}
void work(int now)
{
    for (auto i : to[now])
        if (!ans[i])
            ans[i] = 4 - ans[now], work(i);
        else if (ans[i] + ans[now] != 4)
            std::cout << "IMPOSSIBLE" << std::endl, exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a; i <= n; ++i)
        std::cin >> a, ~a ? sona[a].push_back(i) : void(roota = i);
    for (int i = 1, b; i <= n; ++i)
        std::cin >> b, ~b ? sonb[b].push_back(i) : void(rootb = i);
    for (int i = 1; i <= n; ++i)
        if ((sona[i].size() ^ sonb[i].size()) & 1)
            std::cout << "IMPOSSIBLE" << std::endl, exit(0);
    dfsa(roota);
    dfsb(rootb);
    for (int i = 1; i <= n; ++i)
        if (!ans[i])
        {
            ans[i] = 1;
            work(i);
        }
    std::cout << "POSSIBLE" << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] - 2 << " \n"[i == n];
    return 0;
}