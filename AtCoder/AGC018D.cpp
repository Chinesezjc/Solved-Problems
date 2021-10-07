// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, fa[100005], fe[100005], siz[100005];
bool good[100005];
long long ans;
std::vector<std::pair<int, int>> to[100005];
std::vector<int> cnt;
void init(int now)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (i.first == fa[now])
            continue;
        fa[i.first] = now;
        fe[i.first] = i.second;
        init(i.first);
        siz[now] += siz[i.first];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a, b, c; i != n; ++i)
    {
        std::cin >> a >> b >> c;
        to[a].push_back({b, c});
        to[b].push_back({a, c});
    }
    init(1);
    for (int i = 2; i <= n; ++i)
        ans += std::min(n - siz[i], siz[i]) * 2ll * fe[i];
    for (int i = 1; i <= n; ++i)
    {
        int max = n - siz[i];
        for (auto j : to[i])
        {
            if (fa[i] == j.first)
                continue;
            max = std::max(max, siz[j.first]);
        }
        if (max * 2 <= n)
            cnt.push_back(i);
    }
    if (cnt.size() - 2)
    {
        int min = INT_MAX;
        for (auto i : to[cnt.back()])
            min = std::min(min, i.second);
        ans -= min;
    }
    else
    {
        ans -= fe[fa[cnt.back()] == cnt.front() ? cnt.back() : cnt.front()];
    }
    std::cout << ans << std::endl;
    return 0;
}