#include <bits/stdc++.h>
#define ls (w * 2)
#define rs (w * 2 + 1)
#define mid ((l + r) / 2)
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
const ll inf = 1ll << 60;

inline int read()
{
    int s = 0;
    char c = getchar(), lc = '+';
    while (c < '0' || '9' < c)
        lc = c, c = getchar();
    while ('0' <= c && c <= '9')
        s = s * 10 + c - '0', c = getchar();
    return lc == '-' ? -s : s;
}
void write(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x < 10)
        putchar(x + '0');
    else
    {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}
void print(ll x = -1, char c = '\n')
{
    write(x);
    putchar(c);
}
struct node
{
    int tot1;
    ll sum, Max1, Max2, tag;
    node()
    {
        tag = inf;
        sum = tot1 = 0;
        Max1 = Max2 = -inf;
    }
    node(ll x)
    {
        sum = Max1 = x;
        Max2 = -inf;
        tot1 = 1;
        tag = inf;
    }
    void cover(ll x)
    {
        if (Max2 < x && x < Max1)
        {
            sum -= (Max1 - x) * tot1;
            Max1 = x;
        }
        tag = min(tag, x);
    }
} t[N * 3], null;
inline ll max(const ll &x, const ll &y)
{
    return x > y ? x : y;
}
node operator+(const node &a, const node &b)
{
    node ret;
    ret.sum = a.sum + b.sum;
    if (a.Max1 > b.Max1)
    {
        ret.Max1 = a.Max1;
        ret.tot1 = a.tot1;
        ret.Max2 = max(a.Max2, b.Max1);
    }
    if (a.Max1 < b.Max1)
    {
        ret.Max1 = b.Max1;
        ret.tot1 = b.tot1;
        ret.Max2 = max(a.Max1, b.Max2);
    }
    if (a.Max1 == b.Max1)
    {
        ret.Max1 = a.Max1;
        ret.tot1 = a.tot1 + b.tot1;
        ret.Max2 = max(a.Max2, b.Max2);
    }
    return ret;
}
int a[N];
void push_down(const int &w)
{
    if (t[w].tag == inf)
        return;
    t[ls].cover(t[w].tag);
    t[rs].cover(t[w].tag);
    t[w].tag = inf;
}
void build(const int &w, const int &l, const int &r)
{
    if (l == r)
        return void(t[w] = node(a[l]));
    build(ls, l, mid);
    build(rs, mid + 1, r);
    t[w] = t[ls] + t[rs];
}
void change(const int &w, const int &l, const int &r, const int &L, const int &R, const ll &x)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        if (x >= t[w].Max1)
            return;
        if (t[w].Max2 < x && x < t[w].Max1)
            return t[w].cover(x);
    }
    if (l < r)
        push_down(w);
    change(ls, l, mid, L, R, x);
    change(rs, mid + 1, r, L, R, x);
    t[w] = t[ls] + t[rs];
}
node query(const int &w, const int &l, const int &r, const int &L, const int &R)
{
    if (r < L || R < l)
        return null;
    if (L <= l && r <= R)
        return t[w];
    if (l < r)
        push_down(w);
    return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
}

signed main(signed Recall, char *_902_[])
{
    (void)Recall, (void)_902_;
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            int opt = read(), l = read(), r = read();
            if (opt == 0)
                change(1, 1, n, l, r, read());
            if (opt == 1)
                print(query(1, 1, n, l, r).Max1);
            if (opt == 2)
                print(query(1, 1, n, l, r).sum);
        }
    }

    return 0;
}