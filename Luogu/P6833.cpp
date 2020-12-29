//This Code was made by Chinese_zjc_.
#pragma GCC optimize("Ofast")
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
int n, m, a, b, c, ans = INF;
int v[1005][1005], dis[3][1005][1005];
bool init[1005][1005];
pair<int, int> u, nxt;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
void spfa(int now)
{
    if (now == 0)
    {
        init[n][a] = true;
        dis[now][n][a] = v[n][a];
        que.push({v[n][a], {n, a}});
    }
    if (now == 1)
    {
        init[1][b] = true;
        dis[now][1][b] = v[1][b];
        que.push({v[1][b], {1, b}});
    }
    if (now == 2)
    {
        init[1][c] = true;
        dis[now][1][c] = v[1][c];
        que.push({v[1][c], {1, c}});
    }
    while (!que.empty())
    {
        u = que.top().second;
        que.pop();
        init[u.first][u.second] = false;
        for (int i = 0; i < 4; ++i)
        {
            nxt = {u.first + xx[i], u.second + yy[i]};
            if (dis[now][nxt.first][nxt.second] > dis[now][u.first][u.second] + v[nxt.first][nxt.second])
            {
                dis[now][nxt.first][nxt.second] = dis[now][u.first][u.second] + v[nxt.first][nxt.second];
                if (!init[nxt.first][nxt.second])
                {
                    init[nxt.first][nxt.second] = true;
                    que.push({dis[now][nxt.first][nxt.second], nxt});
                }
            }
        }
    }
}
inline long long read()
{
    long long x = 0;
    char ch = getchar();
    bool positive = 1;
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            positive = 0;
    for (; isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(long long a)
{
    if (a >= 10)
        write(a / 10);
    putchar('0' + a % 10);
}
inline void writesp(long long a)
{
    if (a >= 10)
        write(a / 10);
    putchar('0' + a % 10);
    printf(" ");
}
inline void writeln(long long a)
{
    if (a < 0)
    {
        a = -a;
        putchar('-');
    }
    write(a);
    puts("");
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin >> n >> m >> a >> b >> c;
    n = read();
    m = read();
    a = read();
    b = read();
    c = read();
    for (int i = n; i > 0; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // cin >> v[i][j];
            v[i][j] = read();
            dis[0][i][j] = dis[1][i][j] = dis[2][i][j] = INF;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        spfa(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - (v[i][j] << 1));
        }
    }
    // cout << ans << endl;
    writeln(ans);
    return 0;
}