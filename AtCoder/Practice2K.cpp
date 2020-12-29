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
const int MAXN = 500000;
const int MOD = 998244353;
int n, q, a[MAXN | 5], b, c, d, e, type;
#define lson (now << 1)
#define rson (now << 1 | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
struct LazyTag
{
    int mul, add;
};
struct SegmentTree
{
    int sum;
    LazyTag lazy;
} t[MAXN << 2 | 5];
void push_up(int now)
{
    t[now].sum = (t[lson].sum + t[rson].sum) % MOD;
}
void push_down(int now, int l, int r)
{
    (t[lson].lazy.mul *= t[now].lazy.mul) %= MOD;
    (t[lson].lazy.add *= t[now].lazy.mul) %= MOD;
    (t[lson].lazy.add += t[now].lazy.add) %= MOD;
    (t[rson].lazy.mul *= t[now].lazy.mul) %= MOD;
    (t[rson].lazy.add *= t[now].lazy.mul) %= MOD;
    (t[rson].lazy.add += t[now].lazy.add) %= MOD;
    (((t[lson].sum *= t[now].lazy.mul) %= MOD) += t[now].lazy.add * (lmid - l + 1)) %= MOD;
    (((t[rson].sum *= t[now].lazy.mul) %= MOD) += t[now].lazy.add * (r - rmid + 1)) %= MOD;
    t[now].lazy = {1, 0};
}
void build(int now = 1, int l = 1, int r = n)
{
    t[now].lazy = {1, 0};
    if (l == r)
    {
        t[now].sum = a[l];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
void mul(int L, int R, int v, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        (t[now].lazy.mul *= v) %= MOD;
        (t[now].lazy.add *= v) %= MOD;
        (t[now].sum *= v) %= MOD;
        return;
    }
    push_down(now, l, r);
    mul(L, R, v, lson, l, lmid);
    mul(L, R, v, rson, rmid, r);
    push_up(now);
}
void add(int L, int R, int v, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        (t[now].lazy.add += v) %= MOD;
        (t[now].sum += v * (r - l + 1)) %= MOD;
        return;
    }
    push_down(now, l, r);
    add(L, R, v, lson, l, lmid);
    add(L, R, v, rson, rmid, r);
    push_up(now);
}
int query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return t[now].sum;
    }
    push_down(now, l, r);
    int res = (query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r)) % MOD;
    push_up(now);
    return res;
}
void visit(int now = 1, int l = 1, int r = n)
{
    cout << now << ' ' << l << ' ' << r << ' ' << t[now].sum << " {" << t[now].lazy.mul << ',' << t[now].lazy.add << "}" << endl;
    if (l == r)
    {
        return;
    }
    cout << now << ' ' << lson << endl;
    cout << now << ' ' << rson << endl;
    visit(lson, l, lmid);
    visit(rson, rmid, r);
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
        cin >> type;
        if (type == 0)
        {
            cin >> b >> c >> d >> e;
            ++b;
            mul(b, c, d);
            add(b, c, e);
            // visit();
        }
        if (type == 1)
        {
            cin >> b >> c;
            ++b;
            cout << query(b, c) << endl;
        }
    }
    return 0;
}