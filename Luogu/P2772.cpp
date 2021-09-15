// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
std::pair<int, int> p[500005];
std::vector<int> sta;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i].first >> p[i].second, p[i].first = -p[i].first, p[i].second = -p[i].second;
    std::sort(p + 1, p + 1 + n);
    for (int i = n; i; --i)
    {
        while (!sta.empty() && p[sta.back()].second >= p[i].second)
            sta.pop_back();
        sta.push_back(i);
    }
    for (std::size_t i = 0; i != sta.size(); ++i)
        std::cout << '(' << -p[sta[i]].first << ',' << -p[sta[i]].second << ')' << ",\n"[i + 1 == sta.size()];
    return 0;
}