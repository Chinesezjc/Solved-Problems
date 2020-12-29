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
// #include<windows.h>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, cnt;
struct L
{
    int tim, pos;
    double val;
    bool operator<(const L &__Val) const
    {
        return pos == __Val.pos ? tim < __Val.tim : pos > __Val.pos;
    }
} a[200005];
struct lazytag
{
    double Max;
    int cnt;
    lazytag(double MAX = -INF, int CNT = 0) { Max = MAX, cnt = CNT; }
    lazytag operator+(const lazytag &__Val) const
    {
        return {max(Max, __Val.Max), cnt + __Val.cnt};
    }
    lazytag &operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
    bool operator==(const lazytag &__Val) const
    {
        return Max == __Val.Max && cnt == __Val.cnt;
    }
};
struct node
{
    double Min, Minsec;
    lazytag lazy;
    node(double MIN = 0, double MINSEC = INF) { Min = MIN, Minsec = MINSEC; }
    node operator+(const node &__Val) const
    {
        return {min(Min, __Val.Min),
                Min == __Val.Min ? min(Minsec, __Val.Minsec) : min(max(Min, __Val.Min), min(Minsec, __Val.Minsec))};
    }
} tree[1 << 18 | 5];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid mid
#define rmid (mid + 1)
void push_up(int);
void push_down(int, bool);
void DFS(int, bool);
void push_up(int now)
{
    tree[now] = tree[lson] + tree[rson];
}
void push_down(int now, bool up)
{
    double Min = min(tree[lson].Min, tree[rson].Min);
    if (tree[now].lazy == lazytag())
    {
        return;
    }
    tree[lson].lazy.Max = max(tree[lson].lazy.Max, tree[now].lazy.Max);
    tree[rson].lazy.Max = max(tree[rson].lazy.Max, tree[now].lazy.Max);
    if (tree[now].lazy.cnt)
    {
        if (Min == tree[lson].Min)
        {
            tree[lson].lazy.cnt += tree[now].lazy.cnt;
        }
        if (Min == tree[rson].Min)
        {
            tree[rson].lazy.cnt += tree[now].lazy.cnt;
        }
    }
    tree[now].lazy = lazytag();
    DFS(lson, up);
    DFS(rson, up);
}
void DFS(int now, bool up)
{
#ifdef debug
    cout << "DFS " << now << endl;
    for (int i = 1; i <= m * 2 - 1; ++i)
    {
        cout << tree[i].lazy.cnt << ' ';
    }
    cout << endl;
#endif
    if (tree[now].Min >= tree[now].lazy.Max)
    {
        return;
    }
    if (tree[now].Minsec > tree[now].lazy.Max)
    {
        tree[now].Min = tree[now].lazy.Max;
        tree[now].lazy.cnt += up;
        return;
    }
    push_down(now, up);
    push_up(now);
}
void Max(double val, int L, int R, int now = 1, int l = 1, int r = m)
{
    if (R < l || r < L)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        tree[now].lazy.Max = max(tree[now].lazy.Max, val);
        DFS(now, true);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(now, false);
    Max(val, L, R, lson, l, lmid);
    Max(val, L, R, rson, rmid, r);
    push_up(now);
}
int query(int tim, int now = 1, int l = 1, int r = m)
{
    if (l == r)
    {
        return tree[now].lazy.cnt;
    }
    push_down(now, false);
    int mid = (l + r) >> 1;
    if (tim <= mid)
    {
        return query(tim, lson, l, lmid);
    }
    else
    {
        return query(tim, rson, rmid, r);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].pos >> a[i].val;
        a[i].val /= a[i].pos;
        a[i].tim = i;
    }
    cnt = m;
    for (int i = 1; i <= n; ++i)
    {
        if (i == a[1].pos)
        {
            continue;
        }
        a[++cnt] = {1, i, 0};
    }
    sort(a + 1, a + 1 + cnt);
    for (int i = 1; i <= n; ++i)
    {
#ifdef debug
        cout << "                                                             " << i << endl;
#endif
        int right = m;
        while (a[cnt].pos == i)
        {
#ifdef debug
            cout << a[cnt].val << ' ' << a[cnt].tim << ' ' << right << endl;
#endif
            Max(a[cnt].val, a[cnt].tim, right);
            right = a[cnt].tim - 1;
            --cnt;
        }
#ifdef debug
        cout << "-------------------------------------" << endl;
        cout << tree[1].Min << ' ' << tree[1].Minsec << ' ' << tree[1].lazy.cnt << ' ' << tree[1].lazy.Max << endl;
        cout << tree[3].Min << ' ' << tree[3].Minsec << ' ' << tree[3].lazy.cnt << ' ' << tree[3].lazy.Max << endl;
        cout << tree[6].Min << ' ' << tree[6].Minsec << ' ' << tree[6].lazy.cnt << ' ' << tree[6].lazy.Max << endl;
        cout << "-------------------------------------" << endl;
#endif
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << query(i) << endl;
    }
    return 0;
}