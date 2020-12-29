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
using namespace std;
int dp[35][35][35][35], n, m, q, ans;
bool Map[35][35];
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
class node
{
public:
    int x, y;
    inline friend istream &operator>>(istream &ist, node &__Val)
    {
        return ist >> __Val.x >> __Val.y;
    }
    inline bool operator==(const node __Val) const
    {
        return x == __Val.x && y == __Val.y;
    }
    inline node move(const int path) const
    {
        return {x + xx[path], y + yy[path]};
    }
} em, st, ed;
queue<pair<node, node>> que;
inline void add(node now, node emp, int v)
{
    if (!~dp[now.x][now.y][emp.x][emp.y])
    {
        dp[now.x][now.y][emp.x][emp.y] = v;
        if (now == ed)
        {
            ans = v;
            return;
        }
        que.push({now, emp});
    }
}
inline void bfs(node now, node emp)
{
    int v = dp[now.x][now.y][emp.x][emp.y];
    node nxt = emp.move(0);
    if (Map[nxt.x][nxt.y])
    {
        if (nxt == now)
        {
            add(emp, now, v + 1);
        }
        else
        {
            add(now, nxt, v + 1);
        }
    }
    nxt = emp.move(1);
    if (Map[nxt.x][nxt.y])
    {
        if (nxt == now)
        {
            add(emp, now, v + 1);
        }
        else
        {
            add(now, nxt, v + 1);
        }
    }
    nxt = emp.move(2);
    if (Map[nxt.x][nxt.y])
    {
        if (nxt == now)
        {
            add(emp, now, v + 1);
        }
        else
        {
            add(now, nxt, v + 1);
        }
    }
    nxt = emp.move(3);
    if (Map[nxt.x][nxt.y])
    {
        if (nxt == now)
        {
            add(emp, now, v + 1);
        }
        else
        {
            add(now, nxt, v + 1);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> Map[i][j];
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> em >> st >> ed;
        if (st == ed)
        {
            cout << 0 << endl;
            continue;
        }
        ans = -1;
        memset(dp, -1, sizeof dp);
        while (!que.empty())
        {
            que.pop();
        }
        que.push({st, em});
        dp[st.x][st.y][em.x][em.y] = 0;
        while (!que.empty() && !~ans)
        {
            bfs(que.front().first, que.front().second);
            que.pop();
        }
        cout << ans << endl;
    }
    return 0;
}