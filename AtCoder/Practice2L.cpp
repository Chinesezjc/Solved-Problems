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
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MAXN = 200000;
int n, q, BEGINS[MAXN | 5], type, a, b;
struct LazyTag
{
    bool flip;
};
struct SegmentTree
{
    int zeros, ones, one_zero, zero_one;
    LazyTag lazy;
    SegmentTree operator*(const SegmentTree &__Val) const
    {
        return {zeros + __Val.zeros, ones + __Val.ones,
                one_zero + __Val.one_zero + ones * __Val.zeros,
                zero_one + __Val.zero_one + zeros * __Val.ones};
    }
} t[MAXN << 2 | 5];
void push_up(int now)
{
    t[now] = t[lson] * t[rson];
}
void flip(int now)
{
    swap(t[now].ones, t[now].zeros);
    swap(t[now].one_zero, t[now].zero_one);
}
void push_down(int now)
{
    if (t[now].lazy.flip)
    {
        flip(lson);
        flip(rson);
        t[lson].lazy.flip ^= true;
        t[rson].lazy.flip ^= true;
        t[now].lazy = {false};
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    t[now].lazy = {false};
    if (l == r)
    {
        t[now] = {BEGINS[l] == 0, BEGINS[l] == 1, 0, 0};
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
void replace(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        flip(now);
        t[now].lazy.flip ^= true;
        return;
    }
    push_down(now);
    replace(L, R, lson, l, lmid);
    replace(L, R, rson, rmid, r);
    push_up(now);
}
SegmentTree query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
    {
        return {0, 0, 0, 0, {false}};
    }
    if (L <= l && r <= R)
    {
        return t[now];
    }
    push_down(now);
    SegmentTree res = query(L, R, lson, l, lmid) * query(L, R, rson, rmid, r);
    push_up(now);
    return res;
}
void visit(int now = 1, int l = 1, int r = n)
{
    // cout << now << ' ' << l << ' ' << r << " nmsl" << endl;
    // cout << t[now].ones << ' ' << t[now].zeros << ' ' << t[now].one_zero << ' ' << t[now].zero_one << ' ' << t[now].lazy.flip << endl;
    if (l == r)
    {
        return;
    }
    push_down(now);
    push_up(now);
    // cout << now << ' ' << lson << endl;
    // cout << now << ' ' << rson << endl;
    visit(lson, l, lmid);
    visit(rson, rmid, r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> BEGINS[i];
    }
    build();
    for (int i = 1; i <= q; ++i)
    {
        cin >> type >> a >> b;
        if (type == 1)
        {
            replace(a, b);
        }
        if (type == 2)
        {
            // visit();
            cout << query(a, b).one_zero << endl;
        }
    }
    return 0;
}