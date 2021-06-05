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
int n, k, fa[2005], ide[2005], ncnt, ecnt, idp[2005], head[20005], d[20005], S, T, SS, TT, dis[20005], cur[20005];
bool in[2005];
std::vector<int> to[2005];
std::map<int, int> idc;
std::vector<int> works[20005];
int init(int now)
{
    static int from[2005];
    if (now == 1)
        from[now] = -1;
    for (auto i : to[now])
    {
        if (!from[i])
        {
            from[i] = now;
            int res = init(i);
            if (res)
            {
                in[now] = true;
                return now == res ? 0 : res;
            }
        }
        else if (from[now] != i)
            return in[now] = true, i;
    }
    return 0;
}
struct edge
{
    int n, t, v;
} e[50005];
void add_edge(int A, int B, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int V)
{
    add_edge(A, B, V);
    add_edge(B, A, 0);
}
void add_bound(int A, int B, int L, int R)
{
    d[A] += L;
    d[B] -= L;
    if (L < R)
        add_flow(A, B, R - L);
}
bool bfs(int s, int t)
{
    std::fill(dis, dis + ncnt, -1);
    dis[s] = 0;
    std::queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == t)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now, int t, int flow = INF)
{
    if (now == t || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, t, std::min(e[i].v, flow));
            if (!tmp)
                dis[e[i].t] = -1;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            res += tmp;
            flow -= tmp;
            if (!flow)
                break;
        }
    return res;
}
int Dinic(int s, int t)
{
    int res = 0;
    while (bfs(s, t))
    {
        std::copy(head, head + ncnt, cur);
        res += dfs(s, t);
    }
    return res;
}
void print()
{
    for (int i = 0; i != ncnt; ++i)
        for (int j = head[i]; ~j; j = e[j].n)
            if (j % 2 == 0)
                std::cout << i << ' ' << e[j].t << ' ' << e[j].v << std::endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    memset(head, -1, sizeof(head));
    S = ncnt++;
    T = ncnt++;
    SS = ncnt++;
    TT = ncnt++;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> fa[i] >> x;
        to[fa[i]].push_back(i);
        to[i].push_back(fa[i]);
        ide[i] = ncnt++;
        for (int j = 0; j != x; ++j)
        {
            static int y;
            std::cin >> y;
            std::pair<std::map<int, int>::iterator, bool> res = idc.insert(std::make_pair(y, ncnt));
            if (res.second)
                ++ncnt;
            add_flow(res.first->second, ide[i], 1);
        }
    }
    init(1);
    for (int i = 1; i <= n; ++i)
        if (in[i] && in[fa[i]])
            add_flow(ide[i], T, 1);
        else
            add_bound(ide[i], T, 1, 1);
    for (int i = 1; i <= k; ++i)
    {
        idp[i] = ncnt++;
        static int c;
        std::cin >> c;
        add_flow(idp[i], idc[c], 1);
        add_flow(S, idp[i], 1);
    }
    int need = 0;
    for (int i = 0; i != ncnt; ++i)
        if (d[i] > 0)
            add_flow(i, TT, +d[i]), need += d[i];
        else if (d[i] < 0)
            add_flow(SS, i, -d[i]);
    add_flow(T, S, INF);
    if (need != Dinic(SS, TT))
        return std::cout << -1 << std::endl, 0;
    if (Dinic(S, T) < n - 1)
        return std::cout << -1 << std::endl, 0;
    for (auto i : idc)
        for (int j = head[i.second]; ~j; j = e[j].n)
            if (~j & 1 && !e[j].v)
                works[i.second].push_back(e[j].t);
    for (int i = 1; i <= k; ++i)
        for (int j = head[idp[i]]; ~j; j = e[j].n)
            if (~j & 1)
            {
                if (e[j].v)
                    std::cout << 0 << ' ' << 0 << std::endl;
                else
                {
                    int tmp = std::find(ide + 1, ide + 1 + n, works[e[j].t].back()) - ide;
                    works[e[j].t].pop_back();
                    std::cout << tmp << ' ' << fa[tmp] << std::endl;
                }
            }
    return 0;
}