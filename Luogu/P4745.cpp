// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
double dis[300005], sum[300005];
bool vis[300005];
std::vector<int> to[300005];
std::priority_queue<std::pair<double, int>> que;
std::priority_queue<double> t[300005];
void push(int pos, double val)
{
    sum[pos] += val;
    t[pos].push(val);
    while (t[pos].size() > 1 && sum[pos] / t[pos].size() > (sum[pos] + t[pos].top()) / (t[pos].size() - 1))
        sum[pos] -= t[pos].top(), t[pos].pop();
    if (dis[pos] > sum[pos] / t[pos].size())
        que.push({-(dis[pos] = sum[pos] / t[pos].size()), pos});
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
        ++sum[x];
        ++sum[y];
    }
    std::fill(dis + 1, dis + 1 + n, 1e18);
    que.push({-(dis[n] = 0), n});
    while (!que.empty())
    {
        std::pair<double, int> now = que.top();
        que.pop();
        if (now.first + dis[now.second] != 0)
            continue;
        vis[now.second] = true;
        for (auto i : to[now.second])
            if (!vis[i])
                push(i, dis[now.second]);
    }
    std::cout << std::fixed << std::setprecision(10) << dis[1] << std::endl;
    return 0;
}