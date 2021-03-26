// This Code was made by Chinese_zjc_.
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define int long long
#define double long double
const double INF = 1e18;
const double eps = 0.0000001;
const double PI = acos(-1);
int n, m, r, a[100005], cnt[100005], top;
double dp[100005], ACOS[20005], B[20005];
std::pair<int, int> sta[100005];
double AND(int x, int y) { return a[y] - a[x] <= r + r ? B[a[y] - a[x]] : 0; }
void DP(double c)
{
    sta[top = 1] = std::make_pair(0, 0);
    for (int i = 1; i <= n; ++i)
    {
        std::pair<int, int> *from = std::upper_bound(sta + 1, sta + 1 + top, std::make_pair(i, n)) - 1;
        dp[i] = dp[from->second] + AND(from->second, i) - c;
        cnt[i] = cnt[from->second] + 1;
        int L, R = n;
        if (dp[sta[top].second] + AND(sta[top].second, n) < dp[i] + AND(i, n))
            continue;
        while (sta[top].first > i &&
               dp[sta[top].second] + AND(sta[top].second, sta[top].first) >= dp[i] + AND(i, sta[top].first))
            R = sta[top--].first;
        L = std::max(sta[top].first, i + 1);
        while (L < R)
        {
            int mid = (L + R) / 2;
            if (dp[sta[top].second] + AND(sta[top].second, mid) >= dp[i] + AND(i, mid))
                R = mid;
            else
                L = mid + 1;
        }
        sta[++top] = std::make_pair(L, i);
    }
}
signed main()
{
    // freopen("mod.in","r",stdin);
    // freopen("mod.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 0; i <= r + r; ++i)
        B[i] = (r * r * acos(i * 0.5 / r) - sqrt(r * r - i * i / 4.0) * i / 2) * 2;
    a[0] = -INF;
    double L = 0, R = r * r * PI;
    while (R - L > eps)
    {
        double mid = (L + R) / 2;
        DP(mid);
        if (cnt[n] <= m)
            L = mid;
        else
            R = mid;
    }
    std::cout << std::fixed << std::setprecision(10) << r * r * PI * m - dp[n] - m * L << std::endl;
    return 0;
}
