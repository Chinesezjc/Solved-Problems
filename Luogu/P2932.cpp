// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int p, c, n;
std::vector<int> to[30005];
bool bad[30005], good[30005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> p >> c >> n;
    for (int i = 1; i <= c; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        for (auto j : to[x])
            bad[j] = true;
    }
    std::queue<int> que;
    que.push(1);
    good[1] = true;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (auto i : to[now])
            if (!bad[i] && !good[i])
                good[i] = true, que.push(i);
    }
    std::cout << p - std::count(good + 1, good + 1 + p, true) << std::endl;
    return 0;
}