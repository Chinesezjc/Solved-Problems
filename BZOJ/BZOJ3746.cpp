// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define c(a, b) v[a][(b) - (a) + 3]
const int MOD = 1000000007;
int n, k, p, f[1000005], g[1000005], s;
bool v[1000005][7];
int calc2()
{
    if (n == 1 || (n == 2 && !k))
        return 1;
    int res = 0;
    for (int i = 1; i <= 2; ++i)
    {
        int now = n - i;
        bool flag = v[n][-i + 3];
        while (now > 2)
            flag &= v[now][-2 + 3], now -= 2;
        if (now == 1)
            flag &= v[now][+1 + 3], ++now;
        else
            flag &= v[now][-1 + 3], --now;
        while (now < n - 2)
            flag &= v[now][+2 + 3], now += 2;
        flag &= v[now][n - now + 3];
        res += flag;
    }
    return res;
}
void dfs1(int now, int can)
{
    if (!can && now == s + 1)
        return void(++f[s]);
    for (int i = -3; i <= +3; ++i)
        if (v[now][i + 3] && now + i - s >= 0 && can >> (now + i - s) & 1)
            dfs1(now + i, can ^ 1 << (now + i - s));
}
void dfs2(int now, int can)
{
    if (!can && now == s)
        return void(++g[s]);
    for (int i = -3; i <= +3; ++i)
        if (v[now][i + 3] && now + i - s >= 0 && can >> (now + i - s) & 1)
            dfs2(now + i, can ^ 1 << (now + i - s));
}
int dfs(int now, int can)
{
    if (!can && n - now <= 3 && v[now][n - now + 3])
        return 1;
    int res = 0;
    for (int i = -3; i <= +3; ++i)
        if (v[now][i + 3] && now + i - s >= 0 && can >> (now + i - 1) & 1)
            res += dfs(now + i, can ^ 1 << (now + i - 1));
    return res;
}
int calc3()
{
    if (n <= 8)
        return dfs(n, (1 << n >> 1) - 1);
    for (s = n - 1; s > std::max(0, n - 10); --s)
    {
        dfs1(s + 0, ((1 << (n - s + 1)) - 1) ^ 1);
        dfs2(s + 1, ((1 << (n - s + 1)) - 1) ^ 2);
    }
    for (; s; --s)
    {
        static long long res;
        res = 0;
        if (c(s, s + 2))
            res += g[s + 1];
        if (c(s, s + 3) && c(s + 2, s + 1))
            res += g[s + 2];
        if (c(s, s + 3) && c(s + 3, s + 2) && c(s + 2, s + 5) && c(s + 4, s + 1))
            res += g[s + 4];
        if (c(s, s + 3) && c(s + 3, s + 6) && c(s + 5, s + 2) && c(s + 2, s + 4) && c(s + 4, s + 1))
            res += g[s + 5];
        f[s] = res % MOD;
        res = 0;
        if (c(s + 2, s))
            res += f[s + 1];
        if (c(s + 1, s + 2) && c(s + 3, s))
            res += f[s + 2];
        if (c(s + 1, s + 4) && c(s + 5, s + 2) && c(s + 2, s + 3) && c(s + 3, s))
            res += f[s + 4];
        if (c(s + 1, s + 4) && c(s + 4, s + 2) && c(s + 2, s + 5) && c(s + 6, s + 3) && c(s + 3, s))
            res += f[s + 5];
        g[s] = res % MOD;
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << f[i] << ' ' << g[i] << std::endl;
    long long res = 0;
    if (c(2, 1))
        res += f[1];
    if (c(1, 2) && c(3, 1))
        res += f[2];
    if (c(1, 4) && c(5, 2) && c(2, 3) && c(3, 1))
        res += f[4];
    if (c(1, 4) && c(4, 2) && c(2, 5) && c(6, 3) && c(3, 1))
        res += f[5];
    if (c(1, 2) && c(2, 3) && c(4, 1))
        res += f[3];
    if (c(1, 2) && c(2, 5) && c(6, 3) && c(3, 4) && c(4, 1))
        res += f[5];
    if (c(1, 2) && c(2, 5) && c(5, 3) && c(3, 6) && c(7, 4) && c(4, 1))
        res += f[6];
    if (c(1, 3) && c(3, 2) && c(2, 5) && c(4, 1))
        res += g[4];
    if (c(1, 3) && c(3, 6) && c(5, 2) && c(2, 4) && c(4, 1))
        res += g[5];
    return res % MOD;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> p;
    memset(v, true, sizeof(v));
    for (int i = 1, a, b; i <= k; ++i)
    {
        std::cin >> a >> b;
        if (std::abs(a - b) <= 3)
            v[a][b - a + 3] = false;
    }
    switch (p)
    {
    case 0:
        std::cout << (n <= 1) << std::endl;
        break;
    case 1:
        std::cout << (n <= 2 && !k) << std::endl;
        break;
    case 2:
        std::cout << calc2() << std::endl;
        break;
    case 3:
        std::cout << calc3() << std::endl;
        break;
    }
    return 0;
}