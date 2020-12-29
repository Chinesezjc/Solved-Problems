#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ls (w * 2)
#define rs (w * 2 + 1)
#define mid ((l + r) / 2)
#define debug 0
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e9 + 7;
int cntcnt = 0;

const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
inline char myGetchar()
{
#ifdef debug
    return getchar();
#endif
    static char buf[IN_BUF], *ps = buf, *pt = buf;
    if (ps == pt)
    {
        ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
    }
    return ps == pt ? EOF : *ps++;
}
inline void myPutchar(char x)
{
#ifdef debug
    return (void)putchar(x);
#endif
    static char pbuf[OUT_BUF], *pp = pbuf;
    struct _flusher
    {
        ~_flusher()
        {
            fwrite(pbuf, 1, pp - pbuf, stdout);
        }
    };
    static _flusher outputFlusher;
    if (pp == pbuf + OUT_BUF)
    {
        fwrite(pbuf, 1, OUT_BUF, stdout);
        pp = pbuf;
    }
    *pp++ = x;
}
inline int read()
{
    int s = 0;
    char c = myGetchar(), lc = '+';
    while (c < '0' || '9' < c)
        lc = c, c = myGetchar();
    while ('0' <= c && c <= '9')
        s = s * 10 + c - '0', c = myGetchar();
    return lc == '-' ? -s : s;
}
void write(int x)
{
    if (x < 0)
    {
        myPutchar('-');
        x = -x;
    }
    if (x < 10)
        myPutchar(x + '0');
    else
    {
        write(x / 10);
        myPutchar(x % 10 + '0');
    }
}
void print(int x = -1, char c = '\n')
{
    write(x);
    myPutchar(c);
}
inline int max(const int &a, const int &b)
{
    return a > b ? a : b;
}
struct piir
{
    int t, v;
};
template <typename T>
struct Vector
{
    struct edge
    {
        int nxt;
        T v;
    } a[N * 3];
    int head[N], cnt, tail[N];
    void push_back(int u, T w)
    {
        a[++cnt].v = w;
        a[tail[u]].nxt = cnt;
        tail[u] = cnt;
        if (head[u] == 0)
            head[u] = cnt;
    }
};
Vector<piir> c;
Vector<int> q;
int ans[N];
struct LazyTag
{
    int Min, tot;
    LazyTag() : Min(inf), tot(0) {}
    inline bool operator==(const LazyTag &a) const
    {
        return Min == a.Min && tot == a.tot;
    }
} null;
struct node
{
    int Max1, Max2, val;
    LazyTag tag;
    node() : Max1(inf), Max2(-inf), val(0) {}
    inline void update(int x, int y)
    {
        if (x >= Max1)
            return;
        Max1 = x;
        val += y;
        if (x < tag.Min)
        {
            tag.Min = x;
            tag.tot += y;
        }
    }
} t[N * 4];
inline void push_up(node &c, const node &a, const node &b)
{
    c.Max1 = max(a.Max1, b.Max1);
    c.Max2 = a.Max1 == b.Max1
                 ? max(a.Max2, b.Max2)
                 : max(min(a.Max1, b.Max1), max(a.Max2, b.Max2));
}
inline void push_down(int w)
{
    if (t[w].tag == null)
        return;
    t[ls].update(t[w].tag.Min, t[w].tag.tot);
    t[rs].update(t[w].tag.Min, t[w].tag.tot);
    t[w].tag = null;
}
void change(int w, int l, int r, const int &L, const int &R, const int &x)
{
    ++cntcnt;
    if (r < L || R < l || x >= t[w].Max1)
        return;
    if (L <= l && r <= R && t[w].Max2 < x)
        return t[w].update(x, 1);
    push_down(w);
    change(ls, l, mid, L, R, x);
    change(rs, mid + 1, r, L, R, x);
    push_up(t[w], t[ls], t[rs]);
}
inline int query(int w, int l, int r, int x)
{
    while (l < r)
    {
        push_down(w);
        if (x <= mid)
            w = ls, r = mid;
        else
            w = rs, l = mid + 1;
    }
    return t[w].val;
}

signed main(signed Recall, char *_902_[])
{
    freopen("ex_a4.in", "r", stdin);
    freopen("data.out", "w", stdout);
    (void)Recall, (void)_902_;
    memset(ans, 0, sizeof(ans));
    int n = read(), Q = read();
    for (int i = 1; i <= n; i++)
        c.push_back(i, (piir){1, read()});
    for (int i = 1; i <= Q; i++)
    {
        int opt = read(), x = read();
        if (opt == 1)
            c.push_back(x, (piir){i, read()});
        else
            q.push_back(x, i);
    }
    for (int i = 1; i <= n; i++)
        c.push_back(i, (piir){Q + 1, 0});
    for (int i = n; i >= 1; i--)
    {
        for (int j = c.head[i]; c.a[j].nxt; j = c.a[j].nxt)
            change(1, 1, Q, c.a[j].v.t, c.a[c.a[j].nxt].v.t - 1, c.a[j].v.v);
        for (int j = q.head[i]; j; j = q.a[j].nxt)
            ans[q.a[j].v] = query(1, 1, Q, q.a[j].v);
    }
    for (int i = 1; i <= Q; i++)
        if (ans[i])
            print(ans[i]);
    print(cntcnt);
    return 0;
}