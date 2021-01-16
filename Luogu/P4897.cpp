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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
#ifdef debug
unsigned long long seed = 114514;
#else
unsigned long long seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
#endif
mt19937_64 Rand(seed);
int n, m, q, cnt = 2, head[505], cur[505], dis[505], ans[505][505];
vector<pair<int, int>> son[505];
struct edge
{
    int n, t, v;
} e[6005];
void add_flow(const int &F, const int &T, const int &Flow)
{
    e[cnt] = {head[F], T, Flow};
    head[F] = cnt++;
    e[cnt] = {head[T], F, 0};
    head[T] = cnt++;
}
bool bfs(const int &s, const int &t)
{
    queue<int> que({s});
    fill(dis, dis + 1 + n, -1);
    dis[s] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == t)
                    return true;
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(const int &now, int Flow, const int &s, const int &t)
{
    if (now == t)
        return Flow;
    int res = 0;
    for (int i = cur[now]; i && Flow; i = e[i].n)
    {
        if (dis[now] + 1 == dis[e[i].t])
        {
            int tmp = dfs(e[i].t, min(Flow, e[i].v), s, t);
            Flow -= tmp;
            res += tmp;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
        }
    }
    return res;
}
int dinic(const int &s, const int &t)
{
    int res = 0;
    while (bfs(s, t))
    {
        copy(head, head + 1 + n, cur);
        res += dfs(s, INF, s, t);
    }
    return res;
}
void work(const vector<bool> &can)
{
    if (find(++find(can.begin(), can.end(), true), can.end(), true) == can.end())
        return;
    int s, t;
    do
    {
        s = Rand() % (n + 1);
        t = Rand() % (n + 1);
    } while (s == t || !can[s] || !can[t]);
#ifdef debug
    for (auto i : can)
        cout << i;
    cout << endl;
    cout << s << ' ' << t << endl;
#endif
    int v = dinic(s, t);
    vector<bool> S(n + 1), T = can;
    for (int i = 0; i <= n; ++i)
    {
        if (can[i] && ~dis[i])
        {
            S[i] = true;
            T[i] = false;
        }
        for (int j = head[i]; j; j = e[j].n)
        {
            if (j & 1)
            {
                e[j ^ 1].v += e[j].v;
                e[j].v = 0;
            }
        }
    }
    son[s].push_back({t, v});
    son[t].push_back({s, v});
    work(S);
    work(T);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, c;
        cin >> a >> b >> c;
        add_flow(a, b, c);
        add_flow(b, a, c);
    }
    work(vector<bool>(n + 1, true));
    for (int i = 0; i <= n; ++i)
    {
#ifdef debug
        for (auto j : son[i])
        {
            cout << i << ' ' << j.first << ' ' << j.second << endl;
        }
#endif
        queue<int> que({i});
        fill(ans[i], ans[i] + 1 + n, -1);
        ans[i][i] = INF;
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (auto j : son[now])
            {
                if (!~ans[i][j.first])
                {
                    ans[i][j.first] = min(ans[i][now], j.second);
                    que.push(j.first);
                }
            }
        }
    }
    cin >> q;
    while (q--)
    {
        static int a, b;
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
    return 0;
}