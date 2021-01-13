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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int power(int A, int B, int C)
{
    int res = 1;
    while (B)
        (B & 1) && (res = res * A % C), B >>= 1, A = A * A % C;
    return res;
}
template <class Type>
class LCT
{
private:
    class node
    {
    public:
        Type val, x;
        int siz;
        bool rev;
        node *fa, *son[2];
        node *&lson = son[0], *&rson = son[1];
        node(const Type &VAL = Type(), const int &FA = 0, const int &LSON = 0, const int &RSON = 0)
            : val(VAL), fa(FA), son{LSON, RSON}, rev(false) { pushup(); }
        friend Type Xor(node *const now) { return now ? now->x : 0; }
        friend int size(node *const now) { return now ? now->siz : 0; }
        friend SonType query_son(node *const now)
        {
            return now->fa && (now->fa->lson == now || now->fa->rson == now) ? now == now->fa->rson : -1;
        }
        void pushup()
        {
            x = val ^ Xor(lson) ^ Xor(rson);
            siz = 1 + size(lson) + size(rson);
        }
        void pushdown()
        {
            if (rev)
            {
                swap(lson, rson);
                if (lson)
                    lson->rev ^= true;
                if (rson)
                    rson->rev ^= true;
            }
        }
        friend void connect(node *const Fa, node *const Son, const SonType &Which)
        {
            if (Fa && ~Which)
                Fa->son[Which] = Son;
            if (Son)
                Son->fa = Fa;
        }
    };
    node *root;
    vector<node *> g;
    void rotate(node *const &now)
    {
        node *Fa = now->fa;
        bool Which = query_son(now);
        connect(Fa->fa, now, query_son(Fa));
        connect(Fa, now->son[!Which], Which);
        connect(now, Fa, !Which);
        Fa->pushup();
    }
    void init_pushdown(node *const now)
    {
        if (~query_son(now))
            init_pushdown(now->fa);
        now->pushdown();
    }
    void splay(node *const &now)
    {
        init_pushdown(now);
        while (~query_son(now))
        {
            if (query_son(now) == query_son(now->fa))
                rotate(now->fa);
            rotate(now);
        }
        now->pushup();
    }

public:
    void add_node(const Type Value = Type()) { g.push_back(new node(Value)); }
    void access(const int Pos)
    {
        for (node *now = g[Pos], lst = 0;now;lst=now,now=now->fa)
        {
            splay(now);
        }
    }
};
LCT<char> lct;
int n, m;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        static int v;
        cin >> v;
        lct.add_node(v);
    }
    for (int i = 0; i < m; ++i)
    {
        static int opt, x, y;
        cin >> opt >> x >> y;
        switch (opt)
        {
        case 0:
            --x;
            --y;
            break;
        case 1:
            --x;
            --y;
            break;
        case 2:
            --x;
            --y;
            break;
        case 3:
            --x;
            break;
        }
    }
    return 0;
}