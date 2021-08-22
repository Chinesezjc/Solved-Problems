// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const double eps = 1e-9;
int n, m, tim[3005];
double dis[3005];
bool in[3005];
std::vector<std::pair<int, double>> to[3005];
bool check(double x)
{
    std::vector<int> sta;
    for (int i = 1; i <= n; ++i)
        sta.push_back(i), in[i] = true, tim[i] = 1;
    std::fill(dis + 1, dis + 1 + n, 0);
    std::fill(tim + 1, tim + 1 + n, 0);
    std::fill(in + 1, in + 1 + n, true);
    while (!sta.empty())
    {
        int now = sta.back();
        sta.pop_back();
        in[now] = false;
        for (auto i : to[now])
            if (dis[i.first] > dis[now] + i.second - x)
            {
                dis[i.first] = dis[now] + i.second - x;
                if (!in[i.first])
                {
                    in[i.first] = true;
                    ++tim[i.first];
                    if (tim[i.first] > n)
                        return true;
                    sta.push_back(i.first);
                }
            }
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        static double z;
        std::cin >> x >> y >> z;
        to[x].push_back({y, z});
    }
    double l = -1e4, r = +1e4;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    std::cout << std::fixed << std::setprecision(8) << l << std::endl;
    return 0;
}