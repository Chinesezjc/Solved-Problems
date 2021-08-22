// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, in[10005], p, q, cnt, del[10005];
std::vector<int> to[10005];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
std::vector<std::pair<int, int>> rk;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        p = q = 0;
        for (int i = 1; i <= m; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        for (int i = 1; i <= n; ++i)
            in[i] = to[i].size(), que.push({in[i], i});
        std::fill(del + 1, del + 1 + n, false);
        rk.clear();
        while (!que.empty())
        {
            std::pair<int, int> now = que.top();
            que.pop();
            if (now.first != in[now.second])
                continue;
            del[now.second] = true;
            rk.push_back(now);
            for (auto i : to[now.second])
                if (!del[i])
                    que.push({--in[i], i});
        }
        std::vector<std::pair<int, int>>::iterator iter = std::max_element(rk.begin(), rk.end());
        std::cout << (p = rk.end() - iter);
        while (iter != rk.end())
            std::cout << ' ' << iter++->second;
        std::cout << '\n';
        std::fill(del + 1, del + 1 + n, false);
        rk.clear();
        for (int i = 1; i <= n; ++i)
            in[i] = to[i].size(), que.push({in[i], i});
        while (!que.empty())
        {
            std::pair<int, int> now = que.top();
            que.pop();
            if (now.first != in[now.second] || del[now.second])
                continue;
            del[now.second] = true;
            rk.push_back(now);
            for (auto i : to[now.second])
                del[i] = now.second;
            for (auto i : to[now.second])
                if (del[i] == now.second)
                    for (auto j : to[i])
                        if (!del[j])
                            que.push({--in[j], j});
        }
        std::cout << rk.size();
        for (auto i : rk)
            std::cout << ' ' << i.second;
        std::cout << '\n';
        for (int i = 1; i <= n; ++i)
            to[i].clear();
    }
    return 0;
}