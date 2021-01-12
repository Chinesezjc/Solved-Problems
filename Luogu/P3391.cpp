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
template <class Type>
class Splay
{
    class node
    {
    public:
        Type val;
        int siz;
        node *fa, *son[2];
        node *&lson = son[0], *&rson = son[1];
        bool rev;
        node(const Type &VAL = Type(), node *FA = 0, node *LSON = 0, node *RSON = 0)
            : val(VAL), fa(FA), son{LSON, RSON} { update(); }
        friend int size(node *now) { return now ? now->siz : 0; }
        void update() { siz = 1 + size(lson) + size(rson); }
        bool query_son() { return fa ? fa->rson == this : false; }
        void swap_son() { swap(lson, rson); }
        friend void push_down(node *now)
        {
            if (now && now->rev)
            {
                now->swap_son();
                if (now->lson)
                    now->lson->rev ^= true;
                if (now->rson)
                    now->rson->rev ^= true;
            }
        }
        friend void connect(node *const &Fa, node *const &Son, const bool &Which)
        {
            push_down(Fa);
            if (Fa)
                Fa->son[Which] = Son;
            if (Son)
                Son->fa = Fa;
        }
    };
    node *root;
    template <class RandomAccessIterator>
    node *_build(RandomAccessIterator First, RandomAccessIterator Last)
    {
        if (First == Last)
            return 0;
        RandomAccessIterator Middle = First + (Last - First) / 2;
        node *res = new node(*Middle);
        connect(res, _build(First, Middle), false);
        connect(res, _build(Middle + 1, Last), true);
        res->update();
        return res;
    }
    void clear(node *now)
    {
        if (!now)
            return;
        clear(now->lson);
        clear(now->rson);
        delete now;
        if (now == root)
            root = 0;
    }
    template <class Container>
    void _visit(node *now, Container &container) const
    {
        if (!now)
            return;
        _visit(now->lson, container);
        container.push_back(now->val);
        _visit(now->rson, container);
    }
    void rotate(node *now)
    {
        node *Fa = now->fa;
        bool Which = query_son(now);
        connect(Fa->fa, now, query_son(Fa));
        connect(Fa, now->son[!Which], Which);
        connect(now, Fa, !Which);
        Fa->update();
        now->update();
    }
    void splay(node *now, node *Fa)
    {
        while (now->fa != Fa)
        {
            if (now->fa->fa == Fa && query_son(now) == query_son(now->fa))
                rotate(now->fa);
            rotate(now);
        }
        if (!Fa)
            root = now;
    }
    node *find(int Rank)
    {
        node *now = root;
        while (now)
        {
            push_down(now);
            if (Rank <= size(now->lson))
            {
                now = now->lson;
                continue;
            }
            Rank -= size(now->lson);
            if (Rank <= 1)
                break;
            Rank -= 1;
            if (Rank <= size(now->rson))
            {
                now = now->rson;
                continue;
            }
            now = 0;
        }
        if (!now)
            return Type();
        splay(now, 0);
        return now;
    }

public:
    template <class RandomAccessIterator>
    void build(RandomAccessIterator First, RandomAccessIterator Last)
    {
        clear(root);
        root = _build(First, Last);
    }
    template <class Container>
    void visit(Container &container) const
    {
        _visit(root, container);
    }
    void reverse(int LeftRank, int RightRank)
    {
        if (LeftRank == 1)
        {
            node *now = find(LeftRank);
            splay(now, 0);
            if (now->rson)
                now->rson->rev ^= true;
        }
        else if (RightRank == size(root))
        {
            node *now = find(RightRank);
            splay(now, 0);
            if (now->lson)
                now->lson->rev ^= true;
        }
        node *l = find(LeftRank - 1), *r = find(RightRank + 1);
        splay(l, 0);
        splay(r, l);
        if (r->lson)
            r->lson->rev ^= true;
    }
};
Splay<int> splay;
int n, m;
string nmsl = "12345641fsad56f1asf";
signed main()
{
    ios::sync_with_stdio(false);
    splay.build(nmsl.begin(), nmsl.end());
    splay.visit(nmsl);
    cout << nmsl << endl;
    // cin >> n >> m;
    return 0;
}