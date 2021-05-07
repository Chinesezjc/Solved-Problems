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
const int MOD = 998244353;
std::vector<std::pair<int, int> /**/> son[100005];
int n, m, fa[100005], val[100005], a[100005], depth[100005], top[100005],
    heavy[100005], siz[100005], dfn[100005], idfn[100005], cnt, ans;
void init1(int now)
{
    siz[now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i].second)
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i].second] = now;
        val[son[now][i].second] = son[now][i].first;
        depth[son[now][i].second] = depth[now] + 1;
        init1(son[now][i].second);
        siz[now] += siz[son[now][i].second];
        if (siz[heavy[now]] < siz[son[now][i].second])
            heavy[now] = son[now][i].second;
    }
}
void init2(int now)
{
    dfn[idfn[now] = ++cnt] = now;
    if (heavy[now])
    {
        top[heavy[now]] = top[now];
        init2(heavy[now]);
    }
    for (int i = 0; i != (int)son[now].size(); ++i)
        if (heavy[now] != son[now][i].second)
            init2(top[son[now][i].second] = son[now][i].second);
}
struct node
{
    int sum, res[2][2];
    int add[2][2];
    bool swap;
} tree[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushdown(int now)
{
    if (tree[now].swap)
    {
        for (int i = 0; i != 2; ++i)
        {
            std::swap(tree[lson].res[i][0], tree[lson].res[i][1]);
            std::swap(tree[rson].res[i][0], tree[rson].res[i][1]);
            std::swap(tree[lson].add[i][0], tree[lson].add[i][1]);
            std::swap(tree[rson].add[i][0], tree[rson].add[i][1]);
        }
        tree[lson].swap ^= true;
        tree[rson].swap ^= true;
        tree[now].swap = false;
    }
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 2; ++j)
            if (tree[now].add[i][j])
            {
                tree[lson].res[i][j] = (tree[lson].res[i][j] + tree[lson].sum * tree[now].add[i][j]) % MOD;
                tree[rson].res[i][j] = (tree[rson].res[i][j] + tree[rson].sum * tree[now].add[i][j]) % MOD;
                tree[lson].add[i][j] = (tree[lson].add[i][j] + tree[now].add[i][j]) % MOD;
                tree[rson].add[i][j] = (tree[rson].add[i][j] + tree[now].add[i][j]) % MOD;
                tree[now].add[i][j] = 0;
            }
}
void pushup(int now)
{
    tree[now].sum = (tree[lson].sum + tree[rson].sum) % MOD;
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 2; ++j)
            tree[now].res[i][j] = (tree[lson].res[i][j] + tree[rson].res[i][j]) % MOD;
}
void add(int L, int R, bool t1, bool t2, int val, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        tree[now].res[t1][t2] = (tree[now].res[t1][t2] + tree[now].sum * val) % MOD;
        tree[now].add[t1][t2] = (tree[now].add[t1][t2] + val) % MOD;
        return;
    }
    pushdown(now);
    add(L, R, t1, t2, val, lson, l, lmid);
    add(L, R, t1, t2, val, rson, rmid, r);
    pushup(now);
}
void swap(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        for (int i = 0; i != 2; ++i)
        {
            std::swap(tree[now].res[i][0], tree[now].res[i][1]);
            std::swap(tree[now].add[i][0], tree[now].add[i][1]);
        }
        tree[now].swap ^= true;
        return;
    }
    pushdown(now);
    swap(L, R, lson, l, lmid);
    swap(L, R, rson, rmid, r);
    pushup(now);
}
void visit(int now = 1, int l = 1, int r = n)
{
    if (l == r)
        return void(std::cout << dfn[l] << ' ' << tree[now].res[0][0] << ' ' << tree[now].res[0][1] << ' ' << tree[now].res[1][0] << ' ' << tree[now].res[1][1] << ' ' << tree[now].sum << std::endl);
    pushdown(now);
    visit(lson, l, lmid);
    visit(rson, rmid, r);
    pushup(now);
}
void work(int u, bool odd)
{
    add(1, n, odd, 0, 1);
    while (u)
    {
        swap(idfn[top[u]], idfn[u]);
        u = fa[top[u]];
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        tree[now].sum = val[dfn[l]];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
#undef lson
#undef rson
#undef lmid
#undef rmid
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        son[a].push_back(std::make_pair(c, b));
        son[b].push_back(std::make_pair(c, a));
    }
    init1(1);
    top[1] = 1;
    init2(1);
    build();
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i];
        work(a[i], i & 1);
        ans = (ans + tree[1].res[(i & 1) ^ 1][1]) % MOD;
        // visit();
        // std::cout << tree[1].res[(i & 1) ^ 1][1] << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}