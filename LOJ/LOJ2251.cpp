// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const int MOD = 998244353;
const long long INF = LLONG_MAX >> 1;
int n, m, pre[100005];
struct matrix
{
    int v[2][2];
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res = {{{0, 0}, {0, 0}}};
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; res.v[i][j++] %= MOD)
                for (int k = 0; k != 2; ++k)
                    res.v[i][j] += A.v[i][k] * B.v[k][j];
        return res;
    }
    matrix &operator*=(const matrix &val) { return *this = *this * val; }
    friend std::ostream &operator<<(std::ostream &A, const matrix &B)
    {
        A << '[';
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                A << ' ' << B.v[i][j];
        return A << ']';
    }
} ans[100005];
const matrix I = {{{1, 0}, {0, 1}}};
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
struct operation
{
    int opt, l, r, p;
} a[100005];
struct SGT
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    matrix t[1 << 18];
    std::vector<int> cha;
    bool vis[1 << 18];
    void build(int now = 1, int l = 1, int r = n)
    {
        t[now] = I;
        if (l == r)
            return;
        build(lson, l, lmid);
        build(rson, rmid, r);
    }
    void clear()
    {
        while (!cha.empty())
        {
            int now = cha.back();
            vis[now] = false;
            t[now] = I;
            cha.pop_back();
        }
    }
    void mul(int L, int R, matrix V, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            t[now] = t[now] * V;
            if (!vis[now])
            {
                vis[now] = true;
                cha.push_back(now);
            }
            return;
        }
        mul(L, R, V, lson, l, lmid);
        mul(L, R, V, rson, rmid, r);
    }
    matrix query(int pos, int now = 1, int l = 1, int r = n)
    {
        if (l == r)
            return t[now];
        return (pos <= lmid ? query(pos, lson, l, lmid) : query(pos, rson, rmid, r)) * t[now];
    }
} B;
matrix D(matrix x)
{
    x.v[1][0] = x.v[0][1] = x.v[0][1] * 2 % MOD;
    x.v[1][1] = x.v[0][0] = (MOD + 1 - x.v[0][1]) % MOD;
    return x;
}
void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    // std::cout << l << ' ' << r << std::endl;
    std::sort(a + l, a + mid + 1, [&](const operation &A, const operation &B)
              { return A.l < B.l; });
    std::sort(a + mid + 1, a + r + 1, [&](const operation &A, const operation &B)
              { return A.l < B.l; });
    B.clear();
    for (int i = mid + 1, j = l; i <= r; ++i)
    {
        while (j <= mid && a[j].l <= a[i].l)
        {
            if (a[j].opt == 1)
                B.mul(1, a[j].r, D(ans[a[j].p]));
            ++j;
        }
        if (a[i].opt == 2)
            ans[a[i].p] *= B.query(a[i].r);
    }
    B.clear();
    for (int i = r, j = mid; i >= mid + 1; --i)
    {
        while (j >= l && a[i].l < a[j].l)
        {
            if (a[j].opt == 1)
                B.mul(a[j].l, a[j].r, ans[a[j].p]);
            --j;
        }
        if (a[i].opt == 2)
            ans[a[i].p] *= B.query(a[i].r);
    }
    std::sort(a + l, a + mid + 1, [&](const operation &A, const operation &B)
              { return A.r < B.r; });
    std::sort(a + mid + 1, a + r + 1, [&](const operation &A, const operation &B)
              { return A.r < B.r; });
    B.clear();
    for (int i = mid + 1, j = l; i <= r; ++i)
    {
        while (j <= mid && a[j].r < a[i].r)
        {
            if (a[j].opt == 1)
                B.mul(a[j].l, a[j].r, ans[a[j].p]);
            ++j;
        }
        if (a[i].opt == 2 && a[i].l)
            ans[a[i].p] *= B.query(a[i].l);
    }
    // std::cout << ans[3] << std::endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i].opt >> a[i].l >> a[i].r;
        a[i].p = i;
        pre[i] = pre[i - 1] + (a[i].opt == 1);
        if (a[i].opt == 2)
            ans[i] = {{{1, 0}, {0, 0}}}, --a[i].l;
        else
        {
            int inv = power(a[i].r - a[i].l + 1, MOD - 2);
            ans[i] = {{{(MOD + 1 - inv) % MOD, inv}, {inv, (MOD + 1 - inv) % MOD}}};
        }
    }
    B.build();
    cdq(1, m);
    std::sort(a + 1, a + 1 + m, [&](const operation &A, const operation &B)
              { return A.p < B.p; });
    for (int i = 1; i <= m; ++i)
        if (a[i].opt == 2)
            std::cout << ans[i].v[0][a[i].l ? 0 : pre[i] & 1] << std::endl;
    return 0;
}