// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k, selled[100005], a[100005], b[100005], c[100005], d[100005], die[100005];
long long ans[100005];
std::vector<int> app[100005], upd, added;
int left(int day, int id) { return std::max(0ll, c[id] - 1ll * day * d[id] - selled[id]); }
std::priority_queue<std::pair<int, int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
        die[i] = left(100000, i) > 0 ? 100000 : (c[i] + d[i] - 1) / d[i];
        app[die[i]].push_back(i);
        --c[i];
    }
    for (int i = 100000; i; --i)
    {
        while (!app[i].empty())
        {
            que.push({b[app[i].back()] + a[app[i].back()], -1});
            que.push({a[app[i].back()], app[i].back()});
            app[i].pop_back();
        }
        while (!upd.empty())
        {
            que.push({a[upd.back()], upd.back()});
            upd.pop_back();
        }
        int has = m;
        while (has && !que.empty())
        {
            std::pair<int, int> now = que.top();
            if (~now.second)
            {
                int cnt = std::min(has, left(i - 1, now.second));
                has -= cnt;
                selled[now.second] += cnt;
                ans[100000] += 1ll * cnt * now.first;
                if (!left(i - 1, now.second))
                {
                    que.pop();
                    if (d[now.second])
                        upd.push_back(now.second);
                }
                while (cnt--)
                    added.push_back(now.first);
            }
            else
            {
                --has;
                ans[100000] += now.first;
                que.pop();
                added.push_back(now.first);
            }
        }
    }
    std::sort(added.begin(), added.end());
    std::reverse(added.begin(), added.end());
    for (int i = 99999; i; --i)
    {
        ans[i] = ans[i + 1];
        while (int(added.size()) > i * m)
            ans[i] -= added.back(), added.pop_back();
    }
    while (k--)
    {
        static int p;
        std::cin >> p;
        std::cout << ans[p] << std::endl;
    }
    return 0;
}