// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int sum[2][1 << 19], n, m;
std::bitset<200005> s;
bool tag[1 << 19];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    sum[0][now] = sum[0][lson] + sum[0][rson];
    sum[1][now] = sum[1][lson] + sum[1][rson];
}
void pushdown(int now)
{
    if (tag[now])
    {
        std::swap(sum[0][lson], sum[1][lson]);
        std::swap(sum[0][rson], sum[1][rson]);
        tag[lson] ^= true;
        tag[rson] ^= true;
        tag[now] = false;
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        sum[0][now] = !(sum[1][now] = s[n - l]);
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return sum[1][now];
    pushdown(now);
    return query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
}
void modify(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        tag[now] ^= true;
        std::swap(sum[0][now], sum[1][now]);
        return;
    }
    pushdown(now);
    modify(L, R, lson, l, lmid);
    modify(L, R, rson, rmid, r);
    pushup(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s;
    build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y;
        std::cin >> opt >> x >> y;
        if (opt)
            std::cout << query(x, y) << std::endl;
        else
            modify(x, y);
    }
    return 0;
}