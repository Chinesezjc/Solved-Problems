//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3ffffffffffffff;
int n, m, x[500005], l = -1e12, r = 0, cnt[500005], dp[500005], sum[500005], top;
std::pair<int, int> sta[500005];
int w(int L, int R)
{
    if (L >= R)
        return INF;
    int mid = (L + R + 1) >> 1;
    return (sum[R] - sum[mid] - (R - mid) * x[mid]) + ((mid - L) * x[mid] - sum[mid] + sum[L]);
    // return sum[R] + (mid * 2 - (L + R)) * x[mid] + sum[L];
}
void DP(int k)
{
    sta[top = 1] = std::make_pair(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int from = (std::upper_bound(sta + 1, sta + 1 + top, std::make_pair(i, INF)) - 1)->second;
        dp[i] = dp[from] + w(from, i) - k;
        cnt[i] = cnt[from] + 1;
        int R = n + 1;
        while (dp[sta[top].second] + w(sta[top].second, sta[top].first) >= dp[i] + w(i, sta[top].first))
            R = sta[top--].first;
        int L = std::max(sta[top].first + 1, i);
#ifdef debug
        std::cout << i << ' ' << L << ' ' << R << std::endl;
#endif
        if (L > R)
            continue;
        while (L < R)
        {
            int mid = (L + R) / 2;
            if (dp[i] + w(i, mid) <= dp[sta[top].second] + w(sta[top].second, mid))
                R = mid;
            else
                L = mid + 1;
        }
        if (L <= n)
            sta[++top] = std::make_pair(L, i);
#ifdef debug
        for (int i = 1; i <= top; ++i)
            std::cout << sta[i].first << ' ' << sta[i].second << std::endl;
        std::cout << "end " << i << std::endl;
#endif
    }
#ifdef debug
    std::cout << "END " << dp[n] << ' ' << cnt[n] << std::endl;
#endif
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i];
    std::sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + x[i];
    while (l < r)
    {
        int mid = (l + r) >> 1;
        DP(mid);
        if (cnt[n] < m)
            l = mid + 1;
        else
            r = mid;
#ifdef debug
        std::cout << l << ' ' << r << std::endl;
#endif
    }
    DP(l);
    std::cout << dp[n] + m * l << std::endl;
    return 0;
}