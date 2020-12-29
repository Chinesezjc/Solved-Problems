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
int n, m, s, t, cnt = 1, head[5005], a, b, c, d, ans, anss;
pair<int, int> from[5005], dis[5005];
queue<int> que;
bool in[5005];
struct edge
{
    int n, t, cap, cost;
} e[100005];
void add(int F, int T, int CAP, int COST)
{
    e[++cnt] = {head[F], T, CAP, COST};
    head[F] = cnt;
}
bool operator>(const pair<int, int> &A, const pair<int, int> &B)
{
    return A.first == B.first ? A.second < B.second : A.first > B.first;
}
bool spfa()
{
    fill(dis + 1, dis + 1 + n, make_pair(INF, INF));
    dis[s] = {0, INF};
    in[s] = true;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        in[now] = false;
        que.pop();
        for (int i = head[now]; i; i = e[i].n)
        {
            if (e[i].cap == 0)
            {
                continue;
            }
            pair<int, int> nxt = {dis[now].first + e[i].cost, min(dis[now].second, e[i].cap)};
            if (dis[e[i].t] > nxt)
            {
                dis[e[i].t] = nxt;
                from[e[i].t] = {now, i};
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << "(" << dis[i].first << "," << dis[i].second << ")";
    // }
    // cout << endl;
    // for (int i = 1; i <= cnt; ++i)
    // {
    //     cout << e[i].cap << ' ' << e[i].t << ' ' << e[i].cost << endl;
    // }
    return dis[t] != make_pair(INF, INF);
}
void update()
{
    int now = t;
    ans += dis[t].second;
    anss += dis[t].first * dis[t].second;
    while (now != s)
    {
        e[from[now].second ^ 0].cap -= dis[t].second;
        e[from[now].second ^ 1].cap += dis[t].second;
        now = from[now].first;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c >> d;
        add(a, b, c, +d);
        add(b, a, 0, -d);
    }
    while (spfa())
    {
        // cout << ans << endl;
        update();
    }
    cout << ans << ' ' << anss << endl;
    return 0;
}