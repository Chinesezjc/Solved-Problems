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
int n, m, v, e, a, b, c, dis[305][305], classroom[2][2005];
double dp[2005][2005][2], accept[2005], ans = INF;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> v >> e;
    for (int i = 1; i <= v; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> classroom[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> accept[i];
    }
    for (int i = 1; i <= e; ++i)
    {
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = min(c, dis[a][b]);
    }
    for (int k = 1; k <= v; ++k)
    {
        for (int i = 1; i <= v; ++i)
        {
            for (int j = 1; j <= v; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i][1][0] = dp[i][1][1] = INF;
    }
    dp[0][1][0] = 0;
    dp[1][1][1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        dp[0][i][0] = dp[0][i - 1][0] + dis[classroom[0][i - 1]][classroom[0][i]];
        dp[0][i][1] = INF;
        for (int j = 1; j <= m; ++j)
        {
            dp[j][i][0] = min(dp[j][i - 1][0] +
                                  dis[classroom[0][i - 1]][classroom[0][i]],
                              dp[j][i - 1][1] +
                                  dis[classroom[0][i - 1]][classroom[0][i]] * (1 - accept[i - 1]) +
                                  dis[classroom[1][i - 1]][classroom[0][i]] * accept[i - 1]);
            dp[j][i][1] = min(dp[j - 1][i - 1][0] +
                                  dis[classroom[0][i - 1]][classroom[0][i]] * (1 - accept[i]) +
                                  dis[classroom[0][i - 1]][classroom[1][i]] * accept[i],
                              dp[j - 1][i - 1][1] +
                                  dis[classroom[0][i - 1]][classroom[0][i]] * (1 - accept[i - 1]) * (1 - accept[i]) +
                                  dis[classroom[0][i - 1]][classroom[1][i]] * (1 - accept[i - 1]) * accept[i] +
                                  dis[classroom[1][i - 1]][classroom[0][i]] * accept[i - 1] * (1 - accept[i]) +
                                  dis[classroom[1][i - 1]][classroom[1][i]] * accept[i - 1] * accept[i]);
        }
    }
    for (int i = 0; i <= m; ++i)
    {
        ans = min(ans, min(dp[i][n][0], dp[i][n][1]));
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}