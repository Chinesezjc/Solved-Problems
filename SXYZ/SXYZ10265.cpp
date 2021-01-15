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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, t[100005], ans;
bool p;
int dis(int a, int b)
{
    return (b + n - a) % n;
}
void solve()
{
    int dp[1 << 10][10];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        dp[1 << i][i] = t[i];
    }
    for (int i = 0; i < 1 << n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < n; ++k)
                {
                    if (i & (1 << k))
                    {
                        continue;
                    }
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + max(dis(j, k), t[k] - dp[i][j]));
                }
            }
        }
    }
    ans = INF;
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }
    solve();
    for (int i = 0; i < m; ++i)
    {
        static int x, y;
        cin >> x >> y;
        if (p)
        {
            x ^= ans;
            y ^= ans;
        }
        --x;
        t[x] = y;
        solve();
    }
    return 0;
}