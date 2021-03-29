#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls tr[p].lson
#define rs tr[p].rson
const int N = 1e5 + 5;
struct Segment_Tree
{
    int mx, mn, lson, rson;
    int tag;
    void clear(int Tag)
    {
        mx -= Tag;
        mn -= Tag;
        tag += Tag;
    }
} tr[N << 2];
int rt1, rt2, tot;
void pushdown(int p)
{
    if (tr[p].tag)
    {
        tr[ls].clear(tr[p].tag);
        tr[rs].clear(tr[p].tag);
        tr[p].tag = 0;
    }
}
void pushup(int p)
{
    tr[p].mn = min(tr[ls].mn, tr[rs].mn);
    tr[p].mx = max(tr[ls].mx, tr[rs].mx);
}
int query_max(int p, int l, int r, int ql, int qr)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tr[p].mx;
    int res = 0, mid = (l + r) >> 1;
    pushdown(p);
    if (ql <= mid)
        res = max(res, query_max(ls, l, mid, ql, qr));
    if (mid + 1 <= qr)
        res = max(res, query_max(rs, mid + 1, r, ql, qr));
    return res;
}
int query_min(int p, int l, int r, int ql, int qr)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tr[p].mn;
    int res = 1 << 30, mid = (l + r) >> 1;
    pushdown(p);
    if (ql <= mid)
        res = min(res, query_min(ls, l, mid, ql, qr));
    if (mid + 1 <= qr)
        res = min(res, query_min(rs, mid + 1, r, ql, qr));
    return res;
}
void upt(int p, int l, int r, int ql, int qr, int tag)
{
    if (ql <= l && r <= qr)
        return tr[p].clear(tag);
    int mid = (l + r) >> 1;
    pushdown(p);
    if (ql <= mid)
        upt(ls, l, mid, ql, qr, tag);
    if (mid + 1 <= qr)
        upt(rs, mid + 1, r, ql, qr, tag);
    pushup(p);
}
int a[N], sum[N], k[N];
void build(int &p, int l, int r)
{
    if (!p)
        p = ++tot;
    if (l == r)
        return (void)(tr[p].mn = tr[p].mx = sum[l]);
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushup(p);
}
signed main()
{
    int n, m, x, y, z, P;
    cin >> n >> x >> y >> z >> P;
    for (int i = 1; i <= n; ++i)
        a[i] = (1ll * (i - x) * (i - x) % P + 1ll * (i - y) * (i - y) % P + 1ll * (i - z) * (i - z) % P) % P,
        sum[i] = sum[i - 1] + a[i];
    //	for(int i=1;i<=n;++i)
    //	cout<<sum[i]<<" ";cout<<endl;
    build(rt1, 1, n);
    build(rt2, 1, n);
    cin >> m >> k[1] >> k[2] >> x >> y >> z >> P;
    for (int i = 3; i <= m; ++i)
        k[i] = (1ll * x * k[i - 1] % P + 1ll * y * k[i - 2] % P + z) % P;
    int l, r, Ans;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cout << query_min(rt1, 1, n, j, j) << ' ' << query_max(rt2, 1, n, j, j) << std::endl;
        }
        cin >> l >> r;
        int Mn = query_min(rt1, 1, n, r, n), Mx = query_max(rt2, 1, n, 1, l - 1);
        Ans = min(k[i], Mn - Mx);
        upt(rt1, 1, n, r, n, Ans);
        upt(rt2, 1, n, l, n, Ans);
        cout << Ans << endl;
    }
    return 0;
}
