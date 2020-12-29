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
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[505][505], dp[505], l, r, dis[505][505];
bool can[505][505];
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
queue<pair<int, int>> que;
bool check()
{
    for (int i = 1; i <= m; ++i)
    {
        if (!can[n][i])
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    fill(dp + 1, dp + 1 + m, INF);
    for (int k = 1; k <= m; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dis[i][j] = -1;
            }
        }
        dis[1][k] = 0;
        que.push({1, k});
        while (!que.empty())
        {
            pair<int, int> now = que.front();
            que.pop();
            can[now.first][now.second] = true;
            for (int i = 0; i < 4; ++i)
            {
                if (!~dis[now.first + xx[i]][now.second + yy[i]] && a[now.first][now.second] > a[now.first + xx[i]][now.second + yy[i]])
                {
                    dis[now.first + xx[i]][now.second + yy[i]] = dis[now.first][now.second] + 1;
                    que.push({now.first + xx[i], now.second + yy[i]});
                }
            }
        }
        // for (int i = 1; i <= n; ++i)
        // {
        //     for (int j = 1; j <= m; ++j)
        //     {
        //         cout << dis[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        int l = INF, r = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (~dis[n][i])
            {
                l = min(l, i);
                r = max(r, i);
            }
        }
        for (int i = l - 1; i <= r; ++i)
        {
            dp[r] = min(dp[r], dp[i] + 1);
        }
    }
    if (check())
    {
        cout << 1 << endl
             << dp[m] << endl;
    }
    else
    {
        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (!can[n][i])
            {
                ++ans;
            }
        }
        cout << 0 << endl
             << ans << endl;
    }
    return 0;
}