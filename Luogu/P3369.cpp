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
struct Splay
{
    int root, cnt = 0;
    struct node
    {
        int son[2], fa, val, cnt, siz;
        node() { clear(); }
        void clear() { son[0] = son[1] = fa = val = cnt = siz = 0; }
    } tree[100005];
    Splay() { clear(); }
    void clear() { root = cnt = 0; }
    void update(int now)
    {
        if (!now)
            return;
        tree[now].siz = tree[now].cnt;
        for (int i = 0; i != 2; ++i)
            if (tree[now].son[i])
                tree[now].siz += tree[tree[now].son[i]].siz;
    }
    bool get_which(int now) { return tree[tree[now].fa].son[1] == now; }
    void connect(int fa, int son, bool g)
    {
        if (fa)
            tree[fa].son[g] = son;
        if (son)
            tree[son].fa = fa;
    }
    void rotate(int now)
    {
        bool fag = get_which(tree[now].fa), nowg = get_which(now);
        int fa = tree[now].fa;
        connect(tree[fa].fa, now, fag);
        connect(fa, tree[now].son[!nowg], nowg);
        connect(now, fa, !nowg);
        update(fa);
        update(now);
    }
    void splay(int now)
    {
        if (!now)
            return;
        for (int fa; (fa = tree[now].fa); rotate(now))
            if (tree[fa].fa)
                rotate(get_which(fa) == get_which(now) ? fa : now);
        root = now;
    }
    void insert(int val)
    {
        if (!root)
        {
            root = ++cnt;
            tree[root].val = val;
            tree[root].siz = tree[root].cnt = 1;
            return;
        }
        for (int now = root;;)
        {
            if (val == tree[now].val)
            {
                ++tree[now].cnt;
                ++tree[now].siz;
                return splay(now);
            }
            else
            {
                bool son = val > tree[now].val;
                if (tree[now].son[son])
                    now = tree[now].son[son];
                else
                {
                    tree[++cnt].val = val;
                    tree[cnt].cnt = tree[cnt].siz = 1;
                    connect(now, cnt, son);
                    return splay(cnt);
                }
            }
        }
    }
    int lower_bound(int val)
    {
        if (!root)
            return 0;
        for (int now = root, ans = 0;;)
        {
            if (val <= tree[now].val)
            {
                ans = now;
                if (tree[now].son[0])
                    now = tree[now].son[0];
                else
                {
                    splay(now);
                    return ans;
                }
            }
            else
            {
                if (tree[now].son[1])
                    now = tree[now].son[1];
                else
                {
                    splay(now);
                    return ans;
                }
            }
        }
    }
    int upper_bound(int val)
    {
        if (!root)
            return 0;
        for (int now = root, ans = 0;;)
        {
            if (val < tree[now].val)
            {
                ans = now;
                if (tree[now].son[0])
                    now = tree[now].son[0];
                else
                {
                    splay(now);
                    return ans;
                }
            }
            else
            {
                if (tree[now].son[1])
                    now = tree[now].son[1];
                else
                {
                    splay(now);
                    return ans;
                }
            }
        }
    }
    int get_rk(int val)
    {
        if (!root)
            return 1;
        for (int now = root, ans = 1;;)
        {
            if (val < tree[now].val)
            {
                if (tree[now].son[0])
                    now = tree[now].son[0];
                else
                {
                    splay(now);
                    return ans;
                }
                continue;
            }
            ans += tree[tree[now].son[0]].siz;
            if (val == tree[now].val)
            {
                splay(now);
                return ans;
            }
            ans += tree[now].cnt;
            if (val > tree[now].val)
            {
                if (tree[now].son[1])
                    now = tree[now].son[1];
                else
                {
                    splay(now);
                    return ans;
                }
                continue;
            }
        }
    }
    int get_val(int rk)
    {
        if (!root)
            return 0;
        --rk;
        for (int now = root;;)
        {
            if (tree[tree[now].son[0]].siz > rk)
            {
                now = tree[now].son[0];
                continue;
            }
            rk -= tree[tree[now].son[0]].siz;
            if (tree[now].cnt > rk)
            {
                splay(now);
                return tree[now].val;
            }
            rk -= tree[now].cnt;
            now = tree[now].son[1];
        }
    }
    bool erase(int val, int num = 1)
    {
        if (!root)
            return false;
        for (int now = root;;)
        {
            if (val == tree[now].val)
            {
                tree[now].cnt -= num;
                splay(now);
                if (tree[now].cnt <= 0)
                {
                    int rson = upper_bound(tree[now].val);
                    if (rson)
                    {
                        splay(rson);
                        connect(rson, tree[now].son[0], 0);
                    }
                    else
                        tree[root = tree[now].son[0]].fa = 0;
                    tree[now].clear();
                }
                return true;
            }
            else
            {
                bool son = val > tree[now].val;
                if (tree[now].son[son])
                    now = tree[now].son[son];
                else
                {
                    splay(now);
                    return false;
                }
            }
        }
    }
    void visit(int now = -1)
    {
        if (!~now)
        {
            visit(root);
            std::cout << std::endl;
        }
        else
        {
            if (tree[now].son[0])
                visit(tree[now].son[0]);
            std::cout << tree[now].val << ' ';
            if (tree[now].son[1])
                visit(tree[now].son[1]);
        }
    }
    int lst(int now)
    {
        if (!now)
        {
            now = root;
            while (tree[now].son[1])
                now = tree[now].son[1];
            splay(now);
            return now;
        }
        splay(now);
        now = tree[now].son[0];
        while (tree[now].son[1])
            now = tree[now].son[1];
        return now;
    }
    int nxt(int now)
    {
        if (!now)
        {
            now = root;
            while (tree[now].son[0])
                now = tree[now].son[0];
            splay(now);
            return now;
        }
        splay(now);
        now = tree[now].son[1];
        while (tree[now].son[0])
            now = tree[now].son[0];
        return now;
    }
    const int &at(int now) const
    {
        return tree[now].val;
    }
} S;
signed main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    while (n--)
    {
        static int opt, v;
        std::cin >> opt >> v;
        switch (opt)
        {
        case 1:
            S.insert(v);
            break;
        case 2:
            S.erase(v);
            break;
        case 3:
            std::cout << S.get_rk(v) << std::endl;
            break;
        case 4:
            std::cout << S.get_val(v) << std::endl;
            break;
        case 5:
            std::cout << S.at(S.lst(S.lower_bound(v))) << std::endl;
            break;
        case 6:
            std::cout << S.at(S.upper_bound(v)) << std::endl;
            break;
        }
        // S.visit();
    }
    return 0;
}