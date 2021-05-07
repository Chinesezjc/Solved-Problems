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
int fa[100005], n, m, dfn[100005], idfn[100005], heavy[100005], siz[100005], dep[100005], top[100005], cnt;
std::vector<int> son[100005];
namespace IO
{
    char OUT[20];
    char IN;
    int cnt;
    template <class T>
    T &read(T &__Val)
    {
        __Val = 0;
        IN = getchar();
        while (!isdigit(IN))
        {
            IN = getchar();
        }
        while (isdigit(IN))
        {
            __Val = __Val * 10 + (IN & 15);
            IN = getchar();
        }
        return __Val;
    }
    template <class T>
    void write(const T &__Val)
    {
        if (__Val == 0)
        {
            putchar('0');
        }
        T now = __Val;
        while (now)
        {
            OUT[cnt++] = now % 10;
            now /= 10;
        }
        while (cnt)
        {
            putchar(OUT[--cnt] | '0');
        }
    }
    template <class T, class... Args>
    void read(T &__Val, Args &...args)
    {
        read(__Val);
        read(args...);
    }
} // namespace IO
void init1(int now)
{
    siz[now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        dep[son[now][i]] = dep[now] + 1;
        init1(son[now][i]);
        siz[now] += siz[son[now][i]];
        if (!~heavy[now] || siz[heavy[now]] < siz[son[now][i]])
            heavy[now] = son[now][i];
    }
}
void init2(int now)
{
    dfn[idfn[now] = cnt++] = now;
    if (~heavy[now])
        top[heavy[now]] = top[now], init2(heavy[now]);
    for (int i = 0; i != (int)son[now].size(); ++i)
        if (heavy[now] != son[now][i])
            init2(top[son[now][i]] = son[now][i]);
}
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
struct node
{
    int cnt, set, tot;
} tree[1 << 18];
void pushup(int now)
{
    tree[now].cnt = tree[lson].cnt + tree[rson].cnt;
    tree[now].tot = tree[lson].tot + tree[rson].tot;
}
void pushdown(int now)
{
    if (~tree[now].set)
    {
        tree[lson].cnt = tree[lson].tot * tree[now].set;
        tree[rson].cnt = tree[rson].tot * tree[now].set;
        tree[lson].set = tree[now].set;
        tree[rson].set = tree[now].set;
        tree[now].set = -1;
    }
}
void build(int now = 1, int l = 0, int r = n)
{
    if (r - l == 1)
    {
        tree[now].tot = 1;
        tree[now].set = -1;
        return;
    }
    build(lson, l, mid);
    build(rson, mid, r);
    pushup(now);
}
int sum(int L, int R, int now = 1, int l = 0, int r = n)
{
    if (r <= L || R <= l)
        return 0;
    if (L <= l && r <= R)
        return tree[now].cnt;
    pushdown(now);
    return sum(L, R, lson, l, mid) + sum(L, R, rson, mid, r);
}
void set(int L, int R, int val, int now = 1, int l = 0, int r = n)
{
    if (r <= L || R <= l)
        return;
    if (L <= l && r <= R)
    {
        tree[now].cnt = val * tree[now].tot;
        tree[now].set = val;
        return;
    }
    pushdown(now);
    set(L, R, val, lson, l, mid);
    set(L, R, val, rson, mid, r);
    pushup(now);
}
signed main()
{
    IO::read(n);
    fa[0] = -1;
    for (int i = 1; i < n; ++i)
    {
        IO::read(fa[i]);
        son[fa[i]].push_back(i);
    }
    memset(heavy, -1, sizeof(heavy));
    init1(0);
    init2(0);
    build();
    IO::read(m);
    for (int i = 1; i <= m; ++i)
    {
        static char opt;
        static int x;
        static int ans;
        do
            opt = getchar();
        while (opt != 'i' && opt != 'u');
        IO::read(x);
        switch (opt)
        {
        case 'i':
            ans = dep[x] + 1;
            while (~x)
            {
                ans -= sum(idfn[top[x]], idfn[x] + 1);
                set(idfn[top[x]], idfn[x] + 1, 1);
                x = fa[top[x]];
            }
            IO::write(ans);
            break;
        case 'u':
            IO::write(sum(idfn[x], idfn[x] + siz[x]));
            set(idfn[x], idfn[x] + siz[x], 0);
            break;
        }
        putchar('\n');
    }
    return 0;
}