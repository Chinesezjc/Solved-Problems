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
char Map[205][205];
int n, m, sx, sy, ans;
queue<pair<int, int>> que;
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(Map, '#', sizeof(Map));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    Map[sx][sy] = '#';
    que.push({sx, sy});
    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> nxt = {now.first + xx[i], now.second + yy[i]};
            if (Map[nxt.first][nxt.second] != '#')
            {
                if (Map[nxt.first][nxt.second] == '*')
                {
                    ++ans;
                }
                Map[nxt.first][nxt.second] = '#';
                que.push(nxt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}