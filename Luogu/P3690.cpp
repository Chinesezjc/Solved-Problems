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
#include <cassert>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
template <class Type>
class LCT
{
private:
    class node
    {
    public:
        Type val, sum = Type();
        bool rev = false;
        int fa, son[2];
        int &lson = son[0], &rson = son[1];
        node(const Type &VAL = Type(), const int &FA = 0, const int &LSON = 0, const int &RSON = 0)
            : val(VAL), fa(FA), son{LSON, RSON} {}
        node(const node &tmp)
            : val(tmp.val), sum(tmp.sum), rev(tmp.rev), fa(tmp.fa), son{tmp.lson, tmp.rson} {}
        void swap_son() { swap(lson, rson); }
    };
    vector<node> g;
    void pushdown(const int &now)
    {
        if (g[now].rev)
        {
            g[now].swap_son();
            g[g[now].lson].rev ^= true;
            g[g[now].rson].rev ^= true;
            g[now].rev = false;
        }
    }
    void pushup(const int &now) { g[now].sum = g[now].val ^ g[g[now].lson].sum ^ g[g[now].rson].sum; }
    void connect(const int &Fa, const int &Son, const int &Which)
    {
        if (Fa && ~Which)
            g[Fa].son[Which] = Son;
        if (Son)
            g[Son].fa = Fa;
    }
    int query_son(const int &now) const
    {
        return g[g[now].fa].lson == now || g[g[now].fa].rson == now ? g[g[now].fa].rson == now : -1;
    }
    void rotate(const int &now)
    {
        int Fa = g[now].fa;
        bool Which = query_son(now);
        connect(g[Fa].fa, now, query_son(Fa));
        connect(Fa, g[now].son[!Which], Which);
        connect(now, Fa, !Which);
        pushup(Fa);
    }
    void init_splay(const int &now)
    {
        if (~query_son(now))
            init_splay(g[now].fa);
        pushdown(now);
    }
    void splay(const int &now)
    {
        init_splay(now);
        while (~query_son(now))
        {
            if (query_son(g[now].fa) == query_son(now))
                rotate(g[now].fa);
            rotate(now);
        }
        pushup(now);
    }
    void access(int now)
    {
        for (int lst = 0; now; lst = now, now = g[now].fa)
        {
            splay(now);
            g[now].rson = lst;
            pushup(now);
        }
    }
    void reverse(const int &now) { g[now].rev ^= true; }
    void make_root(const int &now)
    {
        assert(0 < now && now < g.size());
        access(now);
        splay(now);
        reverse(now);
    }
    int find_root(int now)
    {
        access(now);
        splay(now);
        for (pushdown(now); g[now].lson; pushdown(now))
            now = g[now].lson;
        splay(now);
        return now;
    }
    void split(const int &A, const int &B)
    {
        make_root(A);
        access(B);
        splay(B);
        assert(find_root(B) == A);
    }
    void _visit(const int &now) const
    {
        if (!now)
            return;
        cout << g[now].fa << ' ' << now << ' ' << query_son(now) << endl;
        _visit(g[now].lson);
        _visit(g[now].rson);
    }

public:
    LCT() { g.push_back(node()); }
    void add_node(const Type &Value = Type()) { g.push_back(Value); }
    bool link(const int &A, const int &B)
    {
        make_root(A);
        if (find_root(B) == A)
            return false;
        access(B);
        splay(B);
        g[B].fa = A;
        return true;
    }
    bool cut(const int &A, const int &B)
    {
        split(A, B);
        splay(B);
        if (g[B].lson != A || g[A].rson)
            return false;
        g[A].fa = 0;
        g[B].lson = 0;
        pushup(B);
        return true;
    }
    void visit(const int &now)
    {
        cout << "<visit>" << endl;
        splay(now);
        _visit(now);
        cout << "</visit>" << endl;
    }
    Type sum(const int &A, const int &B)
    {
        split(A, B);
        splay(A);
        return g[A].sum;
    }
    void modify(int now, const Type &Value)
    {
        splay(now);
        g[now].val = Value;
        for (pushup(now); ~query_son(now); pushup(now))
            now = g[now].fa;
    }
};
LCT<int> lct;
int n, m;
signed main()
{
#ifdef debug
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        static int v;
        cin >> v;
        lct.add_node(v);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y;
        cin >> opt >> x >> y;
        switch (opt)
        {
        case 0:
            cout << lct.sum(x, y) << endl;
            lct.visit(x);
            break;
        case 1:
            cout << lct.link(x, y) << endl;
            lct.visit(x);
            break;
        case 2:
            lct.cut(x, y);
            lct.visit(x);
            break;
        case 3:
            lct.modify(x, y);
            lct.visit(x);
            break;
        }
    }
    return 0;
}
