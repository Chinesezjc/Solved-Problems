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
using namespace std;
const int INF = 0x3fffffff;
namespace IO
{
    char OUT[20];
    char IN;
    int cnt;
    template <class T>
    T &read(T &__Val)
    {
        __Val = 0;
        IN = getchar();
        while (!isdigit(IN))
        {
            IN = getchar();
        }
        while (isdigit(IN))
        {
            __Val = __Val * 10 + (IN & 15);
            IN = getchar();
        }
        return __Val;
    }
    template <class T>
    void write(const T &__Val)
    {
        T now = __Val;
        while (now)
        {
            OUT[cnt++] = now % 10;
            now /= 10;
        }
        while (cnt)
        {
            putchar(OUT[--cnt] | '0');
        }
    }
    template <class T, class... Args>
    void read(T &__Val, Args &... args)
    {
        read(__Val);
        read(args...);
    }
} // namespace IO
struct change
{
    int pos, tim, val;
    bool operator<(const change &__Val) const
    {
        return pos == __Val.pos ? tim < __Val.tim : pos < __Val.pos;
    }
} a[2000005];
struct query
{
    int pos, tim, p;
    bool operator<(const query &__Val) const
    {
        return pos < __Val.pos;
    }
} c[1000005];
int n, m, b[1000005], cnt, ccnt, ans[1000005];
struct lazytag
{
    int Min, cnt;
    lazytag(const int &MIN = INF, const int &CNT = 0) { Min = MIN, cnt = CNT; }
    inline const bool operator==(const lazytag &__Val) const { return Min == __Val.Min && cnt == __Val.cnt; }
    inline const bool empty() const { return Min == INF && cnt == 0; }
    inline void clear() { Min = INF, cnt = 0; }
};
#ifdef debug
int CNTCNT = 0;
#endif
struct node
{
    int Max, Maxsec;
    lazytag lazy;
    void update(int val, int cnt)
    {
        if (val < Max)
        {
            Max = val;
            if (val < lazy.Min)
            {
                lazy.Min = val;
                lazy.cnt += cnt;
            }
        }
    }
} tree[1 << 21 | 5];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid mid
#define rmid (mid + 1)
#define max(x, y) ((x) < (y) ? (y) : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
inline void push_up(const int &now)
{
    tree[now].Max = max(tree[lson].Max, tree[rson].Max);
    tree[now].Maxsec = tree[lson].Max == tree[rson].Max
                           ? max(tree[lson].Maxsec, tree[rson].Maxsec)
                           : max(min(tree[lson].Max, tree[rson].Max), max(tree[lson].Maxsec, tree[rson].Maxsec));
}
inline void push_down(const int &now)
{
    if (tree[now].lazy.empty())
    {
        return;
    }
    tree[lson].update(tree[now].lazy.Min, tree[now].lazy.cnt);
    tree[rson].update(tree[now].lazy.Min, tree[now].lazy.cnt);
    tree[now].lazy.clear();
}
void build(const int &now = 1, const int &l = 0, const int &r = m)
{
    if (l == r)
    {
        tree[now] = {INF, -INF};
        return;
    }
    const int mid = (l + r) / 2;
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
void Min(const int &val, const int &L, const int &R, const int &now = 1, const int &l = 0, const int &r = m)
{
#ifdef debug
    ++CNTCNT;
#endif
    if (R < l || r < L || tree[now].Max <= val)
    {
        return;
    }
    if (L <= l && r <= R && tree[now].Maxsec < val)
    {
        return tree[now].update(val, 1);
    }
    int mid = (l + r) / 2;
    push_down(now);
    Min(val, L, R, lson, l, lmid);
    Min(val, L, R, rson, rmid, r);
    push_up(now);
}
const int query(const int &tim, const int &now = 1, const int &l = 0, const int &r = m)
{
    if (l == r)
    {
        return tree[now].lazy.cnt;
    }
    push_down(now);
    const int mid = (l + r) / 2;
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
#ifdef debug
    freopen("ex_a4.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    IO::read(n, m);
    for (int i = 1; i <= n; ++i)
    {
        IO::read(b[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        int opt;
        IO::read(opt);
        switch (opt)
        {
        case 1:
            ++cnt;
            IO::read(a[cnt].pos, a[cnt].val);
            a[cnt].tim = cnt;
            break;
        case 2:
            IO::read(c[++ccnt].pos);
            c[ccnt].tim = cnt;
            c[ccnt].p = ccnt;
            break;
        }
    }
    m = cnt;
    build();
    for (int i = 1; i <= n; ++i)
    {
        a[++cnt] = {i, 0, b[i]};
    }
    sort(a + 1, a + 1 + cnt);
    sort(c + 1, c + 1 + ccnt);
#ifdef debug
    cout << __LINE__ << ' ' << clock() << endl;
#endif
    for (int i = n, que = ccnt; i; --i)
    {
        int right = m;
        while (a[cnt].pos == i)
        {
            Min(a[cnt].val, a[cnt].tim, right);
            right = a[cnt].tim - 1;
            --cnt;
        }
        while (c[que].pos == i)
        {
            ans[c[que].p] = query(c[que].tim);
            --que;
        }
    }
#ifdef debug
    cout << __LINE__ << ' ' << clock() << endl;
    cout << CNTCNT << endl;
#endif
    for (int i = 1; i <= ccnt; ++i)
    {
        IO::write(ans[i]);
        putchar('\n');
    }
#ifdef debug
    cout << __LINE__ << ' ' << clock() << endl;
#endif
    return 0;
}