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
int n, m, ans = INF;
struct edge
{
    int x, y, a, b;
    friend bool operator<(const edge &A, const edge &B) { return A.a < B.a; }
} e[100005];
class LinkCutTree
{
public:
    class node
    {
    public:
        int fa, val, max, son[2];
        bool rev;
        node() : fa(), val(), max(), rev() {}
        friend bool operator<(const node &A, const node &B) { return A.val < B.val; }
    } tree[150005];
    LinkCutTree(){};
    void reverse(int now) { tree[now].rev ^= true; }
    int query_son(int now) { return tree[tree[now].fa].son[1] == now ? 1 : (tree[tree[now].fa].son[0] == now) - 1; }
    int get_max(int A, int B, int C) { return tree[B] < tree[A] ? (tree[C] < tree[A] ? A : C)
                                                                : (tree[C] < tree[B] ? B : C); }
    void pushup(int now) { tree[now].max = get_max(now, tree[tree[now].son[0]].max, tree[tree[now].son[1]].max); }
    void pushdown(int now)
    {
        if (tree[now].rev)
        {
            std::swap(tree[now].son[0], tree[now].son[1]);
            tree[tree[now].son[0]].rev ^= true;
            tree[tree[now].son[1]].rev ^= true;
            tree[now].rev = false;
        }
    }
    void connect(int fa, int now, int which)
    {
        if (fa && ~which)
            tree[fa].son[which] = now;
        if (now)
            tree[now].fa = fa;
    }
    void rotate(int now)
    {
        int fa = tree[now].fa;
        bool which = query_son(now);
        connect(tree[fa].fa, now, query_son(fa));
        connect(fa, tree[now].son[!which], which);
        connect(now, fa, !which);
        pushup(fa);
    }
    void init_splay(int now)
    {
        if (~query_son(now))
            init_splay(tree[now].fa);
        pushdown(now);
    }
    void splay(int now)
    {
        init_splay(now);
        for (int fa = tree[now].fa; ~query_son(now); rotate(now), fa = tree[now].fa)
            if (query_son(now) == query_son(fa))
                rotate(fa);
        pushup(now);
    }
    void access(int now)
    {
        for (int lst = 0; now; now = tree[now].fa)
        {
            splay(now);
            tree[now].son[1] = lst;
            pushup(lst = now);
        }
    }
    void make_root(int now)
    {
        access(now);
        splay(now);
        reverse(now);
    }
    int find_root(int now)
    {
        access(now);
        splay(now);
        while (tree[now].son[0])
            now = tree[now].son[0];
        return now;
    }
    bool link(int A, int B)
    {
        make_root(A);
        if (find_root(B) == A)
            return false;
        make_root(B);
        tree[B].fa = A;
        return true;
    }
    bool cut(int A, int B)
    {
        make_root(A);
        access(B);
        splay(B);
        if (tree[B].son[0] != A)
            return false;
        tree[B].son[0] = tree[A].fa = 0;
        pushup(B);
        return true;
    }
    int max(int A, int B)
    {
        make_root(A);
        access(B);
        splay(B);
        return tree[B].max;
    }
} lct;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> e[i].x >> e[i].y >> e[i].a >> e[i].b;
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        if (e[i].x == e[i].y)
            continue;
        // std::cout << i << ' ' << e[i].x << ' ' << e[i].y << std::endl;
        lct.make_root(e[i].x);
        if (lct.find_root(e[i].y) == e[i].x)
        {
            int tmp = lct.max(e[i].x, e[i].y) - n;
            if (e[tmp].b > e[i].b)
            {
                lct.cut(e[tmp].x, tmp + n);
                lct.cut(e[tmp].y, tmp + n);
            }
        }
        lct.tree[i + n].val = e[i].b;
        lct.link(e[i].x, i + n);
        lct.link(e[i].y, i + n);
        lct.make_root(1);
        if (lct.find_root(n) == 1)
            ans = std::min(ans, e[i].a + e[lct.max(1, n) - n].b);
    }
    std::cout << (ans == INF ? -1 : ans) << std::endl;
    return 0;
}