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
const int MOD = 1000000007;
inline int F(int now)
{
    if (now < 0)
    {
        if (now >= -MOD)
        {
            now += MOD;
        }
        else
        {
            now = now % MOD + MOD;
        }
    }
    else
    {
        if (MOD < now && now < MOD << 1)
        {
            now -= MOD;
        }
        else
        {
            now %= MOD;
        }
    }
    return now;
}
struct mint
{
    int v;
    inline mint()
    {
        v = 0;
    }
    inline mint(int now)
    {
        v = F(now);
    }
    inline mint operator+(const mint &__Val) const
    {
        return v + __Val.v;
    }
    inline mint operator*(const mint &__Val) const
    {
        return v * __Val.v;
    }
    inline mint operator+=(const mint &__Val)
    {
        return *this = *this + __Val;
    }
    inline friend ostream &operator<<(ostream &ost, const mint __Val)
    {
        return ost << __Val.v;
    }
    inline friend bool operator==(const mint &A, const mint &B)
    {
        return A.v == B.v;
    }
};
inline mint operator+(const int &A, const mint &B)
{
    return B + A;
}
inline mint operator*(const int &A, const mint &B)
{
    return B * A;
}
int n, m, a[200005], b[200005];
mint f[200005], g[200005], d[200005];
inline mint sqr(mint now)
{
    return now * now;
}
struct lazytag
{
    mint first_term, common_difference;
    mint first_term2, first_term_of_common_difference2, common_difference_of_common_difference2;
    inline friend lazytag operator+(const lazytag &A, const lazytag &B)
    {
        return {A.first_term + B.first_term,
                A.common_difference + B.common_difference,
                A.first_term2 + B.first_term2,
                A.first_term_of_common_difference2 + B.first_term_of_common_difference2,
                A.common_difference_of_common_difference2 + B.common_difference_of_common_difference2};
    }
    inline lazytag operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
    inline friend bool operator==(const lazytag &A, const lazytag &B)
    {
        return A.first_term == B.first_term &&
               A.common_difference == B.common_difference &&
               A.first_term2 == B.first_term2 &&
               A.first_term_of_common_difference2 == B.first_term_of_common_difference2 &&
               A.common_difference_of_common_difference2 == B.common_difference_of_common_difference2;
    }
};
struct node
{
    mint suma_i, sumia_i, suma_i2, sumb_i;
    int len;
    lazytag lazy;
    inline friend node operator+(const node &A, const node &B)
    {
        return {A.suma_i + B.suma_i,
                A.sumia_i + B.sumia_i + B.suma_i * A.len,
                A.suma_i2 + B.suma_i2,
                A.sumb_i + B.sumb_i,
                A.len + B.len};
    }
    inline friend node operator+(const node &A, const lazytag &B)
    {
        return {
            A.suma_i +
                B.first_term * A.len +
                B.common_difference * f[A.len - 1],
            A.sumia_i +
                f[A.len - 1] * B.first_term +
                g[A.len - 1] * B.common_difference,
            A.suma_i2 +
                2 * A.suma_i * B.first_term +
                A.len * sqr(B.first_term) +
                g[A.len - 1] * sqr(B.common_difference) +
                2 * A.sumia_i * B.common_difference +
                2 * f[A.len - 1] * B.first_term * B.common_difference,
            A.sumb_i +
                A.len * B.first_term2 +
                f[A.len - 1] * B.first_term_of_common_difference2 +
                d[max(A.len - 2, 0ll)] * B.common_difference_of_common_difference2,
            A.len,
            A.lazy +
                B,
        };
    }
    inline node operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
} tree[1 << 20];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
inline void push_down(int now)
{
    if (tree[now].lazy == lazytag())
    {
        return;
    }
    tree[lson] += tree[now].lazy;
    tree[now].lazy.first_term += tree[now].lazy.common_difference * tree[lson].len;
    tree[now].lazy.first_term2 += tree[now].lazy.first_term_of_common_difference2 * tree[lson].len +
                                  tree[now].lazy.common_difference_of_common_difference2 * f[tree[lson].len - 1];
    tree[now].lazy.first_term_of_common_difference2 +=
        tree[now].lazy.common_difference_of_common_difference2 * tree[lson].len;
    tree[rson] += tree[now].lazy;
    tree[now].lazy = lazytag();
}
inline void push_up(int now)
{
    tree[now] = tree[lson] + tree[rson];
}
inline void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        tree[now] = {a[l], 0, a[l] * a[l], b[l], 1, lazytag()};
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
inline void add(int L, int R, mint s, mint k, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        s = s + (l - L) * k;
        tree[now] += {s, k, sqr(s), 2 * s * k + sqr(k), 2 * sqr(k)};
        return;
    }
    push_down(now);
    add(L, R, s, k, lson, l, lmid);
    add(L, R, s, k, rson, rmid, r);
    push_up(now);
}
inline mint query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return tree[now].suma_i2 + tree[now].sumb_i;
    }
    push_down(now);
    return query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
}
inline void read(int &x)
{
    x = 0;
    bool flag = false;
    char c = getchar();
    while ('0' > c || c > '9')
    {
        if (c == '-')
        {
            flag = true;
        }
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c & 15);
        c = getchar();
    }
    flag && (x = -x);
}
char tmp[10];
int cnt = 0;
inline void write(int x)
{
    if (!x)
    {
        putchar('0');
        return;
    }
    while (x)
    {
        tmp[cnt++] = x % 10;
        x /= 10;
    }
    while (cnt)
    {
        putchar(tmp[--cnt] | '0');
    }
}
signed main()
{
    read(n);
    read(m);
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + i;
        g[i] = g[i - 1] + i * i;
        d[i] = d[i - 1] + f[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        read(b[i]);
    }
    build();
    for (int i = 1; i <= m; ++i)
    {
        int opt, l, r;
        read(opt);
        read(l);
        read(r);
        if (opt)
        {
            write(query(l, r).v);
            putchar('\n');
        }
        else
        {
            int s, k;
            read(s);
            read(k);
            add(l, r, s, k);
        }
    }
    return 0;
}