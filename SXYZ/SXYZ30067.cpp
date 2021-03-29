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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
enum side
{
    L = 0,
    R = 1,
    U = 2
};
class tree
{
public:
    int x, y, rk, l, r, u, lu, ru;
} t[50005];
int n, dp[3][50005], in[3][50005];
int need[50005], head[50005], cur[50005], id[50005], S, T, SS, TT, ncnt, ecnt, dis[50005];
std::vector<std::pair<side, int>> from[3][50005];
std::map<int, std::map<int, int>> g;
std::queue<std::pair<side, int>> que;
struct edge
{
    int n, t, flow;
} e[600005];
void add_edge(int A, int B, int FLOW)
{
    e[ecnt] = {head[A], B, FLOW};
    head[A] = ecnt++;
}
void add_flow(int A, int B, int FLOW)
{
    add_edge(A, B, FLOW);
    add_edge(B, A, 0);
}
void add_bound(int A, int B, int L, int R)
{
    if (L > R)
        return;
    need[A] += L;
    need[B] -= L;
    add_flow(A, B, R - L);
}
void add(side f, int A)
{
    if (~A)
        ++in[f][A];
}
void update(side Af, int A, side Bf, int B)
{
    if (!~A)
        return;
    int val = dp[Bf][B] + 1;
    switch (Af)
    {
    case L:
        if (Bf == U)
            val += g[t[B].y].size() - t[B].rk;
        break;
    case R:
        if (Bf == U)
            val += t[B].rk - 1;
        break;
    case U:
        break;
    }
    if (dp[Af][A] < val)
    {
        dp[Af][A] = val;
        from[Af][A].clear();
    }
    if (dp[Af][A] == val)
        from[Af][A].push_back(std::make_pair(Bf, B));
    --in[Af][A];
    if (!in[Af][A])
        que.push(std::make_pair(Af, A));
}
void print(std::pair<side, int> pos)
{
    if (!pos.second)
        return;
    std::pair<side, int> lst = from[pos.first][pos.second].front();
    print(lst);
    if (t[lst.second].y == t[pos.second].y &&
        lst.first == U)
        switch (pos.first)
        {
        case L:
            for (std::map<int, int>::iterator i = g[t[lst.second].y].upper_bound(t[lst.second].x);
                 i != g[t[lst.second].y].end(); ++i)
                std::cout << i->second << ' ';
            break;
        case R:
            for (std::map<int, int>::iterator i = g[t[lst.second].y].lower_bound(t[lst.second].x);
                 i-- != g[t[lst.second].y].begin();)
                std::cout << i->second << ' ';
            break;
        case U:
            break;
        }
    std::cout << pos.second // << "."
              << ' ';
}
void init(int val)
{
    memset(head, -1, sizeof(head));
    std::queue<std::pair<side, int>> q;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j <= n; ++j)
            if (val == dp[i][j])
            {
                in[i][j] = true;
                q.push(std::make_pair(side(i), j));
            }
    for (int i = 0; i <= n; ++i)
        id[i] = ncnt++;
    S = ncnt++;
    T = ncnt++;
    SS = ncnt++;
    TT = ncnt++;
    for (int i = 0; i <= n; ++i)
    {
        add_flow(S, id[i], INF);
        add_flow(id[i], T, INF);
    }
    std::vector<std::pair<int, int>> edges;
#ifdef debug
    std::cout << "Size:" << q.size() << std::endl;
