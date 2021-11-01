// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const long long MOD = 998244353;
// #define debug
int n, k, m, a[120], sn, st, sk[10], ans, b[10][10], p, dp1[115][115][230], dp2[115][230];
bool able[115][230];
int inv(int v)
{
    if (v == 0)
        return 0;
    int s = MOD, t = v;
    int m0 = 0, m1 = 1;
    int u, tmp;
    while (t)
    {
        u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    return m0;
}
int del()
{
    long long c = 1;
#ifdef debug
    for (int i = 0; i != p; ++i)
        for (int j = 0; j != p; ++j)
            std::cout << b[i][j] << " \n"[j + 1 == p];
#endif
    for (int i = 0; i != p; ++i)
    {
        if (!b[i][i])
            for (int j = i; ++j != p;)
                if (b[j][i])
                {
                    std::swap(b[i], b[j]);
                    c = MOD - c;
                    break;
                }
        for (int j = i; ++j != p;)
        {
            int v = b[j][i] * (MOD - inv(b[i][i])) % MOD;
            if (v < 0)
                v += MOD;
            for (int l = i; l != p; ++l)
                b[j][l] = (b[j][l] + 1ll * v * b[i][l]) % MOD;
        }
    }
#ifdef debug
    for (int i = 0; i != p; ++i)
        for (int j = 0; j != p; ++j)
            std::cout << b[i][j] << " \n"[j + 1 == p];
#endif
    for (int i = 0; i != p; ++i)
        c = c * b[i][i] % MOD;
    return c;
}
void work()
{
#ifdef debug
    for (int i = 0; i != p; ++i)
        std::cout << sk[i] << ' ';
    std::cout << sn << std::endl;
#endif
    for (int i = 0; i != p; ++i)
        for (int j = 0; j != p; ++j)
            if (i == 0)
                b[i][j] = j == p - 1 ? dp2[n % k][sn - (k / 2) * (p - 1) + n] : dp2[k][sk[j + 1] - (k / 2) * j + n];
            else
            {
                int t = sk[i] - i * (k / 2) + n;
#ifdef debug
                std::cout << t - n << ' ' << k << ' ' << sk[j + 1] - (k / 2) * j << ' ' << dp1[t][k][sk[j + 1] - (k / 2) * j + n] << std::endl;
#endif
                b[i][j] = j == p - 1 ? dp1[t][n % k][sn - (k / 2) * (p - 1) + n] : dp1[t][k][sk[j + 1] - (k / 2) * j + n];
            }
    ans = (ans + del()) % MOD;
}
void dfs(int x)
{
    if (x == p)
        return sn - sk[p - 1] <= std::min(k / 2 - 1, n % k) ? work() : void();
    for (sk[x] = sk[x - 1]; sk[x] <= std::min(sk[x - 1] + k / 2 - 1, sn); ++sk[x])
        dfs(x + 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> m;
    for (int i = 0; i != m; ++i)
    {
        char c;
        std::cin >> c;
        a[i] = (c == '1');
    }
#ifdef debug
    if (k <= 0)
#else
    if (k <= 22)
#endif
    {
        bool bad[1 << k], now = true, lst = false;
        int dp[2][1 << k];
        memset(dp[now], 0, sizeof(dp[now]));
        for (int i = 0; i != 1 << k; ++i)
            bad[i] = __builtin_popcount(i) == k / 2;
        for (int i = 0; i != m; ++i)
            st |= a[i] << (k - 1 - i);
        for (int i = 0; i != 1 << (k - m); ++i)
            if (!bad[i | st])
                dp[now][i | st] = 1;
        for (int i = k; i != n; ++i)
        {
            std::swap(now, lst);
            std::memset(dp[now], 0, sizeof(dp[now]));
            for (int j = 0; j != 1 << k; ++j)
            {
                dp[lst][j] %= MOD;
                for (int l = 0; l != 2; ++l)
                {
                    int nxt = (j << 1 | l) & ((1 << k) - 1);
                    if (!bad[nxt])
                        dp[now][nxt] += dp[lst][j];
                }
            }
        }
        std::cout << std::accumulate(dp[now], dp[now] + (1 << k), 0ll) % MOD << std::endl;
        return 0;
    }
    for (int tim = 0; tim != 2; ++tim)
    {
        for (int i = 0; i != m; ++i)
            st += a[i];
        p = n / k + 1;
        for (sn = 0; sn <= n / k * (k / 2) + n % k; ++sn)
        {
            std::memset(able, 0, sizeof(able));
            std::memset(dp1, 0, sizeof(dp1));
            std::memset(dp2, 0, sizeof(dp2));
            for (int i = 0; i <= k; ++i)
                for (int j = k / 2; j >= -n; --j)
                    able[i][j + n] = true;
            for (int i = 0, v = 0; i != m; v += a[i++])
                able[i][v + n] = false;
#ifdef debug
            std::cout << "?" << std::endl;
#endif
            for (int i = n % k; i++ != n;)
                able[i][sn - (k / 2) * (p - 1) + n] = false;
            for (int i = -1; i >= -n; --i)
                if (able[0][i + n])
                {
                    dp1[i + n][0][i + n] = 1;
                    for (int j = 1; j <= k; ++j)
                        for (int l = n; l >= -n; --l)
                            if (able[j][l + n])
                                dp1[i + n][j][l + n] = (dp1[i + n][j - 1][l + n] +
                                                        (l + n ? dp1[i + n][j - 1][l + n - 1] : 0)) %
                                                       MOD;
                }
            dp2[m][st + n] = 1;
            for (int i = m + 1; i <= k; ++i)
                for (int j = n; j >= -n; --j)
                    if (able[i][j + n])
                        dp2[i][j + n] = (dp2[i - 1][j + n] + (j + n ? dp2[i - 1][j + n - 1] : 0)) % MOD;
#ifdef debug
            for (int j = n; j >= -n; --j)
                for (int i = 0; i <= k; ++i)
                    std::cout << able[i][j + n] << " \n"[i == k];
#endif
            dfs(1);
#ifdef debug
            std::cout << sn << std::endl
                      << ans << std::endl;
#endif
        }
        st = 0;
        for (int i = 0; i != m; ++i)
            a[i] = !a[i];
    }
    std::cout << ans << std::endl;
    return 0;
}