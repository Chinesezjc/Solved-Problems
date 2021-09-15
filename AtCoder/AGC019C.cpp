// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct point
{
    int x, y;
} a[200005];
int dp[200005], sx, sy, ex, ey, n, cnt;
double ans;
const double s = 10 * 2 - 10 / 2 * std::acos(-1);
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> sx >> sy >> ex >> ey >> n;
    std::cout << std::fixed << std::setprecision(20);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].x >> a[i].y;
    if (sx == ex)
    {
        ans = (std::max(sy, ey) - std::min(sy, ey)) * 100.0;
        for (int i = 1; i <= n; ++i)
            if (sx == a[i].x && std::min(sy, ey) <= a[i].y && a[i].y <= std::max(sy, ey))
                ans += 10 * acos(-1) - 10 * 2;
        std::cout << ans << std::endl;
        return 0;
    }
    if (sy == ey)
    {
        ans = (std::max(sx, ex) - std::min(sx, ex)) * 100.0;
        for (int i = 1; i <= n; ++i)
            if (sy == a[i].y && std::min(sx, ex) <= a[i].x && a[i].x <= std::max(sx, ex))
                ans += 10 * acos(-1) - 10 * 2;
        std::cout << ans << std::endl;
        return 0;
    }
    if (sx > ex)
    {
        sx = -sx;
        ex = -ex;
        for (int i = 1; i <= n; ++i)
            a[i].x = -a[i].x;
    }
    if (sy > ey)
    {
        sy = -sy;
        ey = -ey;
        for (int i = 1; i <= n; ++i)
            a[i].y = -a[i].y;
    }
    for (int i = 1; i <= n; ++i)
        if (!(sx <= a[i].x && a[i].x <= ex && sy <= a[i].y && a[i].y <= ey))
        {
            std::swap(a[i--], a[n--]);
            continue;
        }
    std::sort(a + 1, a + 1 + n, [&](const point &A, const point &B)
              { return A.x < B.x; });
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; ++i)
        if (dp[cnt] < a[i].y)
            dp[++cnt] = a[i].y;
        else
            dp[std::upper_bound(dp + 1, dp + 1 + cnt, a[i].y) - dp] = a[i].y;
    ans = (ey + ex - sy - sx) * 100.0 - cnt * s;
    if (ex - sx == cnt - 1 || ey - sy == cnt - 1)
        ans += s + (10 * acos(-1) - 10 * 2);
    std::cout << ans << std::endl;
    return 0;
}