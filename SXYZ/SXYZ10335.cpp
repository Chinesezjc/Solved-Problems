// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
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
    } tree[600005];

public:
    LCT() {}
    void pushup(int now) { tree[now].sum = tree[now].val + tree[tree[now].son[0]].sum + tree[tree[now].son[1]].sum; }
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
    void init_splay(int now)
    {
        if (~query_son(now))
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
        int fa = tree[now].fa;
        bool nowg = query_son(now);
        connect(tree[fa].fa, now, query_son(fa));
        connect(fa, tree[now].son[!nowg], nowg);
        connect(now, fa, !nowg);
        pushup(fa);
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
        access(B);
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
        // std::cout << clock() << std::endl;
        // _visit();
        pushup(B);
        // for (int i = 1; i <= n; ++i)
        //     std::cout << tree[i].sum << " \n"[i == n];
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
            for (int i = 1; i <= 1000; ++i)
                if (!~query_son(i))
                    _visit(i);
            return;
        }
        pushdown(now);
        if (tree[now].son[0])
            _visit(tree[now].son[0]);
        if (tree[now].fa)
            std::cout << "   " << tree[now].fa << ' ' << now << ' ' << query_son(now) << std::endl;
        if (tree[now].son[1])
            _visit(tree[now].son[1]);
    }
    int work(int root, int l, int r)
    {
        make_root(root);
        access(l);
        splay(l);
        // _visit();
        int now = l, bes = l;
        while (true)
        {
            pushdown(now);
            if (now <= r)
            {
                bes = now;
                if (tree[now].son[0])
                    now = tree[now].son[0];
                else
                    break;
            }
            else
            {
                if (tree[now].son[1])
                    now = tree[now].son[1];
                else
                    break;
            }
        }
        // std::cout << "l is " << l << ' ' << "bes is " << bes << std::endl;
        return sum(l, bes) - sum(bes, bes);
    }
};
LCT<int> lct;
int n, m, cnt;
std::map<int, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        lct.link(i, i + 1);
    cnt = m + 1;
    for (int i = 1, opt, l, r; i <= n; ++i)
    {
        std::cin >> opt >> l >> r;
        ++r;
        if (opt == 1)
        {
            std::map<int, int>::iterator iter = map.lower_bound(l);
            if (iter != map.end() && r >= iter->second)
                continue;
            iter = map.upper_bound(l);
            if (iter != map.begin())
            {
                --iter;
                while (iter->second >= r)
                {
                    // std::cout << "del " << iter->first << ' ' << iter->second << std::endl;
                    lct.cut(iter->first, iter->second);
                    lct.link(iter->first, iter->first + 1);
                    lct.modify(iter->first, 0);
                    if (iter != map.begin())
                        map.erase(iter--);
                    else
                    {
                        map.erase(iter);
                        break;
                    }
                }
            }
            lct.cut(l, l + 1);
            lct.modify(l, 1);
            map[l] = r;
            lct.link(l, r);
        }
        else if (opt == 2)
        {
            std::cout << lct.work(m + 1, l, r) << '\n';
        }
        // for (auto i : map)
        //     std::cout << i.first << ' ' << i.second << std::endl;
    }
    return 0;
}