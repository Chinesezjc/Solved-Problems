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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[505], dp[505], s, cnt, head[1005], Beg, End, cur[1005], dis[1005], tot, ans, in[505], out[505];
struct edge
{
    int v, n, t;
} e[250005];
int add_edge(int F, int T, int V)
{
    e[cnt] = {V, head[F], T};
    return head[F] = cnt++;
}
bool bfs()
{
    queue<int> que;
    fill(dis, dis + tot, -1);
    dis[Beg] = 0;
    que.push(Beg);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == End)
                {
                    return true;
                }
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int now = Beg, int flow = INF)
{
    if (now == End)
    {
        return flow;
    }
    int res = 0;
    while (~cur[now] && flow)
    {
        if (dis[now] + 1 != dis[e[cur[now]].t])
        {
            cur[now] = e[cur[now]].n;
            continue;
        }
        int v = dfs(e[cur[now]].t, min(flow, e[cur[now]].v));
        e[cur[now] ^ 0].v -= v;
        e[cur[now] ^ 1].v += v;
        flow -= v;
        res += v;
        cur[now] = e[cur[now]].n;
    }
    return res;
}
void dinic()
{
    while (bfs())
    {
        copy(head, head + tot, cur);
        ans += dfs();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl
             << 1 << endl
             << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (a[j] <= a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        s = max(dp[i], s);
    }
    cout << s << endl;
    for (int i = 1; i <= n; ++i)
    {
        in[i] = tot++;
        out[i] = tot++;
    }
    Beg = tot++;
    End = tot++;
    fill(head, head + tot, -1);
    for (int i = 1; i <= n; ++i)
    {
#ifdef debug
        cout << "in[" << i << "]" << ' ' << "out[" << i << "]" << ' ' << 1 << endl;
#endif
        add_edge(in[i], out[i], 1);
        add_edge(out[i], in[i], 0);
        if (dp[i] == 1)
        {
#ifdef debug
            cout << "Beg" << ' ' << "in[" << i << "]" << ' ' << "1" << endl;
#endif
            add_edge(Beg, in[i], 1);
            add_edge(in[i], Beg, 0);
        }
        if (dp[i] == s)
        {
#ifdef debug
            cout << "out[" << i << "]" << ' ' << "End" << ' ' << "1" << endl;
#endif
            add_edge(out[i], End, 1);
            add_edge(End, out[i], 0);
        }
        for (int j = i + 1; j <= n; ++j)
        {
            if (dp[i] + 1 == dp[j] && a[i] <= a[j])
            {
#ifdef debug
                cout << "out[" << i << "]" << ' ' << "in[" << j << "]" << ' ' << "1" << endl;
#endif
                add_edge(out[i], in[j], 1);
                add_edge(in[j], out[i], 0);
            }
        }
    }
    dinic();
    cout << ans << endl;
    if (dp[1] == 1)
    {
        add_edge(Beg, in[1], INF);
        add_edge(in[1], Beg, 0);
    }
    if (dp[n] == s)
    {
        add_edge(out[n], End, INF);
        add_edge(End, out[n], 0);
    }
    add_edge(in[1], out[1], INF);
    add_edge(out[1], in[1], 0);
    add_edge(in[n], out[n], INF);
    add_edge(out[n], in[1], 0);
    dinic();
    cout << ans << endl;
    return 0;
}