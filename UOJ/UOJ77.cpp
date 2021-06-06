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
const int INF = 0x3fffffff;
int n, a[5005], b[5005], w[5005], l[5005], r[5005], p[5005],
    id[5005], idd[5005], head[100005], dis[100005], cur[100005], ncnt, ecnt, tcnt, S, T, root;
std::vector<int> g;
bool cmpa(const int &A, const int &B) { return a[A] < a[B]; }
struct edge
{
    int n, t, v;
} e[2000005];
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
bool bfs()
{
    std::queue<int> que;
    que.push(S);
    std::fill(dis, dis + ncnt, -1);
    dis[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[now] + 1 == dis[e[i].t])
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            if (!tmp)
                dis[e[i].t] = -1;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            if (!flow)
                break;
        }
    return res;
}
int Dinic()
{
    int res = 0;
    while (bfs())
    {
        std::copy(head, head + ncnt, cur);
        res += dfs();
    }
    return res;
}
struct node
{
    int lson, rson, to;
    node() : lson(-1), rson(-1), to(-1) {}
} tree[200005];
#define mid ((l + r) >> 1)
int build(int l = 0, int r = n)
{
    int now = tcnt++;
    tree[now].to = ncnt++;
    if (r - l != 1)
    {
        add_flow(tree[tree[now].lson = build(l, mid)].to, tree[now].to, INF);
        add_flow(tree[tree[now].rson = build(mid, r)].to, tree[now].to, INF);
    }
    return now;
}
int add(int pos, int from, int old = root, int l = 0, int r = n)
{
    int now = tcnt++;
    tree[now].to = ncnt++;
    if (r - l == 1)
        add_flow(from, tree[now].to, INF);
    else
    {
        add_flow(tree[tree[now].lson = (pos < mid ? add(pos, from, tree[old].lson, l, mid) : tree[old].lson)].to,
                 tree[now].to, INF);
        add_flow(tree[tree[now].rson = (pos < mid ? tree[old].rson : add(pos, from, tree[old].rson, mid, r))].to,
                 tree[now].to, INF);
    }
    return now;
}
void connect(int L, int R, int to, int now = root, int l = 0, int r = n)
{
    if (L <= l && r <= R)
        return add_flow(tree[now].to, to, INF);
    if (L < mid)
        connect(L, R, to, tree[now].lson, l, mid);
    if (mid < R)
        connect(L, R, to, tree[now].rson, mid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i] >> w[i] >> l[i] >> r[i] >> p[i];
    for (int i = 1; i <= n; ++i)
        g.push_back(i);
    std::sort(g.begin(), g.end(), cmpa);
    for (int i = 0; i != n; ++i)
    {
        int tmp = g[i];
        g[i] = a[tmp];
        a[tmp] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        l[i] = std::lower_bound(g.begin(), g.end(), l[i]) - g.begin();
        r[i] = std::upper_bound(g.begin(), g.end(), r[i]) - g.begin();
    }
    memset(head, -1, sizeof(head));
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= n; ++i)
    {
        id[i] = ncnt++;
        idd[i] = ncnt++;
    }
    root = build();
    for (int i = 1; i <= n; ++i)
    {
        add_flow(S, id[i], w[i]);
        add_flow(id[i], T, b[i]);
        add_flow(idd[i], id[i], p[i]);
        // for (int j = 1; j < i; ++j)
        //     if (l[i] <= a[j] && a[j] <= r[i])
        //         add_flow(id[j], idd[i], INF);
        if (l[i] != r[i])
            connect(l[i], r[i], idd[i]);
        root = add(a[i], id[i]);
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += w[i] + b[i];
    std::cout << sum - Dinic() << std::endl;
    return 0;
}