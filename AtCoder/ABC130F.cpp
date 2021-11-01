// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const char dd[] = {'R', 'L', 'U', 'D'};
const int xx[] = {+1, -1, 0, 0}, yy[] = {0, 0, +1, -1};
int n;
long double ans;
struct node
{
    int x, y, d;
} a[100005];
long double check(long double now)
{
    long double xl = INT_MAX, xr = INT_MIN, yl = INT_MAX, yr = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        long double x = a[i].x + xx[a[i].d] * now, y = a[i].y + yy[a[i].d] * now;
        xl = std::min(x, xl);
        xr = std::max(x, xr);
        yl = std::min(y, yl);
        yr = std::max(y, yr);
    }
    return (xr - xl) * (yr - yl);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static char c;
        std::cin >> a[i].x >> a[i].y >> c;
        a[i].d = std::find(dd, dd + 4, c) - dd;
    }
    long double l = 0, r = 200000000;
    while (l != r)
    {
        long double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (std::abs(mid1 - mid2) < 1e-16)
        {
            l = r = mid1;
            break;
        }
        else if (check(mid1) > check(mid2))
            l = mid1;
        else
            r = mid2;
    }
    std::cout << std::fixed << std::setprecision(20) << check(l) << std::endl;
    return 0;
}