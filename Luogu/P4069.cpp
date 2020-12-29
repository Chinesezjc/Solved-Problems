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
// #include<windows.h>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a, b, c, d, e, top[100005], fa[100005], depth[100005], dis[100005], siz[100005], dfn[100005];
int cnt, tim, to[100005], pos[100005];
vector<pair<int, int>> son[100005];
vector<int> in[100005];
void init(int now)
{
    siz[now] = 1;
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (son[now][i].first == fa[now])
        {
            swap(son[now][i], son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i].first] = now;
        depth[son[now][i].first] = depth[now] + 1;
        dis[son[now][i].first] = dis[now] + son[now][i].second;
        init(son[now][i].first);
        siz[now] += siz[son[now][i].first];
        if (siz[son[now][i].first] > siz[son[now].front().first])
        {
            swap(son[now][i], son[now].front());
        }
    }
}
void dfs(int now)
{
    in[to[now] = cnt].push_back(now);
    if (!son[now].empty())
    {
        top[son[now].front().first] = top[now];
        pos[son[now].front().first] = pos[now] + son[now].front().second;
        dfs(son[now].front().first);
    }
    for (int i = 1; i < (int)son[now].size(); ++i)
    {
        top[son[now][i].first] = son[now][i].first;
        pos[son[now][i].first] = 0;
        dfn[++cnt] = son[now][i].first;
        dfs(son[now][i].first);
    }
}
int y(pair<int, int> func, int x)
{
    return func.first * x + func.second;
}
int LCA(int A, int B)
{
    while (top[A] != top[B])
    {
        if (depth[top[A]] > depth[top[B]])
            A = fa[top[A]];
        else
            B = fa[top[B]];
    }
    if (depth[A] > depth[B])
        return B;
    else
        return A;
}
struct node
{
    int lson, rson, l, r, ty, Min;
    pair<int, int> v;
    node() = default;
    node(const int &LSON, const int &RSON, const int &LL, const int &RR, const int &TY)
    {
        lson = LSON;
        rson = RSON;
        l = LL;
        r = RR;
        ty = TY;
        Min = 123456789123456789;
        v = {0, 123456789123456789};
    }
} tree[1 << 18];
void _M_insert(const int &now, pair<int, int> v)
{
    if (y(v, pos[in[tree[now].ty][tree[now].l]]) >= y(tree[now].v, pos[in[tree[now].ty][tree[now].l]]) &&
        y(v, pos[in[tree[now].ty][tree[now].r]]) >= y(tree[now].v, pos[in[tree[now].ty][tree[now].r]]))
    {
        return;
    }
    if (y(v, pos[in[tree[now].ty][tree[now].l]]) <= y(tree[now].v, pos[in[tree[now].ty][tree[now].l]]) &&
        y(v, pos[in[tree[now].ty][tree[now].r]]) <= y(tree[now].v, pos[in[tree[now].ty][tree[now].r]]))
    {
        tree[now].v = v;
        tree[now].Min = min(tree[now].Min, min(y(tree[now].v, pos[in[tree[now].ty][tree[now].l]]),
                                               y(tree[now].v, pos[in[tree[now].ty][tree[now].r]])));
        return;
    }
    int mid = (tree[now].l + tree[now].r) >> 1;
    if (y(v, pos[in[tree[now].ty][mid]]) < y(tree[now].v, pos[in[tree[now].ty][mid]]))
    {
        swap(v, tree[now].v);
        tree[now].Min = min(tree[now].Min, min(y(tree[now].v, pos[in[tree[now].ty][tree[now].l]]),
                                               y(tree[now].v, pos[in[tree[now].ty][tree[now].r]])));
    }
    if (tree[now].l < tree[now].r)
    {
        if (!~tree[now].lson)
        {
            tree[tree[now].lson = ++tim] = {-1, -1, tree[now].l, mid, tree[now].ty};
        }
        if (!~tree[now].rson)
        {
            tree[tree[now].rson = ++tim] = {-1, -1, mid + 1, tree[now].r, tree[now].ty};
        }
        _M_insert(tree[now].lson, v);
        _M_insert(tree[now].rson, v);
        tree[now].Min = min(tree[now].Min, min(tree[tree[now].lson].Min, tree[tree[now].rson].Min));
    }
}
void insert(const int &L, const int &R, const int &now, const pair<int, int> &v)
{
    if (L <= tree[now].l && tree[now].r <= R)
    {
        // cout << L << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << R << endl;
        _M_insert(now, v);
        return;
    }
    int mid = (tree[now].l + tree[now].r) >> 1;
    if (L <= mid)
    {
        if (!~tree[now].lson)
        {
            tree[tree[now].lson = ++tim] = {-1, -1, tree[now].l, mid, tree[now].ty};
        }
        insert(L, R, tree[now].lson, v);
        tree[now].Min = min(tree[now].Min, tree[tree[now].lson].Min);
    }
    if (mid < R)
    {
        if (!~tree[now].rson)
        {
            tree[tree[now].rson = ++tim] = {-1, -1, mid + 1, tree[now].r, tree[now].ty};
        }
        insert(L, R, tree[now].rson, v);
        tree[now].Min = min(tree[now].Min, tree[tree[now].rson].Min);
    }
}
int query(const int &L, const int &R, const int &now)
{
    if (now == -1 || tree[now].r < L || tree[now].l > R)
    {
        return 123456789123456789;
    }
    if (L <= tree[now].l && tree[now].r <= R)
    {
        return tree[now].Min;
    }
    return min(min(y(tree[now].v, pos[in[tree[now].ty][max(tree[now].l, L)]]),
                   y(tree[now].v, pos[in[tree[now].ty][min(tree[now].r, R)]])),
               min(query(L, R, tree[now].lson), query(L, R, tree[now].rson)));
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
    }
    init(1);
    top[1] = 1;
    dfn[++cnt] = 1;
    dfs(1);
    for (int i = 1; i <= cnt; ++i)
    {
        tree[++tim] = {-1, -1, 0, in[i].size() - 1, i};
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << top[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            cin >> d >> e;
            int lca = LCA(b, c);
            int now;
            now = b;
            while (top[lca] != top[now])
            {
                insert(0, depth[now] - depth[top[now]], to[now],
                       {-d, e + d * (dis[b] - dis[top[now]])});
                now = fa[top[now]];
            }
            insert(depth[lca] - depth[top[lca]], depth[now] - depth[top[now]], to[now],
                   {-d, e + d * (dis[b] - dis[top[now]])});
            now = c;
            while (top[lca] != top[now])
            {
                insert(0, depth[now] - depth[top[now]], to[now],
                       {d, e + d * (dis[b] + dis[top[now]] - dis[lca] * 2)});
                now = fa[top[now]];
            }
            insert(depth[lca] - depth[top[lca]], depth[now] - depth[top[now]], to[now],
                   {d, e + d * (dis[b] + dis[top[now]] - dis[lca] * 2)});
        }
        if (a == 2)
        {
            int ans = 123456789123456789;
            while (top[b] != top[c])
            {
                if (depth[top[b]] > depth[top[c]])
                {
                    ans = min(ans, query(0, depth[b] - depth[top[b]], to[b]));
                    b = fa[top[b]];
                }
                else
                {
                    ans = min(ans, query(0, depth[c] - depth[top[c]], to[c]));
                    c = fa[top[c]];
                }
            }
            ans = min(ans, query(min(depth[b] - depth[top[b]], depth[c] - depth[top[c]]),
                                 max(depth[b] - depth[top[b]], depth[c] - depth[top[c]]), to[c]));
            cout << ans << endl;
        }
    }
    return 0;
}