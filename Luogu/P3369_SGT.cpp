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
class SGT
{
private:
    class node
    {
    public:
        static constexpr double alpha = 0.75;
        Type val;
        int num, sum, siz;
        node *son[2], *fa;
        node *&lson = son[0], *&rson = son[1];
        bool query_son(node *const &Son) const
        {
            return Son == rson;
        }
        void update(bool up)
        {
            int oldsiz = siz, oldsum = sum;
            siz = 1;
            sum = num;
            if (lson)
            {
                siz += lson->siz;
                sum += lson->sum;
            }
            if (rson)
            {
                siz += rson->siz;
                sum += rson->sum;
            }
            if (up && (siz != oldsiz || sum != oldsum) && fa)
                fa->update(true);
        }
        void modify_son(bool const &Side, node *const &Son)
        {
            son[Side] = Son;
        }
        bool bad() const
        {
            int tmp = 0;
            if (lson)
                tmp = max(lson->siz, tmp);
            if (rson)
                tmp = max(rson->siz, tmp);
            return tmp > siz * alpha;
        }
    };
    node *root;
    template <class RandomAccessIterator>
    node *_rebuild(const RandomAccessIterator &_first, const RandomAccessIterator &_last)
    {
        if (_first == _last)
            return 0;
        RandomAccessIterator mid = (_last - _first) / 2 + _first;
        node *const res = new node{mid->first, mid->second, mid->second, _last - _first,
                                   _rebuild(_first, mid), _rebuild(mid + 1, _last), 0};
        if (res->lson)
            res->lson->fa = res;
        if (res->rson)
            res->rson->fa = res;
        res->update(false);
        return res;
    }
    void clear(node *const now)
    {
        if (now == root)
            root = 0;
        if (now->fa)
            now->fa->modify_son(now->fa->query_son(now), 0);
        if (now->lson)
            clear(now->lson);
        if (now->rson)
            clear(now->rson);
        delete now;
    }
    template <class ContainerType>
    void _visit(node *const &now, ContainerType &Container) const
    {
        if (now->lson)
            _visit(now->lson, Container);
        if (now->num)
            Container.push_back({now->val, now->num});
        if (now->rson)
            _visit(now->rson, Container);
    }
    void rebuild(node *const &now)
    {
        vector<pair<Type, int>> tmp;
        _visit(now, tmp);
        if (now == root)
        {
            clear(now);
            root = _rebuild(tmp.begin(), tmp.end());
        }
        else
        {
            node *const fa = now->fa;
            bool Son = fa->query_son(now);
            clear(now);
            fa->modify_son(Son, _rebuild(tmp.begin(), tmp.end()));
            fa->son[Son]->fa = fa;
            fa->update(true);
        }
    }

public:
    template <class InputIterator>
    void build(InputIterator first, InputIterator last)
    {
        if (root)
            clear(root);
        for (; first != last; ++first)
            insert(*first);
    }
    template <class ContainerType>
    void visit(ContainerType &Container) const
    {
        if (root)
            _visit(root, Container);
    }
    void insert(const Type &Value)
    {
        if (!root)
        {
            root = new node{Value, 1, 1, 1, 0, 0, 0};
            return;
        }
        if (root->bad())
            rebuild(root);
        node *now = root;
        while (true)
        {
            if (now->val > Value)
            {
                if (now->lson)
                {
                    if (now->lson->bad())
                        rebuild(now->lson);
                    now = now->lson;
                    continue;
                }
                else
                {
                    now = now->lson = new node{Value, 0, 0, 1, 0, 0, now};
                    break;
                }
            }
            if (now->val < Value)
            {
                if (now->rson)
                {
                    if (now->rson->bad())
                        rebuild(now->rson);
                    now = now->rson;
                    continue;
                }
                else
                {
                    now = now->rson = new node{Value, 0, 0, 1, 0, 0, now};
                    break;
                }
            }
            break;
        }
        ++now->num;
        now->update(true);
    }
    bool erase(const Type &Value)
    {
        if (!root)
            return false;
        if (root->bad())
            rebuild(root);
        node *now = root;
        while (true)
        {
            if (now->val > Value)
            {
                if (now->lson)
                {
                    if (now->lson->bad())
                        rebuild(now->lson);
                    now = now->lson;
                    continue;
                }
                return false;
            }
            if (now->val < Value)
            {
                if (now->rson)
                {
                    if (now->rson->bad())
                        rebuild(now->rson);
                    now = now->rson;
                    continue;
                }
                return false;
            }
            --now->num;
            now->update(true);
            return true;
        }
    }
    int query_rank(const Type &Value)
    {
        if (!root)
            return 1;
        if (root->bad())
            rebuild(root);
        node *now = root;
        int res = 0;
        while (true)
        {
            if (now->val > Value)
            {
                if (now->lson)
                {
                    if (now->lson->bad())
                        rebuild(now->lson);
                    now = now->lson;
                    continue;
                }
                return res + 1;
            }
            if (now->val < Value)
            {
                if (now->lson)
                    res += now->lson->sum;
                res += now->num;
                if (now->rson)
                {
                    if (now->rson->bad())
                        rebuild(now->rson);
                    now = now->rson;
                    continue;
                }
                return res + 1;
            }
            if (now->lson)
                res += now->lson->sum;
            return res + 1;
        }
    }
    Type query_val(int Rank)
    {
        if (!root)
            return Type();
        if (root->bad())
            rebuild(root);
        node *now = root;
        while (true)
        {
            if (now->lson)
            {
                if (now->lson->bad())
                    rebuild(now->lson);
                if (now->lson->sum >= Rank)
                {
                    now = now->lson;
                    continue;
                }
                Rank -= now->lson->sum;
            }
            if (Rank <= now->num)
                return now->val;
            Rank -= now->num;
            if (now->rson)
            {
                if (now->rson->bad())
                    rebuild(now->rson);
                if (now->rson->sum >= Rank)
                {
                    now = now->rson;
                    continue;
                }
                Rank -= now->rson->sum;
            }
            return Type();
        }
    }
};
SGT<int> sgt;
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
            sgt.insert(x);
            break;
        case 2:
            sgt.erase(x);
            break;
        case 3:
            cout << sgt.query_rank(x) << endl;
            break;
        case 4:
            cout << sgt.query_val(x) << endl;
            break;
        case 5:
            cout << sgt.query_val(sgt.query_rank(x) - 1) << endl;
            break;
        case 6:
            cout << sgt.query_val(sgt.query_rank(x + 1)) << endl;
            break;
        }
    }
    return 0;
}