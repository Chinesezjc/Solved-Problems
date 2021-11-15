// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int B = 4;
int cnt, e[65], lim;
long long k;
std::vector<int> bel[65];
std::vector<std::pair<int, int>> edges;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> k;
    ++cnt;
    for (int i = 0; i != B; ++i)
    {
        bel[0].push_back(++cnt);
        edges.push_back({1, cnt});
    }
    e[0] = ++cnt;
    for (auto i : bel[0])
        if (k % B)
            edges.push_back({i, e[0]}), k -= 1;
    for (long long i = B; i <= k && ++lim; i *= B)
    {
        for (int j = 0; j != B && j * i < k; ++j)
        {
            bel[lim].push_back(++cnt);
            for (auto k : bel[lim - 1])
                edges.push_back({k, cnt});
        }
        e[lim] = ++cnt;
        edges.push_back({e[lim - 1], cnt});
        for (auto j : bel[lim])
            if (k % (i * B))
                edges.push_back({j, e[lim]}), k -= i;
    }
    std::cout << cnt << ' ' << edges.size() << std::endl;
    for (auto i : edges)
        std::cout << i.first << ' ' << i.second << std::endl;
    return 0;
}