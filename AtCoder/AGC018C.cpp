// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int x, y, z, n;
long long sum, ans;
bool vis[100005];
struct node
{
    int a, b, c;
} g[100005];
std::priority_queue<int> que1;
std::priority_queue<std::pair<int, int>> que2;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> x >> y >> z;
    n = x + y + z;
    for (int i = 0; i != n; ++i)
        std::cin >> g[i].a >> g[i].b >> g[i].c;
    std::sort(g, g + n, [&](const auto &A, const auto &B)
              { return A.a - A.b > B.a - B.b; });
    for (int i = 0; i != x; ++i)
        sum += g[i].a, que1.push(g[i].c - g[i].a);
    for (int i = x; i != n; ++i)
        sum += g[i].c, que2.push({g[i].b - g[i].c, i});
    while (int(que2.size()) > z)
        sum += que2.top().first, vis[que2.top().second] = true, que2.pop();
    ans = sum;
    for (int i = x; i != n - y; ++i)
    {
        sum += g[i].a - (vis[i] ? g[i].b : g[i].c);
        que1.push(g[i].c - g[i].a);
        sum += que1.top();
        que1.pop();
        if (vis[i])
        {
            while (que2.top().second <= i)
                que2.pop();
            sum += que2.top().first, vis[que2.top().second] = true, que2.pop();
        }
        ans = std::max(ans, sum);
    }
    std::cout << ans << std::endl;
    return 0;
}