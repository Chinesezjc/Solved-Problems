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
protected:
    class node
    {
    public:
        Type val;
        int num, sum;
        node *son[2], *fa;
        node *&lson = son[0], *&rson = son[1];
        node(const Type VAL = Type(), const int NUM = 0, node *const FA = 0, node *const L = 0, node *const R = 0)
            : val(VAL), num(NUM), son{L, R}, fa(FA) { update(); }
        friend int size(node *const &x) { return x ? sum : 0; }
        bool query_son() const { return fa ? fa->rson == this : 0; }
        void update() { sum = num + size(lson) + size(rson); }
        friend void connect(node *const Fa, node *const Son, const bool which)
        {
            Fa->son[which] = Son;
            Son->fa = Fa;
        }
    };
    node *root;
    void rotate(node *now)
    {
        node *Fa = now->fa;
        bool which = query_son(now);
        connect(Fa->fa, now, query_son(Fa));
        connect(Fa, now->son[!which], which);
        connect(now, Fa, !which);
    }
    void splay(node *now, node *Fa)
    {
        while (now->fa != Fa)
        {
            if (now->fa->fa != Fa && now->fa->query_son() == now->query_son())
                rotate(now->fa);
            rotate(now);
        }
        if (!Fa)
            root = now;
    }

public:
    void insert(const Type &Value)
    {
        if (!root)
            return void(root = new node(Value, 1));
        node *now = root;
        while (now->val != Value)
        {
            if (Value < now->val)
                now = now->lson = now->lson ? now->lson : new node(Value, 0, now);
            if (now->val < Value)
                now = now->rson = now->rson ? now->rson : new node(Value, 0, now);
        }
        ++now->num;
        now->update();
        splay(now, 0);
    }
    bool erase(const Type &Value)
    {
        if (!root)
            return false;
        node *now = root;
        while (now->val != Value)
        {
            if (Value < now->val)
                if (now->lson)
                    now = now->lson;
                else
                    return false;
            if (Value > now->val)
                if (now->rson)
                    now = now->rson;
                else
                    return false;
        }
        --now->num;
        splay(now);
        if (!now->num)
        {
            if(now->lson)
        }
    }
};
Splay<int> splay;
int m;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x;
        cin >> opt >> x;
        switch (opt)
        {
        case 1:
            splay.insert(x);
            break;
        case 2:
            splay.erase(x);
            break;
        case 3:
            cout << splay.query_rank(x) << endl;
            break;
        case 4:
            cout << splay.query_val(x) << endl;
            break;
        case 5:
            cout << splay.query_val(splay.query_rank(x) - 1) << endl;
            break;
        case 6:
            cout << splay.query_val(splay.query_rank(x + 1)) << endl;
            break;
        }
    }
    return 0;
}