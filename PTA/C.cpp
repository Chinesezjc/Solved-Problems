//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
using namespace std;
int n, m, to[100005], root[100005];
struct query
{
    int l, r, rk, p, ans;
} b[5005];
struct num
{
    int v, rk, p;
} a[100005];
bool cmpv(const num &A, const num &B)
{
    return A.v < B.v;
}
bool numcmpp(const num &A, const num &B)
{
    return A.p < B.p;
}
bool querycmpp(const query &A, const query &B)
{
    return A.p < B.p;
}
struct node
{
    int l, r, sum, lson, rson;
} c[5000005];
int cnt;
void build(int now)
{
    if (c[now].l == c[now].r)
    {
        return;
    }
    int mid = (c[now].l + c[now].r) >> 1;
    if (!~c[now].lson)
    {
        c[c[now].lson = cnt++] = {c[now].l, mid, 0, -1, -1};
        build(c[now].lson);
    }
    if (!~c[now].rson)
    {
        c[c[now].rson = cnt++] = {mid + 1, c[now].r, 0, -1, -1};
        build(c[now].rson);
    }
}
void update(int now, int v, int lst)
{
    c[now] = c[lst];
    ++c[now].sum;
    if (c[now].l == c[now].r)
    {
        return;
    }
    int mid = (c[now].l + c[now].r) >> 1;
    if (v <= mid)
    {
        c[now].lson = cnt++;
        update(c[now].lson, v, c[lst].lson);
    }
    else
    {
        c[now].rson = cnt++;
        update(c[now].rson, v, c[lst].rson);
    }
}
int ask(int L, int R, int rk)
{
    // cout << L << ' ' << R << endl;
    // cout << c[L] << ' ' << c[R] << endl;
    if (c[L].l == c[L].r)
    {
        return c[L].l;
    }
    if (c[c[R].lson].sum - c[c[L].lson].sum < rk)
    {
        return ask(c[L].rson, c[R].rson, rk - (c[c[R].lson].sum - c[c[L].lson].sum));
    }
    else
    {
        return ask(c[L].lson, c[R].lson, rk);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i].v;
            a[i].p = i;
        }
        sort(a + 1, a + 1 + n, cmpv);
        for (int i = 1; i <= n; ++i)
        {
            a[i].rk = a[i - 1].rk + (a[i - 1].v != a[i].v);
            to[a[i].rk] = a[i].v;
        }
        sort(a + 1, a + 1 + n, numcmpp);
        c[root[0] = cnt++] = {1, n, 0, -1, -1};
        build(root[0]);
        for (int i = 1; i <= n; ++i)
        {
            update(root[i] = cnt++, a[i].rk, root[i - 1]);
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> b[i].l >> b[i].r >> b[i].rk;
            cout << to[ask(root[b[i].l - 1], root[b[i].r], b[i].rk)] << endl;
        }
    }
    return 0;
}