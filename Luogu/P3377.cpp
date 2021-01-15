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
class node
{
public:
    int v, p;
    friend bool operator<(const node &A, const node &B)
    {
        return A.v == B.v ? A.p < B.p : A.v < B.v;
    }
};
template <class Type>
class heap
{
private:
    class node
    {
    private:
        int dis;
        void swap_son() { swap(lson, rson); }
        bool bad() const { return lson_dis() < rson_dis(); }
        int lson_dis() const { return lson ? lson->dis : -1; }
        int rson_dis() const { return rson ? rson->dis : -1; }

    public:
        node(Type VAL = Type(), node *LSON = 0, node *RSON = 0) : dis(0), val(VAL), lson(LSON), rson(RSON) {}
        Type val;
        node *lson, *rson;
        void update()
        {
            if (bad())
                swap_son();
            dis = rson_dis() + 1;
        }
        friend node *merge_node(node *A, node *B)
        {
            if (B->val < A->val)
                swap(*A, *B);
            if (A->rson)
                merge_node(A->rson, B);
            else
                A->rson = B;
            A->update();
            return A;
        }
    };
    node *root;

public:
    bool empty() const { return root == 0; }
    Type top() const { return empty() ? Type() : root->val; }
    void push(const Type &x)
    {
        if (empty())
            root = new node(x);
        else
            merge_node(root, new node(x));
    }
    void pop()
    {
        if (empty())
            return;
        node *tmp = root;
        root->update();
        if (root->rson)
            root = merge_node(root->lson, root->rson);
        else if (root->lson)
            root = root->lson;
        else
            root = 0;
        delete tmp;
    }
    void merge(heap &x)
    {
        if (x.empty() || &x == this)
            return;
        if (empty())
        {
            root = x.root;
            return;
        }
        root = merge_node(root, x.root);
        x.root = 0;
    }
};
heap<node> h[100005];
int n, m, fa[100005];
bool del[100005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int tmp;
        fa[i] = i;
        cin >> tmp;
        h[i].push({tmp, i});
    }
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> x >> y;
            if (!del[x] && !del[y] && find(x) != find(y))
            {
                h[find(x)].merge(h[find(y)]);
                fa[find(y)] = find(x);
            }
            break;
        case 2:
            cin >> x;
            if (del[x])
                cout << -1 << endl;
            else
            {
                const node tmp = h[find(x)].top();
                h[find(x)].pop();
                cout << tmp.v << endl;
                del[tmp.p] = true;
            }
            break;
        }
    }
    return 0;
}