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
int n, m, Beg, End, l, r, tot;
struct EDGE
{
    int f, t, a, b;
};
struct edge
{
    int n, t, v, p;
};
int flow[1005], fa[1005];
vector<int> head, dis, cur;
vector<EDGE> a;
vector<edge> e;
vector<int> to[1005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
int add_edge(int F, int T, int V, int P)
{
    int res = e.size();
    e.push_back({head[F], T, V, P});
    return head[F] = res;
}
int add_flow(int F, int T, int V, int P)
{
    int res = add_edge(F, T, V, P);
    add_edge(T, F, 0, -1);
    return res;
}
bool bfs()
{
    queue<int> que;
    que.push(Beg);
    dis.assign(n + 2, -1);
    dis[Beg] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
#ifdef debug
                cout << "SHIT " << e[i].v << endl;
#endif
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
int dfs(int now = Beg, int flw = INF)
{
    if (now == End)
    {
        return flw;
    }
    int res = 0;
    while (~cur[now] && flw)
    {
        if (dis[now] + 1 == dis[e[cur[now]].t])
        {
            int v = dfs(e[cur[now]].t, min(flw, e[cur[now]].v));
            e[cur[now] ^ 0].v -= v;
            e[cur[now] ^ 1].v += v;
            flw -= v;
            res += v;
        }
        if (flw)
        {
            cur[now] = e[cur[now]].n;
        }
    }
    return res;
}
bool check(const int &now)
{
    head.assign(n + 2, -1);
    fill(flow + 1, flow + 1 + n, 0);
    e.clear();
    for (int i = 0; i < (int)a.size(); ++i)
    {
        if (a[i].b <= now)
        {
#ifdef debug
            cout << a[i].f << ' ' << a[i].t << ' ' << 2 << endl;
#endif
            add_flow(a[i].f, a[i].t, 2, i);
        }
        if (a[i].a <= now)
        {
            ++flow[a[i].f];
            --flow[a[i].t];
        }
        else
        {
            return false;
        }
    }
    int add = 0, sub = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (flow[i] & 1)
        {
            return false;
        }
        if (flow[i] > 0)
        {
#ifdef debug
            cout << Beg << ' ' << i << ' ' << +flow[i] << endl;
#endif
            add_flow(Beg, i, +flow[i], -1);
            add += flow[i];
        }
        if (flow[i] < 0)
        {
#ifdef debug
            cout << i << ' ' << End << ' ' << -flow[i] << endl;
#endif
            add_flow(i, End, -flow[i], -1);
            sub -= flow[i];
        }
    }
    if (add != sub)
    {
        return false;
    }
    int res = 0;
    while (bfs())
    {
#ifdef debug
        cout << res << endl;
#endif
        cur = head;
        res += dfs();
    }
    if (res == add)
    {
        return true;
    }
    return false;
}
bool allsame()
{
    for (int i = 1; i < n; ++i)
    {
        if (find(i) != find(i + 1))
        {
            return false;
        }
    }
    return true;
}
list<int> work(int u)
{
    list<int> res;
    int now = u;
    do
    {
        int nxt = to[now].back();
        res.push_back(nxt);
        to[now].pop_back();
        now = a[nxt].t;
    } while (now != u);
    for (list<int>::iterator i = res.begin(); i != res.end(); ++i)
    {
        while (!to[a[*i].f].empty())
        {
            res.splice(i, work(a[*i].f));
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    End = n + 1;
    tot = n + 2;
    a.resize(m);
    while (m--)
    {
        cin >> a[m].f >> a[m].t >> a[m].a >> a[m].b;
        fa[find(a[m].f)] = find(a[m].t);
        if (a[m].a > a[m].b)
        {
            swap(a[m].f, a[m].t);
            swap(a[m].a, a[m].b);
        }
        l = max(l, a[m].a);
        r = max(r, a[m].b);
    }
    if (!allsame() || !check(r))
    {
        cout << "NIE" << endl;
        return 0;
    }
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    check(l);
    for (int i = 0; i < (int)e.size(); ++i)
    {
        if (~e[i].p && !e[i].v)
        {
            swap(a[e[i].p].f, a[e[i].p].t);
            swap(a[e[i].p].a, a[e[i].p].b);
        }
    }
    // for (int i = 0; i < a.size(); ++i)
    // {
    //     cout << a[i].f << ' ' << a[i].t << endl;
    // }
    for (int i = 0; i < (int)a.size(); ++i)
    {
        to[a[i].f].push_back(i);
    }
    list<int> ans = work(1);
    for (list<int>::iterator i = ans.begin(); i != ans.end(); ++i)
    {
        cout << a.size() - *i << ' ';
    }
    cout << endl;
    return 0;
}