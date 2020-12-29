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
const int INF = 0x3fffffffffffff;
int dp[12][1 << 12], n, m, dis[12][12], Min[1 << 12][12], a, b, c, ans = INF;
int getmin(int now, int to)
{
    if (Min[now][to])
    {
        return Min[now][to];
    }
    Min[now][to] = INF;
    for (int i = 0; i < n; ++i)
    {
        if (now & (1 << i))
        {
            Min[now][to] = min(Min[now][to], dis[i][to]);
        }
    }
    return Min[now][to];
}
int dfs(int depth, int now)
{
    // cout << depth << ' ' << now << endl;
    if (dp[depth][now])
    {
        return dp[depth][now];
    }
    if (now + 1 == 1 << n)
    {
        return 0;
    }
    dp[depth][now] = INF;
    for (int i = ((1 << n) - 1) & ~now; i; i = (i - 1) & ~now)
    {
        int v = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                v += getmin(now, j);
            }
        }
        dp[depth][now] = min(dp[depth][now], dfs(depth + 1, now | i) + v * depth);
    }
    return dp[depth][now];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        --a;
        --b;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, dfs(1, 1 << i));
    }
    cout << ans << endl;
    return 0;
}