// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#define DFS
const int MOD = 1000000007;
int T, n, s, a, m;
long long add[1 << 10], mul[1 << 10], ans;
inline long long qmod(long long x) { return x >= MOD ? x - MOD : x; }
inline void qmin(long long &a, long long b) { a > b ? a = b : 0; }
inline void dfs(register int lst, register int ca, register int cm, register long long now)
{
    if (lst != 0)
    {
        if (cm)
            for (int i = ca; i; i = (i - 1) & ca)
                dfs(0, ca ^ i, cm, qmod(now + add[i]));
        else
            qmin(ans, qmod(now + add[ca]));
    }
    if (lst != 1)
    {
        if (ca)
            for (int i = cm; i; i = (i - 1) & cm)
                dfs(1, ca, cm ^ i, now * mul[i] % MOD);
        else
            qmin(ans, now * mul[cm] % MOD);
    }
}
signed main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    mul[0] = 1;
    while (T--)
    {
        std::cin >> n >> s;
        ans = MOD;
        a = m = 0;
        for (int i = 1; i <= n; ++i)
        {
            static char c;
            static int x;
            std::cin >> c >> x;
            if (c == '+')
            {
                for (int j = 1 << a; j != 2 << a; ++j)
                    add[j] = (add[j ^ 1 << a] + x) % MOD;
                ++a;
            }
            else
            {
                for (int j = 1 << m; j != 2 << m; ++j)
                    mul[j] = 1ll * mul[j ^ 1 << m] * x % MOD;
                ++m;
            }
        }
        dfs(-1, (1 << a) - 1, (1 << m) - 1, s);
        std::cout << ans << std::endl;
    }
    std::cout << clock() << std::endl;
    return 0;
}