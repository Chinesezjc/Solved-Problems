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

    public:
        bool query_son(node *const &Son) const
        {
            return Son == rson;
        }
        void update()
        {
            int oldsiz = siz, oldsum = sum;
            siz = 0;
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
            if ((siz != oldsiz || sum != oldsum) && fa)
                fa->update();
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
    template <class InputIterator>
    node *_rebuild(const InputIterator &_first, const InputIterator &_last)
    {
        if (_first == _last)
            return 0;
        InputIterator mid = (_last - _first) / 2 + _first;
        return new node{mid->first, mid->second, mid->second, _last - _first,
                        _rebuild(_first, mid), _rebuild(mid + 1, _last), 0};
    }
    void clear(node *const &now)
    {
        if (now == root)
        {
            root = 0;
        }
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
            bool son = fa->query_son(now);
            clear(now);
            fa->modify_son(son, _rebuild(tmp.begin(), tmp.end()));
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
                    now = now->lson = new node{Value, 1, 1, 1, 0, 0, now};
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
                    now = now->rson = new node{Value, 1, 1, 1, 0, 0, now};
                    break;
                }
            }
            ++now->num;
            break;
        }
        now->update();
    }
    bool erase(const Type &Value)
    {
        if (!root)
            return false;
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
                else
                    return false;
            }
            --now->num;
            now->update();
            return true;
        }
    }
    int query_rank(const Type &Value)
    {
        if (!root)
            return -INF;
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
                else
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
                else
                    return res + 1;
            }
            if (now->lson)
                res += now->lson->sum;
            return res + 1;
        }
    }
    Type query_val(const int &Rank) const
    {
    }
    Type greater_val(const Type &Value) const
    {
    }
    Type less_val(const Type &Value) const
    {
    }
};
SGT<char> sgt;
signed main()
{
    ios::sync_with_stdio(false);
    string s = "123456789523156489465asafd";
    sgt.build(s.begin(), s.end());
    cout << "NMLs" << endl;
    vector<pair<char, int>> nmsl;
    sgt.visit(nmsl);
    for (auto i : nmsl)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << sgt.query_rank('5') << endl;
    return 0;
}