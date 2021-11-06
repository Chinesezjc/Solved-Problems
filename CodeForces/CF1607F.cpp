// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int xx[] = {0, 1, 0, -1};
const int yy[] = {1, 0, -1, 0};
const char cc[] = {'R', 'D', 'L', 'U'};
int T, n, m, dfn[2005][2005], low[2005][2005], val[2005][2005], tim;
char c[2005][2005];
struct point
{
    int x : 12, y : 12;
};
std::stack<point> sta;
std::vector<point> in;
int ansx, ansy, ans;
bool ins[2005][2005], bad[2005][2005];
char tmp;
void cmax(point now)
{
    if (val[now.x][now.y] > ans)
    {
        ansx = now.x;
        ansy = now.y;
        ans = val[now.x][now.y];
    }
}
void Tarjan(point now)
{
    dfn[now.x][now.y] = low[now.x][now.y] = ++tim;
    ins[now.x][now.y] = true;
    sta.push(now);
    if (!bad[now.x + xx[c[now.x][now.y]]][now.y + yy[c[now.x][now.y]]])
    {
        if (!dfn[now.x + xx[c[now.x][now.y]]][now.y + yy[c[now.x][now.y]]])
        {
            Tarjan({now.x + xx[c[now.x][now.y]], now.y + yy[c[now.x][now.y]]});
            low[now.x][now.y] = std::min(low[now.x][now.y],
                                         low[now.x + xx[c[now.x][now.y]]][now.y + yy[c[now.x][now.y]]]);
        }
        else if (ins[now.x + xx[c[now.x][now.y]]][now.y + yy[c[now.x][now.y]]])
            low[now.x][now.y] = std::min(low[now.x][now.y],
                                         low[now.x + xx[c[now.x][now.y]]][now.y + yy[c[now.x][now.y]]]);
        if (sta.top().x == now.x && sta.top().y == now.y)
            val[now.x][now.y] = val[now.x + xx[c[now.x][now.y]]][now.y + yy[c[now.x][now.y]]] + 1;
    }
    else
        val[now.x][now.y] = 1;
    if (dfn[now.x][now.y] == low[now.x][now.y])
    {
        if (sta.top().x != now.x || sta.top().y != now.y)
        {
            in.clear();
            val[now.x][now.y] = 1;
            while (sta.top().x != now.x || sta.top().y != now.y)
                in.push_back(sta.top()), sta.pop(), ++val[now.x][now.y];
            for (const auto &i : in)
                ins[i.x][i.y] = false, val[i.x][i.y] = val[now.x][now.y];
        }
        sta.pop();
        ins[now.x][now.y] = false;
    }
    cmax(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    memset(bad, true, sizeof(bad));
    while (T--)
    {
        std::cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> tmp, c[i][j] = std::find(cc, cc + 4, tmp) - cc, bad[i][j] = false, dfn[i][j] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (!dfn[i][j])
                    Tarjan({i, j});
        std::cout << ansx << ' ' << ansy << ' ' << ans << std::endl;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                bad[i][j] = true, val[i][j] = 0;
    }
    return 0;
}