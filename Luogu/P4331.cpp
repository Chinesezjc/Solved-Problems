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
int n, a[1000005], b[1000005];
template <class Type>
class heap
{
private:
    class node
    {
    public:
        Type val;
        int dis;
        node *lson, *rson;
        node(const Type VAL = Type(), const int DIS = 0, node *const &LSON = 0, node *const &RSON = 0)
            : val(VAL), dis(DIS), lson(LSON), rson(RSON) { update(); }
        friend inline int DIS(node *const &now) { return now ? now->dis : -1; }
        void update()
        {
            if (DIS(lson) < DIS(rson))
                swap(lson, rson);
            dis = DIS(rson) + 1;
        }
        void merge_node(node *tmp)
        {
            if (!tmp)
                return;
            if (tmp->val > this->val)
                swap(*this, *tmp);
            if (this->rson)
                this->rson->merge_node(tmp);
            else
                this->rson = tmp;
            this->update();
            return;
        }
    };
    node *root = 0;
    int siz = 0;

public:
    bool empty() const { return !root; }
    int size() const { return siz; }
    void push(const Type &Value)
    {
        ++siz;
        if (empty())
            root = new node(Value);
        else
            root->merge_node(new node(Value));
    }
    Type top() const { return root->val; }
    void pop()
    {
        --siz;
        node *dead = root;
        root = dead->lson;
        root->merge_node(dead->rson);
        delete dead;
    }
    void merge(heap &x)
    {
        siz += x.siz;
        x.siz = 0;
        root->merge_node(x.root);
        x.root = 0;
    }
};
struct L
{
    int l, r;
    heap<int> h;
    void merge(L &x)
    {
        l = min(l, x.l);
        r = max(r, x.r);
        h.merge(x.h);
        while (h.size() > (r - l + 1) / 2)
            h.pop();
    }
    int middle() const { return h.top(); }
} c[1000005];
int top;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 1; i <= n; ++i)
    {
        L tmp;
        tmp.l = i;
        tmp.r = i + 1;
        tmp.h.push(a[i]);
        while (top && c[top].middle() > tmp.middle())
            tmp.merge(c[top--]);
        c[++top] = move(tmp);
    }
    while (top)
    {
        for (int i = c[top].l; i != c[top].r; ++i)
            b[i] = c[top].middle();
        --top;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += llabs(a[i] - b[i]);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << b[i] + i << ' ';
    cout << endl;
    return 0;
}