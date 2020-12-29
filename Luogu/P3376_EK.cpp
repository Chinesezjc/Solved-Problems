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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, s, t, head[1205], a, b, c, cnt = 1, to[1205][1205], dis[1205], ans;
pair<int, int> from[1205];
queue<int> que;
struct edge
{
    int v, n, t;
} e[240005];
void add(int A, int B, int C)
{
    if (to[A][B])
    {
        e[to[A][B]].v += C;
        return;
    }
    e[to[A][B] = ++cnt] = {C, head[A], B};
    head[A] = cnt;
}
bool bfs()
{
    memset(dis, -1, sizeof(dis));
    dis[s] = INF;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (!~dis[e[i].t] && e[i].v)
            {
                dis[e[i].t] = min(dis[now], e[i].v);
                from[e[i].t] = {i, now};
                if (e[i].t == t)
                {
                    while (!que.empty())
                    {
                        que.pop();
                    }
                    return true;
                }
                que.push(e[i].t);
            }
        }
    }
    return false;
}
void update()
{
    int now = t;
    ans += dis[t];
    while (now != s)
    {
        e[from[now].first ^ 0].v -= dis[t];
        e[from[now].first ^ 1].v += dis[t];
        now = from[now].second;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, 0);
    }
    while (bfs())
    {
        update();
    }
    cout << ans << endl;
    return 0;
}