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
std::vector<int> son[100005];
int n, q, root, dfn[100005], idfn[100005], heavy[100005], top[100005], fa[100005], siz[100005], cnt;
bool odd[100005];
bool cmp(const std::vector<int> &A, const std::vector<int> &B) { return A.size() < B.size(); }
void init(int now)
{
    siz[now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        init(son[now][i]);
        siz[now] += siz[son[now][i]];
        odd[now] ^= odd[son[now][i]];
        if (siz[son[now][i]] > siz[heavy[now]])
            heavy[now] = son[now][i];
    }
}
void dfs(int now)
{
    idfn[dfn[now] = ++cnt] = now;
    top[now] = top[now] ?: now;
    odd[now] = son[now].empty();
    if (heavy[now])
    {
        top[heavy[now]] = top[now];
        dfs(heavy[now]);
        odd[now] ^= odd[heavy[now]];
        for (int i = 0; i != (int)son[now].size(); ++i)
            if (heavy[now] != son[now][i])
                dfs(son[now][i]), odd[now] ^= odd[son[now][i]];
    }
}
struct node
{
    int tot, sum;
    bool rev;
} t[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].tot = t[lson].tot + t[rson].tot;
    t[now].sum = t[lson].sum + t[rson].sum;
}
void pushdown(int now)
{
    if (t[now].rev)
    {
        t[lson].sum = t[lson].tot - t[lson].sum;
        t[rson].sum = t[rson].tot - t[rson].sum;
        t[lson].rev ^= true;
        t[rson].rev ^= true;
        t[now].rev = false;
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        t[now].sum = idfn[l] != root && !odd[idfn[l]];
        t[now].tot = idfn[l] != root;
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
    t[now].rev = false;
}
void reverse(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        t[now].sum = t[now].tot - t[now].sum;
        t[now].rev ^= true;
        return;
    }
    pushdown(now);
    reverse(L, R, lson, l, lmid);
    reverse(L, R, rson, rmid, r);
    pushup(now);
}
int sum(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return t[now].sum;
    pushdown(now);
    return sum(L, R, lson, l, lmid) + sum(L, R, rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i < n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    root = std::max_element(son + 1, son + 1 + n, cmp) - son;
    init(root);
    dfs(root);
    build();
#ifdef debug
    for (int i = 1; i <= n; ++i)
        std::cout << sum(i, i) << " \n"[i == n];
#endif
    for (int i = 1; i <= q; ++i)
    {
        static std::vector<int> d;
        std::cin >> cnt;
        d.resize(cnt);
        for (int j = 0; j != cnt; ++j)
            std::cin >> d[j];
        for (int j = 0; j != cnt; ++j)
        {
            if (siz[d[j]] > 1)
            {
                int now = d[j];
                while (now)
                {
#ifdef debug
                    std::cout << dfn[top[now]] << ' ' << dfn[now] << std::endl;
#endif
                    reverse(dfn[top[now]], dfn[now]);
                    now = fa[top[now]];
                }
                odd[root] ^= true;
            }
            ++siz[d[j]];
        }
        std::cout << (odd[root] ? -1 : n - 1 + sum(1, n) + cnt) << std::endl;
#ifdef debug
        for (int i = 1; i <= n; ++i)
            std::cout << sum(i, i) << " \n"[i == n];
#endif
        for (int j = 0; j != cnt; ++j)
        {
            --siz[d[j]];
            if (siz[d[j]] > 1)
            {
                int now = d[j];
                while (now)
                {
                    reverse(dfn[top[now]], dfn[now]);
                    now = fa[top[now]];
                }
                odd[root] ^= true;
            }
        }
    }
    return 0;
}