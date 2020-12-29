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
const int MAXN = 200000;
#define lson (now << 1)
#define rson (now << 1 | 1)
#define lmid ((l + r) >> 1)
#define rmid (((l + r) >> 1) + 1)
int Max[MAXN << 4 | 5], n, a[MAXN + 5], type, b, c, q;
void push_up(int now)
{
    Max[now] = max(Max[lson], Max[rson]);
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        Max[now] = a[l];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
void change(int x, int v, int now = 1, int l = 1, int r = n)
{
    if (x < l || r < x)
    {
        return;
    }
    if (l == r)
    {
        Max[now] = v;
        return;
    }
    change(x, v, lson, l, lmid);
    change(x, v, rson, rmid, r);
    push_up(now);
}
int query_max(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
    {
        return -INF;
    }
    if (L <= l && r <= R)
    {
        return Max[now];
    }
    return max(query_max(L, R, lson, l, lmid), query_max(L, R, rson, rmid, r));
}
int query_min_ans_bigger_than_v(int x, int v, int now = 1, int l = 1, int r = n)
{
    if (r < x || Max[now] < v)
    {
        return n + 1;
    }
    if (l == r)
    {
        if (v <= Max[now])
        {
            return l;
        }
        return n + 1;
    }
    int ans = query_min_ans_bigger_than_v(x, v, lson, l, lmid);
    if (ans != n + 1)
    {
        return ans;
    }
    ans = query_min_ans_bigger_than_v(x, v, rson, rmid, r);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build();
    for (int i = 1; i <= q; ++i)
    {
        cin >> type >> b >> c;
        if (type == 1)
        {
            change(b, c);
        }
        if (type == 2)
        {
            cout << query_max(b, c) << endl;
        }
        if (type == 3)
        {
            cout << query_min_ans_bigger_than_v(b, c) << endl;
        }
    }
    return 0;
}