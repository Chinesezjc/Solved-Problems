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
struct BIT
{
    matrix sum[100005];
    bool vis[100005];
    std::vector<int> cha;
    BIT()
    {
        std::fill(sum, sum + 100005, I);
        std::fill(vis, vis + 100005, false);
    }
    void clear()
    {
        while (!cha.empty())
        {
            int now = cha.back();
            cha.pop_back();
            vis[now] = false;
            sum[now] = I;
        }
    }
    void modify(int pos, matrix val)
    {
        while (pos <= n)
        {
            sum[pos] *= val;
            if (!vis[pos])
                vis[pos] = true, cha.push_back(pos);
            pos += pos & -pos;
        }
    }
    matrix query(int pos)
    {
        matrix res = I;
        while (pos)
        {
            res *= sum[pos];
            pos -= pos & -pos;
        }
        return res;
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
    std::sort(a + l, a + mid + 1, [&](const operation &A, const operation &B)
              { return A.l < B.l; });
    std::sort(a + mid + 1, a + r + 1, [&](const operation &A, const operation &B)
              { return A.l < B.l; });
    std::cout << l << ' ' << r << std::endl;
    for (int i = mid + 1, j = l; i <= r; ++i)
    {
        while (j <= mid && a[j].l <= a[i].l)
        {
            if (a[j].opt == 1)
                B.modify(a[j].r, ans[a[j].p]);
            ++j;
        }
        if (a[i].opt == 2)
            ans[a[i].p] *= B.query(a[i].r - 1);
    }
    B.clear();
    for (int i = mid + 1, j = l; i <= r; ++i)
    {
        while (j <= mid && a[j].l <= a[i].l)
        {
            if (a[j].opt == 1)
                B.modify(n - a[j].r + 1, D(ans[a[j].p]));
            ++j;
        }
        if (a[i].opt == 2)
            ans[a[i].p] *= B.query(n - a[i].r + 1);
    }
    B.clear();
    std::cout << ans[3] << std::endl;
    for (int i = r, j = mid; i >= mid + 1; --i)
    {
        while (j >= l && a[j].l > a[i].l)
        {
            if (a[j].opt == 1)
                B.modify(n - a[j].r + 1, ans[a[j].p]);
            --j;
        }
        if (a[i].opt == 2)
            ans[a[i].p] *= B.query(n - a[i].r + 1);
    }
    B.clear();
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
    cdq(1, m);
    std::sort(a + 1, a + 1 + m, [&](const operation &A, const operation &B)
              { return A.p < B.p; });
    for (int i = 1; i <= m; ++i)
        if (a[i].opt == 2)
            std::cout << ans[i].v[0][a[i].l ? 0 : pre[i] & 1 & 0] << std::endl;
    return 0;
}