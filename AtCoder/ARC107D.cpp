//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
using namespace std;
int dp[3005][6005], n, k, sum[3005][6005];
int dfs(int left, int v)
{
    if (v > left)
    {
        return 0;
    }
    if (~dp[left][v])
    {
        return dp[left][v];
    }
    dp[left][v] = 0;
    for (int i = 0; i <= min(left, v); ++i)
    {
        dp[left][v] += dfs(left - i, (v - i) * 2);
        dp[left][v] %= MOD;
    }
    return dp[left][v];
}
int G(int i, int j)
{
    if (i >= 0 && j >= 0)
    {
        return sum[i][j];
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    // memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    sum[0][0] = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n + 1; j <= n + n; ++j)
        {
            sum[i][j] = G(i - 1, j - 2) + dp[i][j];
        }
        for (int j = n; j >= 0; --j)
        {
            // for (int k = 0; k <= min(i, j); ++k)
            // {
            //     dp[i][j] += dp[i - k][(j - k) * 2];
            // }
            dp[i][j] = sum[i][j * 2];
            dp[i][j] %= MOD;
            sum[i][j] = G(i - 1, j - 2) + dp[i][j];
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][k] << endl;
    return 0;
}