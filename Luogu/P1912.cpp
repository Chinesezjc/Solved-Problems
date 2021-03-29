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
const int INF = 0x3fffffffffffffff;
int T, n, m, k, sum[100005], from[100005], lim, top;
double dp[100005];
std::pair<int, int> sta[100005];
std::string s[100005];
double power(double A, int B)
{
    double res = 1;
    while (B)
    {
        if (B & 1)
            res *= A;
        B >>= 1;
        A *= A;
    }
    return res;
}
double w(int A, int B) { return power(llabs(sum[B] - sum[A] - 1 - m), k); }
void DP()
{
    sta[top = 1] = std::make_pair(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        from[i] = (std::upper_bound(sta + 1, sta + 1 + top, std::make_pair(i, i)) - 1)->second;
        dp[i] = dp[from[i]] + w(from[i], i);
        int r = n;
        while (sta[top].first > i &&
               dp[i] + w(i, sta[top].first) <= dp[sta[top].second] + w(sta[top].second, sta[top].first))
            r = sta[top--].first;
        int l = std::max(i, sta[top].first) + 1;
        if (l > r)
            continue;
        while (l < r)
        {
#ifdef debug
            std::cout << i << std::endl;
#endif
            int mid = (l + r) >> 1;
            if (dp[i] + w(i, mid) <= dp[sta[top].second] + w(sta[top].second, mid))
                r = mid;
            else
                l = mid + 1;
        }
#ifdef debug
        std::cout << l << std::endl;
#endif
        if (dp[i] + w(i, l) <= dp[sta[top].second] + w(sta[top].second, l))
            sta[++top] = std::make_pair(l, i);
    }
}
void print(int now)
{
    if (from[now])
        print(from[now]);
    for (int i = from[now] + 1; i <= now; ++i)
        std::cout << s[i] << " \n"[i == now];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> k;
        lim = round(pow(1e18, 1.0 / k));
        // std::cout << lim << std::endl;
        for (int i = 1; i <= n; ++i)
            std::cin >> s[i];
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + s[i].length() + 1;
        DP();
        // for (int i = 1; i <= n; ++i)
        // {
        //     std::cout << from[i] << " \n"[i == n];
        // }
        if (dp[n] > 1000000000000000000)
        {
            std::cout << "Too hard to arrange" << std::endl;
            // print(n);
        }
        else
        {
            std::cout << std::fixed << std::setprecision(0) << dp[n] << std::endl;
            print(n);
        }
        std::cout << "--------------------" << std::endl;
    }
    return 0;
}