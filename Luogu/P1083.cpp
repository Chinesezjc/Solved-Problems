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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
class lazytag
{
public:
    int add;
    lazytag()
    {
        add = 0;
    }
    lazytag(int __Val)
    {
        add = __Val;
    }
    lazytag operator+(const lazytag &__Val) const
    {
        return add + __Val.add;
    }
    lazytag &operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
};
class node
{
public:
    int Min;
    lazytag lazy;
    node()
    {
        Min = 0;
        lazy = 0;
    }
    node(int A)
    {
        Min = A;
        lazy = 0;
    }
    node(int A, lazytag B)
    {
        Min = A;
        lazy = B;
    }
    node operator+(const lazytag &__Val) const
    {
        return {Min + __Val.add, lazy + __Val};
    }
    node operator+(const node &__Val) const
    {
        return min(Min, __Val.Min);
    }
    node &operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
    node &operator+=(const node &__Val)
    {
        return *this = *this + __Val;
    }
};
node tree[1 << 22];
int n, m, a, b, c, T[1000005];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void push_up(int now)
{
    tree[now] = tree[lson] + tree[rson];
}
void push_down(int now)
{
    tree[lson] += tree[now].lazy;
    tree[rson] += tree[now].lazy;
    tree[now].lazy = 0;
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        tree[now] = T[l];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
void add(int L, int R, int v, int now = 1, int l = 1, int r = n)
{
    if (L > r || l > R)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        tree[now] += lazytag(v);
        return;
    }
    push_down(now);
    add(L, R, v, lson, l, lmid);
    add(L, R, v, rson, rmid, r);
    push_up(now);
}
int query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (L > r || l > R)
    {
        return INF;
    }
    if (L <= l && r <= R)
    {
        return tree[now].Min;
    }
    push_down(now);
    return min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> T[i];
    }
    build();
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        add(b, c, -a);
        if (query(1, n) < 0)
        {
            cout << -1 << endl
                 << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}