#endif
    while (!q.empty())
    {
        std::pair<side, int> now = q.front();
        q.pop();
        for (int i = 0; i < from[now.first][now.second].size(); ++i)
        {
            std::pair<side, int> lst = from[now.first][now.second][i];
            if (!in[lst.first][lst.second])
            {
                in[lst.first][lst.second] = true;
                q.push(lst);
            }
            if (t[lst.second].y != t[now.second].y)
                edges.push_back(std::make_pair(id[lst.second], id[now.second]));
        }
    }
    std::sort(edges.begin(), edges.end());
    edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
    for (int i = 0; i < edges.size(); ++i)
        add_bound(edges[i].first, edges[i].second, 1, INF);
    add_flow(T, S, INF);
    for (int i = 0; i < ncnt; ++i)
    {
        if (need[i] > 0)
            add_flow(i, TT, +need[i]);
        if (need[i] < 0)
            add_flow(SS, i, -need[i]);
    }
}
bool bfs(int beg, int end)
{
    std::fill(dis, dis + ncnt, -1);
    std::queue<int> q;
    q.push(beg);
    dis[beg] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].flow && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == end)
                    return true;
                q.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int now, int end, int flow = INF)
{
    if (now == end)
        return flow;
    int &i = cur[now], res = 0;
    while (~i)
    {
        if (e[i].flow && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, end, std::min(flow, e[i].flow));
            e[i].flow -= tmp;
            e[i ^ 1].flow += tmp;
            res += tmp;
            flow -= tmp;
            if (!flow)
                return res;
        }
        i = e[i].n;
    }
    return res;
}
int Dinic(int beg, int end)
{
    int res = 0;
    while (bfs(beg, end))
    {
        std::copy(head, head + ncnt, cur);
        res += dfs(beg, end);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> t[i].x >> t[i].y;
    for (int i = 0; i <= n; ++i)
        t[i].l = t[i].r = t[i].lu = t[i].ru = t[i].u = -1;

    g.clear(); // left and right
    for (int i = 0; i <= n; ++i)
        g[t[i].y][t[i].x] = i;
    for (std::map<int, std::map<int, int>>::iterator i = g.begin(); i != g.end(); ++i)
    {
        std::map<int, int>::iterator now, nxt = i->second.begin();
        while (now = nxt++, nxt != i->second.end())
        {
            t[now->second].r = nxt->second;
            t[nxt->second].l = now->second;
        }
    }

    g.clear(); // up
    for (int i = 0; i <= n; ++i)
        g[t[i].x][t[i].y] = i;
    for (std::map<int, std::map<int, int>>::iterator i = g.begin(); i != g.end(); ++i)
    {
        std::map<int, int>::iterator now, nxt = i->second.begin();
        while (now = nxt++, nxt != i->second.end())
            t[now->second].u = nxt->second;
    }

    g.clear(); // left-up
    for (int i = 0; i <= n; ++i)
        g[t[i].y + t[i].x][t[i].y] = i;
    for (std::map<int, std::map<int, int>>::iterator i = g.begin(); i != g.end(); ++i)
    {
        std::map<int, int>::iterator now, nxt = i->second.begin();
        while (now = nxt++, nxt != i->second.end())
            t[now->second].lu = nxt->second;
    }

    g.clear(); // right up
    for (int i = 0; i <= n; ++i)
        g[t[i].y - t[i].x][t[i].y] = i;
    for (std::map<int, std::map<int, int>>::iterator i = g.begin(); i != g.end(); ++i)
    {
        std::map<int, int>::iterator now, nxt = i->second.begin();
        while (now = nxt++, nxt != i->second.end())
            t[now->second].ru = nxt->second;
    }

    g.clear(); // DP
    std::fill(dp[L] + 1, dp[L] + n + 1, -INF);
    std::fill(dp[R] + 1, dp[R] + n + 1, -INF);
    std::fill(dp[U] + 1, dp[U] + n + 1, -INF);
    for (int i = 0; i <= n; ++i)
    {
        // L
        add(L, t[i].l);
        add(U, t[i].u);
        add(U, t[i].lu);
        add(U, t[i].ru);

        // R
        add(R, t[i].r);
        add(U, t[i].u);
        add(U, t[i].lu);
        add(U, t[i].ru);

        // U
        add(L, t[i].l);
        add(R, t[i].r);
        add(U, t[i].u);
        add(U, t[i].lu);
        add(U, t[i].ru);
    }
    for (int i = 0; i <= n; ++i)
    {
        if (!in[L][i])
            que.push(std::make_pair(L, i));
        if (!in[R][i])
            que.push(std::make_pair(R, i));
        if (!in[U][i])
            que.push(std::make_pair(U, i));
    }
    for (int i = 0; i <= n; ++i)
        g[t[i].y][t[i].x] = i;
    for (std::map<int, std::map<int, int>>::iterator i = g.begin(); i != g.end(); ++i)
    {
        int rk = 0;
        for (std::map<int, int>::iterator j = i->second.begin(); j != i->second.end(); ++j)
            t[j->second].rk = ++rk;
    }
    while (!que.empty())
    {
        std::pair<side, int> now = que.front();
        que.pop();
        switch (now.first)
        {
        case L:
            update(L, t[now.second].l, L, now.second);
            update(U, t[now.second].u, L, now.second);
            update(U, t[now.second].lu, L, now.second);
            update(U, t[now.second].ru, L, now.second);
            break;
        case R:
            update(R, t[now.second].r, R, now.second);
            update(U, t[now.second].u, R, now.second);
            update(U, t[now.second].lu, R, now.second);
            update(U, t[now.second].ru, R, now.second);
            break;
        case U:
            update(L, t[now.second].l, U, now.second);
            update(R, t[now.second].r, U, now.second);
            update(U, t[now.second].u, U, now.second);
            update(U, t[now.second].lu, U, now.second);
            update(U, t[now.second].ru, U, now.second);
            break;
        }
    }
    int *MaxL = std::max_element(dp[L], dp[L] + 1 + n),
        *MaxR = std::max_element(dp[R], dp[R] + 1 + n),
        *MaxU = std::max_element(dp[U], dp[U] + 1 + n),
        Max = std::max({*MaxL, *MaxR, *MaxU});
    std::cout << Max << std::endl;
    if (*MaxL >= *MaxR && *MaxL >= *MaxU)
        print(std::make_pair(L, MaxL - dp[L]));
    else if (*MaxR >= *MaxL && *MaxR >= *MaxU)
        print(std::make_pair(R, MaxR - dp[R]));
    else
        print(std::make_pair(U, MaxU - dp[U]));
    std::cout << std::endl;

    // Network-Flows
    init(Max);
#ifdef debug
    for (int i = 0; i < ncnt; ++i)
    {
        for (int j = head[i]; ~j; j = e[j].n)
        {
            if (j % 2 == 0)
                std::cout << i << ' ' << e[j].t << ' '
                          << (e[j].flow >= INF ? "INF" : std::to_string(e[j].flow)) << std::endl;
        }
    }
#endif
    Dinic(SS, TT);
    std::cout << INF - Dinic(T, S) << std::endl;
    return 0;
}