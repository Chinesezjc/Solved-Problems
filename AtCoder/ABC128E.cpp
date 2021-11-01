// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, t[200005], val[1 << 19];
struct query
{
    int l, r, x;
} a[200005];
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void min(int L, int R, int v, int now = 1, int l = 0, int r = q)
{
    if (R <= l || r <= L)
        return;
    if (L <= l && r <= R)
    {
        val[now] = std::min(val[now], v);
        return;
    }
    min(L, R, v, lson, l, mid);
    min(L, R, v, rson, mid, r);
}
void print(int v, int now = 1, int l = 0, int r = q)
{
    v = std::min(v, val[now]);
    if (r - l == 1)
    {
        std::cout << (v == INT_MAX ? -1 : v) << std::endl;
        return;
    }
    print(v, lson, l, mid);
    print(v, rson, mid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i].l >> a[i].r >> a[i].x;
        a[i].l -= a[i].x;
        a[i].r -= a[i].x;
    }
    for (int i = 0; i != q; ++i)
        std::cin >> t[i];
    std::fill(val, val + (1 << 19), INT_MAX);
    for (int i = 1; i <= n; ++i)
        min(std::lower_bound(t, t + q, a[i].l) - t, std::lower_bound(t, t + q, a[i].r) - t, a[i].x);
    print(INT_MAX);
    return 0;
}