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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, sx, sy, ex, ey, dis[2005][2005];
char a[2005][2005];
queue<pair<int, int>> que;
vector<pair<int, int>> f[128];
const int xx[] = {0, 1, 0, -1},
          yy[] = {1, 0, -1, 0};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dis[i][j] = -1;
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                sx = i;
                sy = j;
                a[i][j] = '.';
            }
            if (a[i][j] == 'G')
            {
                ex = i;
                ey = j;
                a[i][j] = '.';
            }
            if (isalpha(a[i][j]))
            {
                f[a[i][j]].push_back({i, j});
            }
        }
    }
    dis[sx][sy] = 0;
    que.push({sx, sy});
    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> nxt = {now.first + xx[i], now.second + yy[i]};
            if (!~dis[nxt.first][nxt.second] && a[nxt.first][nxt.second] != '#')
            {
                dis[nxt.first][nxt.second] = dis[now.first][now.second] + 1;
                que.push(nxt);
            }
        }
        for (auto i : f[a[now.first][now.second]])
        {
            if (!~dis[i.first][i.second])
            {
                dis[i.first][i.second] = dis[now.first][now.second] + 1;
                que.push(i);
            }
        }
        f[a[now.first][now.second]].clear();
    }
    cout << dis[ex][ey] << endl;
    return 0;
}