// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long ans;
bool flg;
std::vector<int> a[200005];
std::priority_queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0, t; i != n; ++i)
    {
        std::cin >> t;
        for (int j = 0, x; j != t; ++j)
            std::cin >> x, a[i].push_back(x);
        while (a[i].size() > 4)
            a[i].erase(a[i].begin()), a[i].pop_back();
    }
    flg = 1 & std::count_if(a, a + n, [&](const std::vector<int> &x)
                            { return x.size() % 2 == 0; });
    for (int i = 0; i != n; ++i)
    {
        int s = a[i].size();
        if (s == 1)
            ans += a[i][0];
        else if (s == 2)
            ans += std::min(a[i][0], a[i][1]), que.push(std::max(a[i][0], a[i][1]) - std::min(a[i][0], a[i][1]));
        else if (s & 1)
            ans += flg
                       ? std::max(a[i][s / 2], std::min(a[i][s / 2 - 1], a[i][s / 2 + 1]))
                       : std::min(a[i][s / 2], std::max(a[i][s / 2 - 1], a[i][s / 2 + 1]));
        else
        {
            int x = flg ? std::max(a[i][s / 2 - 1], std::min(a[i][s / 2 - 2], a[i][s / 2]))
                        : std::min(a[i][s / 2 - 1], std::max(a[i][s / 2 - 2], a[i][s / 2])),
                y = flg ? std::max(a[i][s / 2], std::min(a[i][s / 2 - 1], a[i][s / 2 + 1]))
                        : std::min(a[i][s / 2], std::max(a[i][s / 2 - 1], a[i][s / 2 + 1]));
            ans += std::min(x, y);
            que.push(std::max(x, y) - std::min(x, y));
        }
    }
    while (!que.empty())
    {
        ans += que.top();
        que.pop();
        if (!que.empty())
            que.pop();
    }
    std::cout << ans << std::endl;
    return 0;
}