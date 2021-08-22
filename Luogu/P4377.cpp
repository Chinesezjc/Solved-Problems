// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const double eps = 0.0001;
int n, w;
struct node
{
    int w, t;
} a[255];
double dp[1005];
void cmax(double &A, double B) { A = std::max(A, B); }
bool check(double x)
{
    std::fill(dp, dp + w + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = w; j >= 0; --j)
            cmax(dp[std::min(w, j + a[i].w)], dp[j] + a[i].t - a[i].w * x);
    return dp[w] >= 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> w;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].w >> a[i].t;
    double l = 0, r = 1000000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    std::cout << int(1000 * l) << std::endl;
    return 0;
}