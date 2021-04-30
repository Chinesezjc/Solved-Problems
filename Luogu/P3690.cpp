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
int n, m;
template <class Type>
class LCT
{
private:
    class node
    {
    public:
        Type val, sum;
        int son[2], fa;
        bool rev;
        node() : val(), sum(), son(), fa() {}
        node(Type val_) : val(val_), sum(val_), son(), fa() {}
        void clear()
        {
            val = sum = Type();
            son[0] = son[1] = fa = 0;
        }
    } tree[100005];

public:
    LCT() {}
    void pushup(int now)
    {
        tree[now].sum = tree[now].val;
        for (int i = 0; i != 2; ++i)
            tree[now].sum ^= tree[tree[now].son[i]].sum;
    }
    void pushdown(int now)
    {
        if (tree[now].rev)
        {
            std::swap(tree[now].son[0], tree[now].son[1]);
            for (int i = 0; i != 2; ++i)
                if (tree[now].son[i])
                    tree[tree[now].son[i]].rev ^= true;
            tree[now].rev = false;
        }
    }
    void init_splay(int now)
    {
        if (tree[now].fa)
            init_splay(tree[now].fa);
        pushdown(now);
    }
    int query_son(int now)
    {
        int fa = tree[now].fa, res = 2;
        while (res--)
            if (tree[fa].son[res] == now)
                break;
        return res;
    }
    void connect(int A, int B, int which)
    {
        if (A && ~which)
            tree[A].son[which] = B;
        if (B)
            tree[B].fa = A;
    }
    void rotate(int now)
    {
        int fa = tree[now].fa, nowg = query_son(now);
        connect(tree[fa].fa, now, query_son(fa));
        connect(fa, tree[now].son[!nowg], nowg);
        connect(now, fa, !nowg);
        pushup(now);
    }
    void splay(int now)
    {
        init_splay(now);
        for (int fa = tree[now].fa; ~query_son(now); rotate(now), fa = tree[now].fa)
            if (query_son(fa) == query_son(now))
                rotate(fa);
    }
    void access(int now)
    {
        for (int lst = 0; now; lst = now, now = tree[now].fa)
        {
            splay(now);
            tree[now].son[1] = lst;
            pushup(now);
        }
    }
    void reverse(int now) { tree[now].rev ^= true; }
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
        for (pushdown(now); tree[now].son[0]; pushdown(now))
            now = tree[now].son[0];
        splay(now);
        return now;
    }
    void split(int A, int B)
    {
        make_root(A);
        access(B);
        splay(B);
    }
    bool link(int A, int B)
    {
        make_root(A);
        int root = find_root(B);
        if (A == root)
            return false;
        make_root(B);
        tree[B].fa = A;
        return true;
    }
    bool cut(int A, int B)
    {
        split(A, B);
        if (tree[B].son[0] != A || tree[A].son[1])
            return false;
        tree[A].fa = tree[B].son[0] = 0;
        pushup(B);
        return true;
    }
    int sum(int A, int B)
    {
        split(A, B);
        _visit();
        pushup(B);
        for (int i = 1; i <= n; ++i)
            std::cout << tree[i].sum << std::endl;
        return tree[B].sum;
    }
    void modify(int pos, int val)
    {
        splay(pos);
        tree[pos].val = val;
        pushup(pos);
    }
    void _visit(int now = 0)
    {
        if (!now)
        {
            for (int i = 1; i <= n; ++i)
                if (!~query_son(i))
                    _visit(i);
            return;
        }
        if (tree[now].son[0])
            _visit(tree[now].son[0]);
        if (tree[now].fa)
            std::cout << tree[now].fa << ' ' << now << ' ' << query_son(now) << std::endl;
        if (tree[now].son[1])
            _visit(tree[now].son[1]);
    }
};
LCT<int> lct;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        lct.modify(i, x);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y;
        std::cin >> opt >> x >> y;
        switch (opt)
        {
        case 0:
            std::cout << lct.sum(x, y) << std::endl;
            break;
        case 1:
            lct.link(x, y);
            break;
        case 2:
            lct.cut(x, y);
            break;
        case 3:
            lct.modify(x, y);
            break;
        }
    }
    return 0;
}