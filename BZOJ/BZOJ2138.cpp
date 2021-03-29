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
int n, x, y, z, P, A[40005], m, sum[40005];
struct L
{
    int l, r, k;
} Q[40005];
int sqr(int v) { return v * v; }
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
namespace segmenttree_Min
{
    struct node
    {
        int v;
        int lazy;
        node() {}
        node(const int &V) : v(V) {}
        friend node operator+(const node &A, const node &B) { return std::min(A.v, B.v); }
        node &operator+=(const int V)
        {
            v += V;
            lazy += V;
            return *this;
        }
    } tree[1 << 17];
    void push_up(int now) { tree[now] = tree[lson] + tree[rson]; }
    void push_down(int now)
    {
        tree[lson] += tree[now].lazy;
        tree[rson] += tree[now].lazy;
        tree[now].lazy = 0;
    }
    void build(int now = 1, int l = 0, int r = n)
    {
        if (l == r)
            return void(tree[now] = sum[l]);
        build(lson, l, lmid);
        build(rson, rmid, r);
        push_up(now);
    }
    void add(int L, int R, int V, int now = 1, int l = 0, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return void(tree[now] += V);
        push_down(now);
        add(L, R, V, lson, l, lmid);
        add(L, R, V, rson, rmid, r);
        push_up(now);
    }
    int query(int L, int R, int now = 1, int l = 0, int r = n)
    {
        if (R < l || r < L)
            return INF;
        if (L <= l && r <= R)
            return tree[now].v;
        push_down(now);
        return std::min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
    }
};
namespace segmenttree_Max
{
    struct node
    {
        int v;
        int lazy;
        node() {}
        node(const int &V) : v(V) {}
        friend node operator+(const node &A, const node &B) { return std::max(A.v, B.v); }
        node &operator+=(const int V)
        {
            v += V;
            lazy += V;
            return *this;
        }
    } tree[1 << 17];
    void push_up(int now) { tree[now] = tree[lson] + tree[rson]; }
    void push_down(int now)
    {
        tree[lson] += tree[now].lazy;
        tree[rson] += tree[now].lazy;
        tree[now].lazy = 0;
    }
    void build(int now = 1, int l = 0, int r = n)
    {
        if (l == r)
            return void(tree[now] = sum[l]);
        build(lson, l, lmid);
        build(rson, rmid, r);
        push_up(now);
    }
    void add(int L, int R, int V, int now = 1, int l = 0, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return void(tree[now] += V);
        push_down(now);
        add(L, R, V, lson, l, lmid);
        add(L, R, V, rson, rmid, r);
        push_up(now);
    }
    int query(int L, int R, int now = 1, int l = 0, int r = n)
    {
        if (R < l || r < L)
            return -INF;
        if (L <= l && r <= R)
            return tree[now].v;
        push_down(now);
        return std::max(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
    }
};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x >> y >> z >> P;
    for (int i = 1; i <= n; ++i)
        A[i] = (sqr(i - x) + sqr(i - y) + sqr(i - z)) % P;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + A[i];
    std::cin >> m >> Q[1].k >> Q[2].k >> x >> y >> z >> P;
    for (int i = 3; i <= m; ++i)
        Q[i].k = (x * Q[i - 1].k + y * Q[i - 2].k + z) % P;
    for (int i = 1; i <= m; ++i)
        std::cin >> Q[i].l >> Q[i].r;
    segmenttree_Min::build();
    segmenttree_Max::build();
    for (int i = 1; i <= m; ++i)
    {
        // for (int i = 0; i <= n; ++i)
        // {
        //     std::cout << segmenttree_Min::query(i, i) << ' ' << segmenttree_Max::query(i, i) << std::endl;
        // }
        int res = std::min(Q[i].k, segmenttree_Min::query(Q[i].r, n) - segmenttree_Max::query(0, Q[i].l - 1));
        std::cout << res << std::endl;
        segmenttree_Max::add(Q[i].l, n, -res);
        segmenttree_Min::add(Q[i].r, n, -res);
    }
    return 0;
}