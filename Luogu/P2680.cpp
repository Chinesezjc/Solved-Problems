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
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a, b, c, depth[300005], fa[20][300005], st[20][300005], dis[300005], l, r, MAXC;
struct edge
{
    int t, v;
};
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
    {
        swap(A, B);
    }
    for (int i = 19; i >= 0; --i)
    {
        if (depth[fa[i][A]] >= depth[B])
        {
            A = fa[i][A];
        }
    }
    if (A == B)
    {
        return A;
    }
    for (int i = 19; i >= 0; --i)
    {
        if (fa[i][A] != fa[i][B])
        {
            A = fa[i][A];
            B = fa[i][B];
        }
    }
    return fa[0][A];
}
bool cmp(const int &A, const int &B)
{
    return depth[A] > depth[B];
}
struct query
{
    int f, t, lca, v;
    query()
    {
        f = t = lca = v = 0;
    }
    query(int A, int B)
    {
        f = A;
        t = B;
        lca = LCA(A, B);
        v = dis[A] + dis[B] - (dis[lca] << 1);
    }
    bool operator<(const query &__Val) const
    {
        return v > __Val.v;
    }
    // query operator+(const query &__Val) const
    // {
    //     query res;
    //     res.lca = depth[lca] < depth[__Val.lca] ? lca : __Val.lca;
    //     res.v = v + __Val.v;
    //     if (f == __Val.f)
    //     {
    //         res.f = t;
    //         res.t = __Val.t;
    //     }
    //     if (f == __Val.t)
    //     {
    //         res.f = t;
    //         res.t = __Val.f;
    //     }
    //     if (t == __Val.f)
    //     {
    //         res.f = f;
    //         res.t = __Val.t;
    //     }
    //     if (t == __Val.t)
    //     {
    //         res.f = f;
    //         res.t = __Val.f;
    //     }
    //     return res;
    // }
    query operator&(const query &__Val) const
    {
        int lcas[4] = {LCA(f, __Val.f), LCA(f, __Val.t), LCA(t, __Val.f), LCA(t, __Val.t)};
        sort(lcas, lcas + 4, cmp);
        return query(lcas[0], lcas[1]);
    }
} q[300005];
vector<edge> son[300005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
    {
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
        st[i][now] = max(st[i - 1][now], st[i - 1][fa[i - 1][now]]);
    }
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (fa[0][now] == son[now][i].t)
        {
            swap(son[now][i], son[now].back());
            --i;
            son[now].pop_back();
            continue;
        }
        fa[0][son[now][i].t] = now;
        st[0][son[now][i].t] = son[now][i].v;
        depth[son[now][i].t] = depth[now] + 1;
        dis[son[now][i].t] = dis[now] + son[now][i].v;
        init(son[now][i].t);
    }
}
bool check(int now)
{
    query sum = q[1];
    for (int i = 2; i <= m && q[i].v > now; ++i)
    {
        sum = sum & q[i];
        if (sum.f == sum.t)
        {
            return false;
        }
    }
    int res = 0;
    if (depth[sum.f] < depth[sum.t])
    {
        swap(sum.f, sum.t);
    }
    for (int i = 19; i >= 0; --i)
    {
        if (depth[fa[i][sum.f]] >= depth[sum.t])
        {
            res = max(res, st[i][sum.f]);
            sum.f = fa[i][sum.f];
        }
    }
    if (sum.f == sum.t)
    {
        return q[1].v - res <= now;
    }
    for (int i = 19; i >= 0; --i)
    {
        if (fa[i][sum.f] != fa[i][sum.t])
        {
            res = max(res, max(st[i][sum.f], st[i][sum.t]));
            sum.f = fa[i][sum.f];
            sum.t = fa[i][sum.t];
        }
    }
    res = max(res, max(st[0][sum.f], st[0][sum.t]));
    return q[1].v - res <= now;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
        MAXC = max(MAXC, c);
    }
    depth[0] = -1;
    init(1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        q[i] = query(a, b);
    }
    sort(q + 1, q + 1 + m);
    l = q[1].v - MAXC;
    r = q[1].v;
    while (l < r)
    {
        int mid = (l + r) >> 1;
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
    return 0;
}