// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
const int pop[] = {0, 1, 1, 2};
int T, n, k, a[25], in[20005], dp1[25][25][4], dp2[20005][25], fact[20005], ifact[20005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
int C(int n, int m) { return 0 <= m && m <= n ? 1ll * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
int dfs2(int, int);
int dfs1(int l, int r, int x)
{
    if (~dp1[l][r][x])
        return dp1[l][r][x];
    int &v = dp1[l][r][x] = 0, len = a[r] - a[l] + 1;
    if (r - l <= 1)
        v = 1;
    else if (r - l == 2)
        v = C(len - pop[x] - 1, a[r] - a[r - 1] - (x & 1));
    else if (x == 0)
        for (int i = l; i <= r; i += 2)
            v = (v + 1ll * dfs1(l, i, 1) * dfs1(i, r, 2) % MOD * C(len - 1, a[i] - a[l])) % MOD;
    else if (x == 1)
        for (int i = r - 1; i >= l; i -= 2)
            v = (v + 1ll * dfs1(l, i, 1) * dfs1(i, r, 3) % MOD * C(len - 2, a[i] - a[l])) % MOD;
    else if (x == 2)
        for (int i = l + 1; i <= r; i += 2)
            v = (v + 1ll * dfs1(l, i, 3) * dfs1(i, r, 2) % MOD * C(len - 2, a[r] - a[i])) % MOD;
    else if (x == 3)
    {
        if ((r - l) & 1)
            if (a[l + 1] != a[l] + 1)
                v = dfs2(a[l] + 1, r);
            else
                v = dfs1(l + 1, r, 1);
        else
            for (int i = l + 1; i < r; i += 2)
                v = (v + 1ll * dfs1(l, i, 3) * dfs1(i, r, 1) % MOD * C(len - 3, a[r] - a[i] - 1)) % MOD;
    }
    // std::cout << a[l] << ' ' << a[r] << ' ' << x << ' ' << v << std::endl;
    return v;
}
int dfs2(int l, int r)
{
    if (~dp2[l][r])
        return dp2[l][r];
    int &v = dp2[l][r] = 0, len = a[r] - l + 1;
    if (r - in[l] == 1)
        v = 1;
    else if (r - in[l] == 2)
        v = C(len - 2, a[r] - a[r - 1] - 1);
    else if ((r - in[l]) & 1)
    {
        if (in[l] == in[l + 1])
            v = dfs2(l + 1, r);
        else
            v = dfs1(in[l + 1], r, 1);
        for (int i = in[l] + 2; i < r; i += 2)
            v = (v + 1ll * dfs2(l, i) * dfs1(i, r, 3) % MOD * C(len - 2, a[r] - a[i] - 1)) % MOD;
    }
    else
        for (int i = in[l] + 1; i < r; i += 2)
            v = (v + 1ll * dfs2(l, i) * dfs1(i, r, 3) % MOD * C(len - 2, a[r] - a[i] - 1)) % MOD;
    // std::cout << l << ' ' << a[r] << ' ' << v << std::endl;
    return v;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (long long i = 1; i <= 20000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[20000] = power(fact[20000], MOD - 2);
    for (long long i = 20000; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= k; ++i)
            std::cin >> a[i];
        for (int i = 1, j = 1; i <= n; ++i)
            if (j <= k && a[j] == i)
                in[i] = j++;
            else
                in[i] = in[i - 1];
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        std::cout << dfs1(1, k, 0) << std::endl;
    }
    return 0;
}