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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n, m, dis[205][205], a, b, c, tim, q;
bool open[205];
struct NODE
{
    int t, p;
    bool operator<(const NODE &TMP) const
    {
        return t < TMP.t;
    }
} g[205];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i].t;
        g[i].p = i;
    }
    sort(g + 1, g + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            dis[i][j] = dis[j][i] = INF;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        ++a;
        ++b;
        dis[a][b] = dis[b][a] = c;
    }
    cin >> q;
    g[n + 1].t = INF;
    while (q--)
    {
        cin >> a >> b >> c;
        ++a;
        ++b;
        while (g[++tim].t <= c)
        {
            open[g[tim].p] = true;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    dis[i][j] = min(dis[i][j], dis[i][g[tim].p] + dis[g[tim].p][j]);
                }
            }
        }
        --tim;
        if (open[a] && open[b])
        {
            cout << (dis[a][b] == INF ? -1 : dis[a][b]) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}