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
int n, m, v[1005], a[64], b[64], cnt, dis[1005], head[1005], ahead[1005], acnt, S, T, ans[1005], cur[1005];
unsigned long long Q, c[1005];
struct INT
{
    std::bitset<1005> ma;
    unsigned long long val;
    INT() : ma(), val() {}
    INT(int x)
    {
        ma[x] = true;
        val = c[x];
    }
    bool operator!() const { return !val; }
    unsigned long long operator>>(const int &Val) const { return val >> Val; }
    INT &operator^=(const INT &Val)
    {
        ma ^= Val.ma;
        val ^= Val.val;
        return *this;
    }
};
struct J
{
    INT val[64];
    J() {}
    void insert(INT v)
    {
        for (int i = 64; i--;)
        {
            if (!(v >> i & 1))
                continue;
            if (!val[i])
            {
                for (int j = 0; j != i; ++j)
                    if ((v >> j) & 1)
                        v ^= val[j];
                val[i] = v;
                for (int j = 64; --j != i;)
                    if ((val[j] >> i) & 1)
                        val[j] ^= v;
                return;
            }
            v ^= val[i];
        }
    }
    std::bitset<1005> has(unsigned long long v)
    {
        std::bitset<1005> res;
        for (int i = 64; i--;)
        {
            if (!(v >> i & 1))
                continue;
            if (!val[i])
                return std::bitset<1005>();
            v ^= val[i].val;
            res ^= val[i].ma;
        }
        return res;
    }
} A, B;
struct edge
{
    int n, t, v;
} e[500005];
void add_edge(int A, int B, int FLOW)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].v = FLOW;
    head[A] = cnt++;
}
void add_flow(int A, int B, int FLOW)
{
    add_edge(A, B, FLOW);
    add_edge(B, A, FLOW);
}
unsigned long long sqr(unsigned long long v) { return v * v; }
bool bfs()
{
    std::queue<int> que;
    que.push(S);
    memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        // std::cout << now << std::endl;
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now = S, int Flow = INF)
{
    if (now == T)
        return Flow;
    int res = 0, &i = cur[now];
    while (Flow && ~i)
    {
        if (dis[now] + 1 == dis[e[i].t] && e[i].v)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, Flow));
            res += tmp;
            Flow -= tmp;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            if (!Flow)
                break;
        }
        i = e[i].n;
    }
    return res;
}
void Dinic()
{
    while (bfs())
    {
        std::copy(head, head + n + 2, cur);
        dfs();
    }
}
void visit(int now, std::bitset<1005> &vis)
{
    vis[now] = true;
    for (int i = head[now]; ~i; i = e[i].n)
        if (e[i].v && !vis[e[i].t])
            visit(e[i].t, vis);
}
void solve(std::bitset<1005> s, int l, int r)
{
    if (!s.count())
        return;
    if (l == r)
    {
        for (int i = 0; i != n; ++i)
            if (s[i])
                ans[i] = l;
        return;
    }
    int mid = (l + r) >> 1;
    std::copy(ahead, ahead + n + 2, head);
    cnt = acnt;
    for (int i = 0; i != cnt; ++i)
        if (i & 1)
            e[i].v = 0;
        else
            e[i].v += e[i ^ 1].v;
    for (int i = 0; i != n; ++i)
        if (s[i])
        {
            // std::cout << i << std::endl;
            // _sleep(1000);
            if (sqr(v[i] - mid) > sqr(v[i] - mid - 1))
                add_flow(S, i, sqr(v[i] - mid) - sqr(v[i] - mid - 1));
            else
                add_flow(i, T, sqr(v[i] - mid - 1) - sqr(v[i] - mid));
        }
    Dinic();
    std::bitset<1005> yes;
    visit(S, yes);
    solve(s & ~yes, l, mid);
    solve(s & yes, mid + 1, r);
}
signed main()
{
    memset(head, -1, sizeof(head));
    std::bitset<1005> r;
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        std::cin >> c[i];
    for (int i = 0; i != n; ++i)
        std::cin >> v[i];
    for (int i = 0; i != m; ++i)
        std::cin >> a[i];
    for (int i = 0; i != m; ++i)
        std::cin >> b[i];
    for (int i = 0; i != m; ++i)
        A.insert(--a[i]);
    for (int i = 0; i != m; ++i)
        B.insert(--b[i]);
    for (int i = 0; i != n; ++i)
        if (!std::count(a, a + m, i) && (r = A.has(c[i])).count())
            for (int j = 0; j != n; ++j)
                if (r[j])
                    add_flow(j, i, INF);
    for (int i = 0; i != n; ++i)
        if (!std::count(b, b + m, i) && (r = B.has(c[i])).count())
            for (int j = 0; j != n; ++j)
                if (r[j])
                    add_flow(i, j, INF);
    S = n;
    T = n + 1;
    std::copy(head, head + n + 2, ahead);
    acnt = cnt;
    r.set();
    solve(r, 0, 1000000);
    for (int i = 0; i != n; ++i)
        Q += sqr(ans[i] - v[i]);
    std::cout << Q << std::endl;
    return 0;
}