// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
double eps = 0.0001;
int n, m, v[1005], tim[1005];
std::vector<std::pair<int, int>> to[1005], from[1005];
bool in[1005];
double dis[1005];
bool check(double x)
{
    std::fill(dis + 1, dis + 1 + n, INT_MIN);
    std::fill(tim + 1, tim + 1 + n, 0);
    std::fill(in + 1, in + 1 + n, false);
    dis[1] = 0;
    std::stack<int> sta;
    sta.push(1);
    while (!sta.empty())
    {
        int now = sta.top();
        sta.pop();
        in[now] = false;
        for (auto i : to[now])
        {
            if (dis[i.first] < dis[now] + v[i.first] - i.second * x)
            {
                dis[i.first] = dis[now] + v[i.first] - i.second * x;
                if (!in[i.first])
                {
                    in[i.first] = true;
                    sta.push(i.first);
                    ++tim[i.first];
                    if (tim[i.first] > n)
                        return true;
                }
            }
        }
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, v;
        std::cin >> x >> y >> v;
        to[x].push_back({y, v});
        from[y].push_back({x, v});
    }
    double l = 0, r = 1000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    std::cout << std::fixed << std::setprecision(2) << l << std::endl;
    return 0;
}