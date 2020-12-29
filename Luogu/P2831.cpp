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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, Limit, n, dp[1 << 18], can[1 << 18], good[1 << 18], cnt, siz[1 << 18];
// Limit is unuseful.
struct pig
{
    double x, y;
    inline bool operator<(const pig &__Val) const
    {
        return x < __Val.x;
    }
} p[20];
inline int lowbit(int now)
{
    return now & -now;
}
bool equal(double A, double B)
{
    return abs(A - B) < eps;
}
inline pair<double, double> getans(double c, double d, double e, double f)
{
    double b = (f * c * c - d * e * e) / ((e * c) * (c - e));
    return {(d / c - b) / c, b};
}
inline double get(pair<double, double> A, double x)
{
    return x * ((x * A.first) + A.second);
}
inline int dfs(int now)
{
    if (~dp[now])
    {
        return dp[now];
    }
    dp[now] = siz[now];
    for (int i = 1; i <= cnt; ++i)
    {
        if (now & good[i])
        {
            dp[now] = min(dp[now], dfs(now ^ (now & good[i])) + 1);
        }
    }
    return dp[now];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> Limit;
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i].x >> p[i].y;
        }
        memset(dp, -1, sizeof(dp));
        memset(can, false, sizeof(can));
        cnt = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                pair<double, double> ab = getans(p[i].x, p[i].y, p[j].x, p[j].y);
                if (ab.first >= 0)
                {
                    continue;
                }
                int v = (1 << i >> 1) | (1 << j >> 1);
                for (int k = j + 1; k <= n; ++k)
                {
                    if (equal(get(ab, p[k].x), p[k].y))
                    {
                        v |= (1 << k >> 1);
                    }
                }
                can[v] = true;
            }
        }
        for (int i = 0; i < 1 << n; ++i)
        {
            if (can[i])
            {
                good[++cnt] = i;
            }
            siz[i] = siz[i >> 1] + (i & 1);
        }
        cout << dfs((1 << n) - 1) << endl;
    }
    return 0;
}